/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:49:18 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/13 19:49:23 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_tmp;
	unsigned char	*dst_tmp;
	size_t			i;

	i = 0;
	src_tmp = (unsigned char *)src;
	dst_tmp = (unsigned char *)dst;
	while (len > 0)
	{
		if (src < dst)
			dst_tmp[i + len - 1] = src_tmp[i + len - 1];
		else
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
		len--;
	}
	return (dst);
}
