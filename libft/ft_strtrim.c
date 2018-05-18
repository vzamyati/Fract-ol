/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:06:32 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/20 17:06:33 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	j = (ft_strlen(s) - 1);
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && s[j] && j > i)
		j--;
	res = ft_strnew((j - i) + 1);
	if (!res)
		return (NULL);
	k = 0;
	while (i <= j)
		res[k++] = s[i++];
	res[k] = '\0';
	return (res);
}
