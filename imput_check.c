/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:00:03 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/12 18:06:09 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int valid_int(char *av)
{
    int i;
    
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

static int has_duplicates(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = 1;
        while (av[j])
        {
            if (j != i && nbrstr_cmp(av[i], av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int  arg_is_zero(char *av)
{
    int i;

    i = 0;
    if (is_sign(av[i]))
        i++;
    while ( (av[i] && av[i] == '0'))
        i++;
    if (av[i] != '\0')
        return (0);
    return (1);
}

int correct_imput(char **av)
{
    int i;
    int nb_zeros;

    i = 1;
    nb_zeros = 0;
    while (av[i])
    {
        if (!valid_int(av[i]))
            return (0);
        nb_zeros += arg_is_zero(av[i]);
        i++;
    }
    if (nb_zeros > 1)
        return (0);
    if (has_duplicates(av))
        return (0);
    return (1);
}