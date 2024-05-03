/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:09:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 11:45:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_medians	*take_pivot(t_medians *medians, int const *arr, int len,
		int k)
{
	int	*arr_cpy;
	int	i;

	arr_cpy = (int *)ft_calloc(len, sizeof(int));
	if (!arr_cpy)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		arr_cpy[i] = arr[i];
	}
	medians->higt_median = find_kmedian(arr_cpy, len, (2 * len) / k);
	medians->low_median = find_kmedian(arr_cpy, len, (1 * len) / k);
	free(arr_cpy);
	return (medians);
}

static void	apply_median(t_sstack *stk_a, t_sstack *stk_b, t_medians *medians)
{
	int	tmp;

	tmp = stk_a->data[0];
	if (tmp <= medians->higt_median)
	{
		push(stk_a, stk_b, 'b', 0);
		if (tmp >= medians->low_median)
			rotate(stk_a, stk_b, 'b', 0);
	}
	else
		rotate(stk_a, stk_b, 'a', 0);
}

void	split_sort(t_sstack *stk_a, t_sstack *stk_b, int split_k)
{
	int			i;
	int			fix_len_a;
	int			len_a;
	t_medians	medians;

	fix_len_a = s_len_stk(stk_a);
	len_a = fix_len_a;
	if (len_a <= 3)
	{
		turkish_sort(stk_a, stk_b);
		return ;
	}
	medians = *take_pivot(&medians, stk_a->data, fix_len_a, split_k);
	i = -1;
	while (++i < fix_len_a && len_a > 3)
	{
		len_a = (s_len_stk(stk_a));
		apply_median(stk_a, stk_b, &medians);
	}
	if (len_a <= 100)
		split_k = 3;
	split_sort(stk_a, stk_b, split_k);
}
