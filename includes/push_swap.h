/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:01:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 11:44:25 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stackft.h"
# include <limits.h>

typedef struct s_pos
{
	int	src;
	int	dst;
}		t_pos;

typedef struct s_medians
{
	int	low_median;
	int	higt_median;
}		t_medians;

void	start(t_sstack *stk_a, t_sstack *stk_b);

// Parsing

long	init_stk(char **tab, long size, t_sstack *stk_a);
char	**take_tab(int argc, char **argv, long *cal_size);
int		check_dup(t_sstack *stk);

// Push Swap Lang

int		swap(t_sstack *stk_a, t_sstack *stk_b, char c, int check);
int		push(t_sstack *src, t_sstack *dst, char c, int check);
int		rotate(t_sstack *stk_a, t_sstack *stk_b, char c, int check);
int		rev_rotate(t_sstack *stk_a, t_sstack *stk_b, char c, int check);

// Sort function

void	short_sort(t_sstack *stk);
void	turkish_sort(t_sstack *stk_a, t_sstack *stk_b);

void	split_sort(t_sstack *stk_a, t_sstack *stk_b, int split_k);

int		find_kmedian(int *arr, int size, int k);

// Sort Utils

int		test_born(t_sstack *stk, int value, int is_ascending);
int		take_pos(t_sstack *stk, int value, int is_ascending);

// Utils

int		is_sort(t_sstack *stk);

int		get_born_max(t_sstack *stk);
int		get_born_min(t_sstack *stk);
int		take_iter(t_sstack *stk, int pos, int *is_rev);
int		rotate_or_rrotate(t_sstack *stk_a, t_sstack *stk_b, int is_rev,
			char name);
void	instruction(t_sstack *stk_a, t_sstack *stk_b, int pos_a, int pos_b);

#endif // PUSH_SWAP_H