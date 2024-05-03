/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:27:53 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 11:46:06 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start(t_sstack *stk_a, t_sstack *stk_b)
{
	int	len_a;
	int	k;

	k = 3;
	len_a = s_len_stk(stk_a);
	if (len_a <= 3)
		short_sort(stk_a);
	else if (len_a > 100)
	{
		if (len_a >= 300)
			k = 6;
		split_sort(stk_a, stk_b, k);
	}
	else
	{
		push(stk_a, stk_b, 'b', 0);
		push(stk_a, stk_b, 'b', 0);
		turkish_sort(stk_a, stk_b);
	}
}

int	parse(char **argv, int argc, t_sstack *stk_a)
{
	long	cal_size;
	long	size;

	cal_size = 0;
	argv = take_tab(argc, argv, &cal_size);
	s_init_stk(stk_a, cal_size);
	if (!stk_a->data)
		return (-1);
	size = init_stk(argv, cal_size, stk_a);
	if (argc == 2)
		ft_rm_split(argv);
	if (size != cal_size || !check_dup(stk_a) || size <= 0)
	{
		s_clear_stk(stk_a);
		return (-1);
	}
	return (size);
}

int	main(int argc, char **argv)
{
	long		size;
	t_sstack	stk_a;
	t_sstack	stk_b;

	if (argc == 1)
		return (0);
	size = parse(argv, argc, &stk_a);
	if (size <= 0)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if (is_sort(&stk_a))
		return (s_clear_stk(&stk_a), 0);
	s_init_stk(&stk_b, size);
	start(&stk_a, &stk_b);
	s_clear_stk(&stk_a);
	s_clear_stk(&stk_b);
	return (0);
}
