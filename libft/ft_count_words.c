/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:53:53 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/06 16:53:55 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	tmp = (char *)str;
	if (tmp[i] != c)
	{
		i++;
		j++;
	}
	while (tmp[i])
	{
		if (tmp[i] != c && tmp[i - 1] != c)
			j++;
		i++;
	}
	return (j);
}
