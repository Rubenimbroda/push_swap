/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:41:03 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/13 15:38:44 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str)
{
	long int	res;
	int			is_neg;
	int			i;

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

int	abs_val(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

char	**join_args(int ac, char **av)
{
	char	*all_args;
	char	**split_args;
	int		i;

	all_args = ft_strdup("");
	i = 1;
	while (i < ac)
	{
		all_args = strjoin_free(all_args, av[i]);
		all_args = strjoin_free(all_args, " ");
		i++;
	}
	split_args = ft_split(all_args, ' ');
	free(all_args);
	return (split_args);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*strjoin_free(char *s1, char *s2)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	free(s1);
	return (new);
}
