/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:06:33 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/17 21:06:34 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*dst;
	char	*src;
	size_t	i;
	size_t	j;

	dst = (char *)haystack;
	src = (char *)needle;
	i = 0;
	j = 0;
	if (!src[j])
		return ((char *)haystack);
	while (dst[i] && i < len)
	{
		j = 0;
		while (dst[i + j] == src[j] && src[j] != '\0' && i + j < len)
		{
			j++;
			if (src[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
