/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:24:44 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/18 15:24:47 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int			i;
	int			min;
	long long	res;

	i = 0;
	res = 0;
	min = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		min = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		res = 10 * res + (str[i] - 48);
		i++;
		if (i > 19 || res > 9223372036854775807)
			return ((min == 1) ? -1 : 0);
	}
	return (min * res);
}
