/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:19:10 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/13 17:19:13 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;
	unsigned char	c_tmp;
	size_t			i;

	s_tmp = (unsigned char *)s;
	c_tmp = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_tmp[i] != c_tmp)
			i++;
		else
			return (s_tmp + i);
	}
	return (NULL);
}
