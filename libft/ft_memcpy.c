/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:46:39 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/10 21:46:41 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_tmp;
	char	*src_tmp;
	int		i;

	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	i = 0;
	while (n > 0)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
		n--;
	}
	return (dst);
}
