/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 08:39:49 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/21 08:39:52 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*second(int len, int sign, int n)
{
	char *res;

	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (len == 0 && sign < 0)
			break ;
		res[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (sign < 0)
		res[len] = '-';
	return (res);
}

char		*ft_itoa(int n)
{
	int	nb;
	int len;
	int sign;

	nb = n;
	len = 0;
	sign = 1;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
		len++;
	}
	nb = n;
	while (nb /= 10)
		len++;
	len++;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (second(len, sign, n));
}
