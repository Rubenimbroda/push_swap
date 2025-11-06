/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_sa_sb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:09:55 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/06 15:46:51 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (a->top > 0)
	{
		swap(&a->arr[a->top], &a->arr[a->top - 1]);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	if (b->top > 0)
	{
		swap(&b->arr[b->top], &b->arr[b->top - 1]);
		write(1, "sb\n", 1);
	}
}
