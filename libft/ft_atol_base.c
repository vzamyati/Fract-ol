/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 21:27:14 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/02 21:27:16 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_atol_base2(const char *str, int base)
{
	long		res;
	char		*dig;
	char		*tmp;
	int			i;

	dig = "0123456789abcdefghijklmnopqrstuvwxyz";
	res = 0;
	i = 0;
	while (str[i] && (tmp = (char *)ft_memchr(dig, ft_tolower(str[i]), base)))
	{
		res = (res * base) + (tmp - dig);
		i++;
	}
	return (res);
}

long			ft_atol_base(const char *str, int base)
{
	long		res;
	char		sign;
	int			i;

	sign = 1;
	i = 0;
	res = 0;
	if (!str || !*str || base < 2 || base > 36)
		return (res);
	while (ft_isspace(str[i]))
		i++;
	sign = (base == 10 && str[i] == '-') ? -1 : 1;
	if (base == 10 && (*str == '-' || *str == '+'))
		i++;
	if (base == 16 && str[i] == '0' && ft_tolower(str[i + 1]) == 'x')
		res = ft_atol_base2(str + 2, base);
	else
		res = ft_atol_base2(str, base);
	return (res * sign);
}
