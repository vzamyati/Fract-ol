/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 18:49:14 by vzamyati          #+#    #+#             */
/*   Updated: 2018/03/04 20:23:23 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			writing(t_mygnl *tmp, char **line)
{
	char			*temp;

	temp = NULL;
	if (tmp->str && *tmp->str)
	{
		if ((tmp->next_line = ft_strchr(tmp->str, '\n')))
		{
			*line = ft_strsub(tmp->str, 0, tmp->next_line - tmp->str);
			temp = tmp->str;
			tmp->str = ft_strdup(++tmp->next_line);
			ft_strdel(&temp);
		}
		else if (!tmp->next_line && *tmp->str)
		{
			*line = tmp->str;
			tmp->str = NULL;
		}
		return (1);
	}
	return (0);
}

static int			reading(t_mygnl *tmp, char **line)
{
	char			*buff;
	ssize_t			ret;
	char			*temp;

	temp = NULL;
	buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(tmp->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin((tmp->str), buff);
		free(tmp->str);
		tmp->str = temp;
		tmp->next_line = ft_strchr(tmp->str, '\n');
		if (tmp->next_line)
			break ;
	}
	free(buff);
	if (ret < 0)
		return (-1);
	return (writing(tmp, line));
}

int					get_next_line(const int fd, char **line)
{
	static t_mygnl	*box = NULL;
	t_mygnl			*tmp;

	tmp = box;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while (tmp != NULL && (tmp->fd != fd))
		tmp = tmp->next;
	if (tmp == NULL)
	{
		tmp = (t_mygnl*)malloc(sizeof(t_mygnl));
		tmp->fd = fd;
		tmp->str = ft_strnew(0);
		tmp->next_line = NULL;
		tmp->next = box;
		box = tmp;
	}
	return (reading(tmp, line));
}
