/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:24:13 by vzamyati          #+#    #+#             */
/*   Updated: 2018/05/07 12:25:28 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtolower(char *str)
{
	int i;

	i = 0;
	if (str[i])
	{
		while (str[i] != '\0')
		{
			str[i] = ft_tolower(str[i]);
			i++;
		}
	}
}
