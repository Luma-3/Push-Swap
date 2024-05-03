/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:13:26 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 13:37:04 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	s_init_stk(&stk_b, size);
	if (read_input(&stk_a, &stk_b) == -1)
		ft_putendl_fd("Error", 2);
	if (is_sort(&stk_a) && s_isempty_stk(&stk_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	s_clear_stk(&stk_a);
	s_clear_stk(&stk_b);
	return (0);
}
