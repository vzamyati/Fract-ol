/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:06:25 by vzamyati          #+#    #+#             */
/*   Updated: 2017/12/02 15:06:26 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstlen(t_list *lst)
{
	t_list	*tmp;
	size_t	len;

	len = 0;
	tmp = lst;
	if (lst)
		while (tmp)
		{
			len++;
			tmp = tmp->next;
		}
	return (len);
}
