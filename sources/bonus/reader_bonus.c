/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:13:22 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 13:28:11 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	parse_exec(char *rule, t_sstack *stk_a, t_sstack *stk_b)
{
	int	verif;

	verif = -1;
	if (ft_strlen(rule) - 1 == 3)
	{
		if (ft_strncmp(rule, "rr", 2) == 0)
			verif = rev_rotate(stk_a, stk_b, rule[2], 1);
	}
	else if (rule[0] == 'p')
	{
		if (rule[1] == 'a')
			verif = push(stk_b, stk_a, 'a', 1);
		else if (rule[1] == 'b')
			verif = push(stk_a, stk_b, 'b', 1);
	}
	else if (rule[0] == 's')
		verif = swap(stk_a, stk_b, rule[1], 1);
	else if (rule[0] == 'r')
		verif = rotate(stk_a, stk_b, rule[1], 1);
	return (verif);
}

int	read_input(t_sstack *stk_a, t_sstack *stk_b)
{
	char	*line;
	int		format;

	format = 0;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (parse_exec(line, stk_a, stk_b) == -1)
			format = -1;
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	return (format);
}
