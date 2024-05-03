/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslang.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:27:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 11:48:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

int	swap(t_sstack *stk_a, t_sstack *stk_b, char c, int check)
{
	if (!(c == 'a' || c == 'b' || c == 's'))
		return (-1);
	if (c == 'a' || c == 's')
		s_swap_stk(stk_a);
	if (c == 'b' || c == 's')
		s_swap_stk(stk_b);
	if (check == 0)
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

int	push(t_sstack *src, t_sstack *dst, char c, int check)
{
	if (!(c == 'a' || c == 'b'))
		return (-1);
	s_push_stk(dst, s_pop_stk(src));
	if (check == 0)
	{
		ft_putchar_fd('p', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

int	rotate(t_sstack *stk_a, t_sstack *stk_b, char c, int check)
{
	if (!(c == 'a' || c == 'b' || c == 'r'))
		return (-1);
	if (c == 'a' || c == 'r')
		s_rollup_stk(stk_a);
	if (c == 'b' || c == 'r')
		s_rollup_stk(stk_b);
	if (check == 0)
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

int	rev_rotate(t_sstack *stk_a, t_sstack *stk_b, char c, int check)
{
	if (!(c == 'a' || c == 'b' || c == 'r'))
		return (-1);
	if (c == 'a' || c == 'r')
		s_rolldown_stk(stk_a);
	if (c == 'b' || c == 'r')
		s_rolldown_stk(stk_b);
	if (check == 0)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
