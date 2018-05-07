/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:17:42 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/12 11:17:45 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line	*new_tail(int fd)
{
	t_line	*new;

	new = (t_line*)malloc(sizeof(t_line));
	new->data = ft_strnew(0);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

t_line	*fd_finder(t_line *tail, int fd)
{
	t_line	*tmp;

	tmp = tail;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		str_finder(char **s, char **line, int key)
{
	int		i;
	char	*str;

	i = -1;
	str = *s;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			*line = ft_strsub(str, 0, i);
			*s = ft_memmove(*s, &str[i + 1], ft_strlen(&str[i + 1]) + 1);
			return (-1);
		}
	}
	if (str[i] == '\0' && str[i - 1] != '\n' && key == 0)
	{
		*line = ft_strsub(str, 0, i);
		*s = ft_memmove(*s, &str[i], ft_strlen(&str[i]) + 1);
		return (-1);
	}
	return (0);
}

t_line	*tmp_fd_in(t_line *tmp, t_line *tail, int fd)
{
	tmp = tail;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_tail(fd);
	tmp = tmp->next;
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*tail;
	t_line			*tmp;
	char			*del;
	char			buf[BUFF_SIZE + 1];
	int				key;

	if (tail == NULL)
		tail = new_tail(fd);
	if ((tmp = fd_finder(tail, fd)) == NULL)
		tmp = tmp_fd_in(tmp, tail, fd);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((key = read(fd, buf, BUFF_SIZE)) > 0)
	{
		del = tmp->data;
		tmp->data = ft_strjoin(tmp->data, buf);
		ft_strdel(&del);
		ft_bzero(buf, BUFF_SIZE + 1);
		if (str_finder(&(tmp->data), line, key) == -1)
			return (1);
	}
	if (key == -1 || (key == 0 && tmp->data[0] == '\0'))
		return (key = key == -1 ? -1 : 0);
	if (str_finder(&(tmp->data), line, key) == -1)
		return (1);
	return (0);
}
