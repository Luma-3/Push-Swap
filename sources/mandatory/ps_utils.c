/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:20:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 11:45:46 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_born_max(t_sstack *stk)
{
	int		i;
	int		born_i;
	int		max;

	max = INT_MIN;
	i = 0;
	born_i = 0;
	while (i <= stk->base)
	{
		if (max < stk->data[i])
		{
			max = stk->data[i];
			born_i = i;
		}
		i++;
	}
	return (born_i);
}

int	get_born_min(t_sstack *stk)
{
	int		i;
	int		born_i;
	int		max;

	max = INT_MAX;
	i = 0;
	born_i = 0;
	while (i <= stk->base)
	{
		if (max > stk->data[i])
		{
			max = stk->data[i];
			born_i = i;
		}
		i++;
	}
	return (born_i);
}

int	take_iter(t_sstack *stk, int pos, int *is_rev)
{
	int	len;

	len = s_len_stk(stk);
	if (pos <= len / 2)
		return (*is_rev = 0, pos);
	else
		return (*is_rev = 1, len - pos);
}

int	rotate_or_rrotate(t_sstack *stk_a, t_sstack *stk_b, int is_rev, char name)
{
	if (is_rev == 1)
		rev_rotate(stk_a, stk_b, name, 0);
	else
		rotate(stk_a, stk_b, name, 0);
	return (1);
}

void	instruction(t_sstack *stk_a, t_sstack *stk_b, int pos_a, int pos_b)
{
	int	a_roll;
	int	a_is_rev;
	int	b_roll;
	int	b_is_rev;

	a_roll = take_iter(stk_a, pos_a, &a_is_rev);
	b_roll = take_iter(stk_b, pos_b, &b_is_rev);
	while (a_roll > 0 || b_roll > 0)
	{
		if (a_is_rev == b_is_rev && a_roll > 0 && b_roll > 0)
		{
			rotate_or_rrotate(stk_a, stk_b, a_is_rev, 'r');
			a_roll--;
			b_roll--;
		}
		else
		{
			if (a_roll > 0)
				a_roll -= rotate_or_rrotate(stk_a, stk_b, a_is_rev, 'a');
			if (b_roll > 0)
				b_roll -= rotate_or_rrotate(stk_a, stk_b, b_is_rev, 'b');
		}
	}
}
