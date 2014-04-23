/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazian <akazian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 13:34:18 by akazian           #+#    #+#             */
/*   Updated: 2014/04/16 14:30:16 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static char		*search_n(char *buf, int rd, int *pos)
{
	int		i;
	char	*ret;

	i = *pos;
	while (i < rd)
	{
		if (buf[i] == '\n')
		{
			ret = ft_strsub((char const *)buf, *pos, (i - *pos));
			*pos = i + 1;
			return (ret);
		}
		i++;
	}
	return (buf);
}

static int		ft_strlenn(char *str, int max)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < max)
		i++;
	return (i);
}

static char		*line_cat(char *line, char *src, int rd)
{
	char	*tmp;
	int		i;
	int		j;

	if (line == NULL)
		return (ft_strsub((char const *)src, 0, ft_strlenn(src, rd)));
	j = 0;
	tmp = line;
	i = ft_strlen(line);
	line = ft_strnew(i + ft_strlenn(src, rd));
	ft_strcpy(line, tmp);
	free(tmp);
	while (src[j] != '\0' && j < rd)
	{
		line[i] = src[j];
		j++;
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int		rd_value(int const fd, char **line, int *pos, char *buf)
{
	int		rd;
	char	*n_found;

	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		*pos = 0;
		n_found = search_n(buf, rd, pos);
		if (n_found != buf)
		{
			*line = line_cat(*line, n_found, rd);
			free(n_found);
			return (rd);
		}
		if (n_found == buf)
			*line = line_cat(*line, buf, rd);
	}
	return (rd);
}

int				get_next_line(int const fd, char **line)
{
	static int	rd = 0;
	static int	pos = 0;
	static char	buf[BUFF_SIZE];

	*line = NULL;
	if (pos < rd)
	{
		*line = search_n(buf, rd, &pos);
		if (*line != buf)
			return (1);
		else
			*line = ft_strsub((const char*)buf, pos, rd - pos);
	}
	rd = rd_value(fd, line, &pos, buf);
	if (rd == -1)
		return (-1);
	if (rd == 0 && *line == NULL)
		return (0);
	return (1);
}
