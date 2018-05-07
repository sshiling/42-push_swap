/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:36:49 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/22 19:36:51 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_new(char const *s)
{
	int		i;

	if (g_fd <= 0)
		return (0);
	i = 0;
	if (s == NULL)
		return (i);
	i = ft_strlen(s);
	ft_putstr_fd(s, g_fd);
	return (i);
}

int		ft_putstr_res(char *s, t_res *tmp)
{
	if (g_fd <= 0)
		return (0);
	write(g_fd, s, tmp->length);
	return (tmp->length);
}

int		result_printer(t_res *res)
{
	t_res	*tmp;
	int		i;

	i = 0;
	tmp = res;
	while (tmp->next)
	{
		if (tmp->data)
			i = i + ft_putstr_data(tmp->data);
		if (tmp->result && (tmp->c == 'c' || tmp->c == 'C' || tmp->c == 'r'))
			i = i + ft_putstr_res(tmp->result, tmp);
		else if (tmp->result && tmp->c != 'n')
			i = i + ft_putstr_new(tmp->result);
		if (tmp->c == 'y')
			ft_putnbr(i);
		else if (tmp->c == 'n')
		{
			if (tmp->result)
				*((size_t*)(tmp->result)) = i;
			tmp->result = ft_strnew(0);
		}
		tmp = tmp->next;
	}
	return (i);
}

void	t_res_del(t_res *src)
{
	t_res	*tmp;
	t_res	*del;

	tmp = src;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del->spec);
		free(del->data);
		free(del->result);
		free(del);
	}
}
