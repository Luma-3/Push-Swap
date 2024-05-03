/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medians.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:10:37 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/29 11:24:20 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_kmedian(int *arr, int size, int k);

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
		}
	}
}

static int	recursion_call(int *arr, int iter, int nb_groups, int size)
{
	int	k;
	int	tmp_size;

	if (iter == nb_groups - 1)
	{
		tmp_size = size % 5;
		k = tmp_size / 2;
	}
	else
	{
		tmp_size = 5;
		k = 2;
	}
	return (find_kmedian(arr + iter * 5, tmp_size, k));
}

static int	partition_arr(int *arr, int size, int pivot, int k)
{
	int	p_pivot;
	int	i;

	i = -1;
	p_pivot = 0;
	while (++i < size)
	{
		if (arr[i] < pivot)
		{
			ft_swap(&arr[i], &arr[p_pivot]);
			p_pivot++;
		}
	}
	if (k < p_pivot)
		return (find_kmedian(arr, p_pivot, k));
	else if (k > p_pivot)
		return (find_kmedian(arr + p_pivot, size - p_pivot, k - p_pivot -1));
	return (pivot);
}

int	find_kmedian(int *arr, int size, int k)
{
	int	nb_groups;
	int	*medianes;
	int	i;
	int	pivot;

	if (size <= 5)
	{
		sort(arr, size);
		return (arr[k]);
	}
	nb_groups = (size + 4) / 5;
	medianes = (int *)ft_calloc(nb_groups, sizeof(int));
	i = -1;
	while (++i < nb_groups)
		medianes[i] = recursion_call(arr, i, nb_groups, size);
	pivot = find_kmedian(medianes, nb_groups, nb_groups / 2);
	free(medianes);
	return (partition_arr(arr, size, pivot, k));
}
