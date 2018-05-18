/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:33:13 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/17 15:33:14 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*dst;
	char	*src;
	int		i;
	int		j;

	dst = (char *)haystack;
	src = (char *)needle;
	i = 0;
	j = 0;
	if (!src[j])
		return ((char *)haystack);
	while (dst[i])
	{
		j = 0;
		while (dst[i + j] == src[j] && src[j] != '\0')
		{
			j++;
			if (src[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
