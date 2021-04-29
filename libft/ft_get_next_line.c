/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:13:34 by zlayine           #+#    #+#             */
/*   Updated: 2021/04/29 14:20:56 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*make_str(char *s1, char *s2)
{
	if (s1)
		return (ft_strjoin(s1, s2));
	return (ft_strdup(s2));
}

static int	free_bufs(char *b1, char *b2, int ret)
{
	if (ret == -1)
	{
		new_str(b1, NULL);
		new_str(b2, NULL);
	}
	return (ret);
}

static int	make_next_line(char **s, char **line)
{
	int		i;
	char	*tmp;

	if (*s)
	{
		if (ft_strchr(*s, '\n'))
		{
			i = get_newln_len(*s);
			*line = new_str(*line, ft_substr(*s, 0, i));
			*s = new_str(*s, ft_strdup(*s + i + 1));
			if (!*line || !*s)
				return (-1);
			return (1);
		}
		else if (ft_strlen(*s))
		{
			tmp = make_str(*line, *s);
			*s = new_str(*s, NULL);
			*line = new_str(*line, tmp);
			return (0);
		}
		ft_del(*s);
		*s = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*s;
	char		*buf;
	char		*tmp;
	int			rs;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	*line = ft_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rs = 1;
	while (rs)
	{
		rs = read(fd, buf, BUFFER_SIZE);
		buf[rs] = '\0';
		tmp = make_str(s, buf);
		s = new_str(s, tmp);
		ft_del(buf);
		if (ft_strchr(s, '\n'))
			break ;
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	if (rs == 0)
		ft_del(buf);
	return (free_bufs(*line, s, make_next_line(&s, line)));
}
