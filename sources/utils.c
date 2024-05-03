/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:56:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 10:56:34 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

int	is_sort(t_sstack *stk)
{
	int	i;
	int	len;

	i = -1;
	len = s_len_stk(stk);
	while (++i + 1 < len)
	{
		if (!(stk->data[i] < stk->data[i + 1]))
			return (0);
	}
	return (1);
}
