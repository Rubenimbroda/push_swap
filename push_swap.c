/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:25:47 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/13 15:35:18 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*a))
		sa(a);
	else if (stack_size == 3)
		sort_three(a);
	else if (stack_size > 3 && !is_sorted(*a))
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;
	char	**args;

	if (ac < 2)
		return (0);
	if (!correct_imput(ac, av))
		exit_error(NULL, NULL);
	args = join_args(ac, av);
	a = fill_stack_value(args);
	b = NULL;
	stack_size = get_stack_size(a);
	assign_index(a, stack_size);
	push_swap(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
	free_split(args);
	return (0);
}
