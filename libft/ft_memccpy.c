/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:46:39 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/10 21:46:41 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	unsigned char	c_tmp;
	int				i;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	c_tmp = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		dst_tmp[i] = src_tmp[i];
		if (src_tmp[i] == c_tmp)
			return (dst + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
