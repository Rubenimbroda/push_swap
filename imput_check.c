/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:00:03 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/13 15:38:54 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_int(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	if (!is_digit(av[i]))
		return (0);
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

static int	has_duplicates(char **av)
{
	int		i;
	int		j;
	long	n1;
	long	n2;

	i = 0;
	while (av[i])
	{
		n1 = ft_atol(av[i]);
		j = 1 + i;
		while (av[j])
		{
			n2 = ft_atol(av[j]);
			if (n1 == n2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while ((av[i] && av[i] == '0'))
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	correct_imput(int ac, char **av)
{
	int		i;
	int		nb_zeros;
	char	**args;

	args = join_args(ac, av);
	i = 0;
	nb_zeros = 0;
	while (args[i])
	{
		if (!valid_int(args[i]))
		{
			free_split(args);
			return (0);
		}
		nb_zeros += arg_is_zero(args[i]);
		i++;
	}
	if (nb_zeros > 1 || has_duplicates(args))
	{
		free_split(args);
		return (0);
	}
	free_split(args);
	return (1);
}
