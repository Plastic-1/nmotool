/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mfd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 21:40:32 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/16 14:30:42 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_to_char(t_list *cur_fd, char **line, char *buf)
{
	char		*tmp;
	char		*line2;
	size_t		i;
	long long	ret;

	*line = ft_strnew(0);
	while (1)
	{
		i = 0;
		tmp = ft_strnew(BUFF_SIZE);
		while (buf[i] != '\n' && buf[i] != '\0')
		{
			tmp[i] = buf[i];
			i++;
		}
		line2 = *line;
		*line = ft_strjoin(line2, tmp);
		ft_strdel(&line2);
		ft_strdel(&tmp);
		if (buf[i] == '\n')
			return (i + 1);
		ft_strclr(buf);
		if ((ret = read(cur_fd->content_size, buf, BUFF_SIZE)) <= 0)
			return (ret - (i * 2));
	}
}

static int		save_and_restore(t_list *cur_fd, char **line)
{
	char		*save;
	char		*buf;
	long long	i;
	long long	i2;

	save = cur_fd->content;
	buf = ft_strnew(BUFF_SIZE);
	i = 0;
	i2 = 0;
	while (save[i] != '\0')
	{
		buf[i] = save[i];
		i++;
	}
	ft_strclr(save);
	if ((i = read_to_char(cur_fd, line, buf)) > 0)
	{
		while (buf[i] != '\0')
			save[i2++] = buf[i++];
		return (1);
	}
	else if (i < -1)
		return (1);
	else
		return (i);
}

static void		del_cur_fd(t_list *list, t_list *cur_fd)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next->content_size != cur_fd->content_size)
		tmp = tmp->next;
	tmp->next = cur_fd->next;
	free(cur_fd->content);
	free(cur_fd);
}

static t_list	*fd_to_elem(const size_t fd, t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next != NULL)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->content_size != fd)
	{
		tmp->next = ft_lstnew(ft_strnew(BUFF_SIZE), fd);
		tmp = tmp->next;
	}
	return (tmp);
}

int				get_next_line_mfd(int const fd, char **line)
{
	static t_list	*list;
	t_list			*cur_fd;
	int				ret;

	if (BUFF_SIZE <= 0)
		return (-1);
	if (!list)
		list = ft_lstnew(ft_strnew(BUFF_SIZE), -1);
	cur_fd = fd_to_elem((size_t)fd, list);
	ret = save_and_restore(cur_fd, line);
	if (ret <= 0)
		del_cur_fd(list, cur_fd);
	return (ret);
}
