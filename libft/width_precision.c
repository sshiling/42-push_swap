/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:57:17 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/22 17:57:19 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	find_dot(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == '.')
	{
		tmp->spec[1] = ON;
		i++;
	}
	return (i);
}

size_t	wildcard_precision(t_res *tmp, va_list list, size_t i)
{
	tmp->precision = va_arg(list, size_t);
	if (tmp->precision < 0)
	{
		tmp->precision = 0;
		DOT = OFF;
	}
	i++;
	return (i);
}

size_t	find_precision(t_res *tmp, const char *format, size_t i, va_list list)
{
	char	*str;

	if (NUM(format[i]) && format[i - 1] == '.')
	{
		str = ft_strnew(2);
		while (NUM(format[i]))
		{
			str = add_one_char(str, format[i]);
			i++;
		}
		tmp->precision = ft_atoi(str);
		free(str);
	}
	if (format[i] == '*' && format[i - 1] == '.')
		i = wildcard_precision(tmp, list, i);
	else if (!(NUM(format[i])) && format[i - 1] == '.')
		tmp->precision = 0;
	return (i);
}

size_t	wildcard_width(t_res *tmp, va_list list, size_t i)
{
	tmp->width = va_arg(list, size_t);
	if (tmp->width < 0)
	{
		MINUS = ON;
		tmp->width = -(tmp->width);
	}
	i++;
	return (i);
}

size_t	find_width(t_res *tmp, const char *format, size_t i, va_list list)
{
	char	*str;

	if (NUM(format[i]) && format[i] != '0' && format[i - 1] != '.')
	{
		str = ft_strnew(sizeof(char));
		while (NUM(format[i]))
		{
			str = add_one_char(str, format[i]);
			i++;
		}
		tmp->width = ft_atoi(str);
		free(str);
	}
	if (format[i] == '*' && format[i - 1] != '.')
		i = wildcard_width(tmp, list, i);
	return (i);
}
