/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:06:33 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/07 14:06:38 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 512
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_line
{
	char			*data;
	int				fd;
	struct s_line	*next;
}					t_line;
int					get_next_line(const int fd, char **line);

#endif
