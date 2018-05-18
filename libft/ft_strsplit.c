/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:16:14 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/24 15:16:22 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_words(char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		k++;
	}
	return (k);
}

static char	*ft_rewrite(char const *s, int i, int k, char c)
{
	char	*tmp;
	int		j;

	j = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	while (s[i] && s[i] != c)
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (tmp);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		w;
	char	**res;

	i = 0;
	j = 0;
	w = 0;
	if (!s || (!(res = (char **)malloc(sizeof(char *) * find_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + k] != c && s[i + k] != '\0')
			k++;
		if (k == 0)
			break ;
		res[w++] = ft_rewrite(s, i, k, c);
		i = i + k;
	}
	res[w] = NULL;
	return (res);
}
