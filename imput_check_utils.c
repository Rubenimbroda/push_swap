/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:07:28 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/07 18:22:17 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_sign(char c)
{
    return (c == '+' || c == '-');
}

int nbrstr_cmp(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    j = i;
    if (s1[i] == '+')
    {
        if (s2[j] != '+')
            i++;
    }
    else
    {
        if (s2[j] == '+')
            j++;
    }
    while (s1[i] && s2[j] && s1[i] == s2[j])
    {
        i++;
        j++;
    }
    return((unsigned char)s1[i] - (unsigned char)s2[j]);
}