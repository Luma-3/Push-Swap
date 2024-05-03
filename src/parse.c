/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:29:40 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/30 17:49:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

static int	verif_nb(const char *str)
{
	int	i;
	int	zero;

	i = -1;
	zero = 0;
	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			i++;
		else if (str[i] == '-')
			return (0);
		if ((i == 0 || i == 1) && zero == 0 && str[i] == '0')
			zero = 1;
		else if ((i == 0 || i == 1) && str[i] == '0')
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	check_dup(t_sstack *stk)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= stk->base)
	{
		j = i;
		while (++j <= stk->base)
		{
			if (stk->data[i] == stk->data[j])
				return (0);
		}
	}
	return (1);
}

long	init_stk(char **tab, long size, t_sstack *stk_a)
{
	int		i;
	long	tmp;

	i = (int)size;
	while (--i >= 0)
	{
		if (!verif_nb(tab[i]))
			return (-1);
		tmp = ft_atol(tab[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (-1);
		s_push_stk(stk_a, tmp);
	}
	return (size);
}

char	**take_tab(int argc, char **argv, long *cal_size)
{	
	char	**tab;

	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		while (tab[*cal_size] != 0)
			*cal_size += 1;
	}
	else
	{
		*cal_size = argc - 1;
		tab = ++argv;
	}
	return (tab);
}
