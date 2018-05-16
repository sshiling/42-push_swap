/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:03:27 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/20 14:45:23 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int g_fd = 1;

t_res	*new_res(void)
{
	t_res	*res;
	int		i;

	i = 0;
	res = (t_res*)malloc(sizeof(t_res));
	if (res == NULL)
		return (NULL);
	res->spec = (int*)malloc(sizeof(int) * 14);
	while (i < 14)
	{
		res->spec[i] = OFF;
		i++;
	}
	res->data = ft_strnew(sizeof(char));
	res->c = '\0';
	res->width = 0;
	res->precision = 0;
	res->i = 0;
	res->result = NULL;
	res->length = 0;
	res->next = NULL;
	return (res);
}

char	*add_one_char(char *tmp, char c)
{
	char	*str;

	str = ft_strnew(ft_strlen(tmp) + 1);
	ft_strncpy(str, tmp, ft_strlen(tmp));
	str[ft_strlen(tmp)] = c;
	free(tmp);
	return (str);
}

t_res	*save_prcnt(t_res *tmp, int i)
{
	char	*del;

	del = tmp->data;
	tmp->data = ft_strnew(sizeof(char));
	ft_memset(tmp->data, '%', 1);
	tmp->next = new_res();
	i += 1;
	tmp = tmp->next;
	tmp->i = i;
	free(del);
	return (tmp);
}

t_res	*tmp_result(const char *format, t_res *tmp, size_t i, va_list list)
{
	if (format[i] == '%' && format[i + 1] == '%')
		tmp = save_prcnt(tmp, i + 1);
	else if (format[i] == '%' && format[i + 1] != '%')
	{
		tmp = pre_res(tmp, format, i + 1, list);
		i = tmp->i;
		tmp->next = new_res();
		tmp = tmp->next;
		tmp->i = i;
	}
	else
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			tmp->data = add_one_char(tmp->data, format[i]);
			i++;
		}
		tmp->i = i;
		tmp->next = new_res();
		tmp = tmp->next;
		tmp->i = i;
	}
	return (tmp);
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	t_res		*res;
	t_res		*tmp;
	size_t		i;

	i = 0;
	res = new_res();
	tmp = res;
	va_start(list, format);
	while (i < ft_strlen(format))
	{
		tmp = tmp_result(format, tmp, i, list);
		i = tmp->i;
	}
	res = result_creator(list, res);
	va_end(list);
	i = result_printer(res);
	t_res_del(res);
	return (i);
}
