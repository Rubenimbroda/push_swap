/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:59:23 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/12 18:20:59 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int    ft_atol(const char *str)
{
    long int    res;
    int         is_neg;
    int         i;

    res = 0;
    is_neg = 1;
    i = 0;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        is_neg *= -1;
        i++;
    }
    while (is_digit(str[i]))
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * is_neg);
}

void    free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !(*stack))
        return ;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

void    exit_error(t_stack **a, t_stack **b)
{
    free_stack(a);
    free_stack(b);
    write(2, "Error\n", 6);
    exit (1);
}

int abs_val(int nbr)
{
    if (nbr < 0)
        return (nbr * -1);
    return (nbr);
}

t_stack *fill_stack_value(int ac, char **av)
{
    t_stack     *a;
    long int    nbr;
    int         i;

    a = NULL;
    nbr = 0;
    i = 1;
    while (i < ac)
    {
        nbr = ft_atol(av[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
            exit_error(&a, NULL);
        if (i == 1)
            a = new_element((int)nbr);
        else
            stack_add_end(&a, new_element((int)nbr));
        i++;
    }
    return (a);
}

void    assign_index(t_stack *a, int stack_size)
{
    t_stack *ptr;
    t_stack *highest;
    int     val;

    while (--stack_size > 0)
    {
        ptr = a;
        val = INT_MIN;
        highest = NULL;
        while (ptr)
        {
            if (ptr->value == INT_MIN && ptr->i == 0)
                ptr->i = 1;
            if (ptr->value > val && ptr->i == 0)
            {
                val = ptr->value;
                highest = ptr;
                ptr = a;
            }
            else
                ptr = ptr->next;
        }
        if (highest != NULL)
            highest->i = stack_size;
    }
}
