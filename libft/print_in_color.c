/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:38:49 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/24 15:38:51 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*color_setter(char *s)
{
	if ((ft_strstr(s, "{eoc}")) != NULL)
		return ("\e[m");
	if ((ft_strstr(s, "{red}")) != NULL)
		return ("\e[31m");
	if ((ft_strstr(s, "{green}")) != NULL)
		return ("\e[32m");
	if ((ft_strstr(s, "{yellow}")) != NULL)
		return ("\e[33m");
	if ((ft_strstr(s, "{blue}")) != NULL)
		return ("\e[34m");
	if ((ft_strstr(s, "{magenta}")) != NULL)
		return ("\e[35m");
	if ((ft_strstr(s, "{cyan}")) != NULL)
		return ("\e[36m");
	if ((ft_strstr(s, "{white}")) != NULL)
		return ("\e[37m");
	return (NULL);
}

char	*color_finder(char *s)
{
	char	*finder;

	if ((finder = ft_strstr(s, "{eoc}")) != NULL)
		return (finder);
	if ((finder = ft_strstr(s, "{red}")) != NULL)
		return (finder);
	if ((finder = ft_strstr(s, "{green}")) != NULL)
		return (finder);
	if ((finder = ft_strstr(s, "{yellow}")) != NULL)
		return (finder);
	if ((finder = ft_strstr(s, "{blue}")) != NULL)
		return (finder);
	if ((finder = ft_strstr(s, "{magenta}")) != NULL)
		return (finder);
	if ((finder = ft_strstr(s, "{cyan}")) != NULL)
		return (finder);
	if ((finder = ft_strstr(s, "{white}")) != NULL)
		return (finder);
	return (NULL);
}

char	*create_final_color(char *finder, char *s)
{
	char *res;
	char *f2;

	f2 = ft_strchr(finder, '}');
	res = ft_strnew(finder - s + ft_strlen(f2) + ft_strlen(color_setter(s)));
	ft_strncpy(res, s, finder - s);
	ft_strncpy(&res[finder - s], color_setter(s), ft_strlen(color_setter(s)));
	ft_strncpy(&res[ft_strlen(res)], &f2[1], (ft_strlen(f2) - 1));
	ft_strdel(&s);
	s = res;
	return (s);
}

int		ft_putstr_data(char *s)
{
	char	*finder;
	int		i;
	int		j;

	if (g_fd <= 0)
		return (0);
	i = 0;
	j = 1;
	while (j == 1)
	{
		if ((finder = color_finder(s)) != NULL)
			s = create_final_color(finder, s);
		else
		{
			write(g_fd, s, ft_strlen(s));
			j = 0;
		}
	}
	return (ft_strlen(s));
}
