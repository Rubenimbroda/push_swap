/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:25:47 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/12 16:24:27 by rubenior         ###   ########.fr       */
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

	if (ac < 2)
		return (0);
	ft_printf("Checking input...\n");
	if (!correct_imput(av))
		exit_error(NULL, NULL);
	ft_printf("Filling stack...\n");
	a = fill_stack_value(ac, av);
	b = NULL;
	ft_printf("Counting stack size...\n");
	stack_size = get_stack_size(a);
	ft_printf("Assigning index...\n");
	assign_index(a, stack_size);
	ft_printf("Sorting...\n");
	push_swap(&a, &b, stack_size);
	ft_printf("Freeing...\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}

