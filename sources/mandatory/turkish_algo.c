/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:50:35 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 13:18:37 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calcule_cost(t_sstack *src, t_sstack *dst, int pos_src, int pos_dst)
{
	int	cost;
	int	src_roll;
	int	src_is_rev;
	int	dst_roll;
	int	dst_is_rev;

	cost = 0;
	src_roll = take_iter(src, pos_src, &src_is_rev);
	dst_roll = take_iter(dst, pos_dst, &dst_is_rev);
	if (dst_is_rev != src_is_rev)
		cost = src_roll + dst_roll;
	else if (src_roll > dst_roll)
		cost = src_roll;
	else if (src_roll <= dst_roll)
		cost = dst_roll;
	return (cost + 1);
}

static t_pos	take_best(t_sstack *src, t_sstack *dst, int is_ascending)
{
	int		pos_src;
	int		pos_dst;
	int		cost;
	int		tmp_cost;
	t_pos	final_pos;

	pos_src = 0;
	cost = INT_MAX;
	while (pos_src <= src->base)
	{
		pos_dst = take_pos(dst, src->data[pos_src], is_ascending);
		tmp_cost = calcule_cost(src, dst, pos_src, pos_dst);
		if (cost > tmp_cost)
		{
			final_pos.src = pos_src;
			final_pos.dst = pos_dst;
			cost = tmp_cost;
			if (cost <= 2)
				break ;
		}
		pos_src++;
	}
	return (final_pos);
}

void	short_sort(t_sstack *stk)
{
	int	max;

	max = stk->data[get_born_max(stk)];
	if (stk->data[0] == max)
		rotate(stk, NULL, 'a', 0);
	else if (stk->data[1] == max)
		rev_rotate(stk, NULL, 'a', 0);
	if (stk->data[0] > stk->data[1])
		swap(stk, NULL, 'a', 0);
}

void	turkish_sort(t_sstack *stk_a, t_sstack *stk_b)
{
	t_pos	pos;

	while ((int)s_len_stk(stk_a) > 3)
	{
		pos = take_best(stk_a, stk_b, 0);
		instruction(stk_a, stk_b, pos.src, pos.dst);
		push(stk_a, stk_b, 'b', 0);
	}
	short_sort(stk_a);
	while ((int)s_len_stk(stk_b) > 0)
	{
		pos = take_best(stk_b, stk_a, 1);
		instruction(stk_a, stk_b, pos.dst, pos.src);
		push(stk_b, stk_a, 'a', 0);
	}
	instruction(stk_a, stk_b, get_born_min(stk_a), 0);
}
