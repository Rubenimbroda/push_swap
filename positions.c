/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:57:19 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/13 10:56:48 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_positions(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return ;
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_lowest_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_i;
	int		lowest_pos;

	tmp = *stack;
	lowest_i = INT_MAX;
	get_positions(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->i < lowest_i)
		{
			lowest_i = tmp->i;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static int	get_should(t_stack **a, int idx_b, int idx_should, int should_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->i > idx_b && tmp_a->i < idx_should)
		{
			idx_should = tmp_a->i;
			should_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (idx_should != INT_MAX)
		return (should_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->i < idx_should)
		{
			idx_should = tmp_a->i;
			should_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (should_pos);
}

void	get_should_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		should_pos;

	tmp_b = *b;
	get_positions(a);
	get_positions(b);
	should_pos = 0;
	while (tmp_b)
	{
		should_pos = get_should(a, tmp_b->i, INT_MAX, should_pos);
		tmp_b->should_pos = should_pos;
		tmp_b = tmp_b->next;
	}
}
