/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:51:49 by vzamyati          #+#    #+#             */
/*   Updated: 2017/11/29 14:51:52 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp_next;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			tmp_next = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = tmp_next;
		}
		*alst = NULL;
	}
}
