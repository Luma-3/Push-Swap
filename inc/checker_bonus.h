/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:17:48 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 11:44:09 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"
# include "stackft.h"

// PSLANG

int		swap(t_sstack *stk_a, t_sstack *stk_b, char c, int check);
int		push(t_sstack *src, t_sstack *dst, char c, int check);
int		rotate(t_sstack *stk_a, t_sstack *stk_b, char c, int check);
int		rev_rotate(t_sstack *stk_a, t_sstack *stk_b, char c, int check);

// Parsing ARGV

int		check_dup(t_sstack *stk);
long	init_stk(char **tab, long size, t_sstack *stk_a);
char	**take_tab(int argc, char **argv, long *cal_size);

int		is_sort(t_sstack *stk);

int		read_input(t_sstack *stk_a, t_sstack *stk_b);

#endif //CHECKER_BONUS_H