/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:09:33 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/30 15:40:26 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_born(t_sstack *stk, int value, int is_ascending)
{
	int	i_max;
	int	i_min;

	i_max = get_born_max(stk);
	i_min = get_born_min(stk);
	if (value > stk->data[i_max])
	{
		if (i_max == 0)
			return (0 + is_ascending);
		return (i_max + is_ascending);
	}
	else if (value < stk->data[i_min])
	{
		if (!is_ascending && i_min == (int)s_len_stk(stk) - 1)
			return (0);
		return (i_min + 1 - is_ascending);
	}
	return (-1);
}

int	take_pos(t_sstack *stk, int value, int is_ascending)
{
	int	index;
	int	current_value;
	int	prev_value;
	int	born;

	born = test_born(stk, value, is_ascending);
	if (born != -1)
		return (born);
	if ((!is_ascending && stk->data[0] < value && value < stk->data[stk->base])
		|| (is_ascending && stk->data[0] > value
			&& value > stk->data[stk->base]))
		return (0);
	index = 0;
	while (index + 1 <= stk->base)
	{
		current_value = stk->data[index];
		prev_value = stk->data[index + 1];
		if ((!is_ascending && current_value > value && value > prev_value)
			|| (is_ascending && current_value < value && value < prev_value))
			return (index + 1);
		index++;
	}
	return (index);
}
