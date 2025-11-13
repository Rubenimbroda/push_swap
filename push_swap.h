/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:24:07 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/13 15:33:42 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				i;
	int				pos;
	int				should_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

int			correct_imput(int ac, char **av);
int			is_digit(char c);
int			is_sign(char c);
t_stack		*get_last_element(t_stack *stack);
t_stack		*get_before_last_element(t_stack *stack);
t_stack		*new_element(int value);
void		stack_add_end(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack *stack);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		choose_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		get_cost(t_stack **a, t_stack **b);
void		cheapest_move(t_stack **a, t_stack **b);
void		free_stack(t_stack **stack);
void		exit_error(t_stack **a, t_stack **b);
int			abs_val(int nbr);
int			get_lowest_pos(t_stack **stack);
void		get_should_position(t_stack **a, t_stack **b);
void		sort_three(t_stack **stack);
int			is_sorted(t_stack *stack);
void		sort(t_stack **a, t_stack **b);
t_stack		*fill_stack_value(char **av);
void		assign_index(t_stack *a, int stack_size);
long int	ft_atol(const char *str);
int			abs_val(int nbr);
char		**join_args(int ac, char **av);
void		free_split(char **split);
char		*strjoin_free(char *s1, char *s2);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strcat(char *dest, const char *src);

#endif