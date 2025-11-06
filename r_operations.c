/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:50:02 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/06 16:03:08 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int tmp;
	int i;

	i = a->top;
	tmp = a->arr[a->top];
	if (a->top < 1)
		return ;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int tmp;
	int i;

	i = b->top;
	tmp = b->arr[b->top];
	if (b->top < 1)
		return ;
	while (i > 0)
	{
		b->arr[i] = b->arr[i - 1];
		i--;
	}
	b->arr[0] = tmp;
	write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}