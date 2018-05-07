/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:10:58 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/22 18:11:00 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	find_h(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == 'h' && format[i + 1] != 'h')
	{
		tmp->spec[7] = ON;
		i++;
	}
	else if (format[i] == 'h' && format[i + 1] == 'h')
	{
		tmp->spec[6] = ON;
		i = i + 2;
	}
	return (i);
}

size_t	find_l(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == 'l' && format[i + 1] != 'l')
	{
		tmp->spec[9] = ON;
		i++;
	}
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		tmp->spec[8] = ON;
		i = i + 2;
	}
	return (i);
}

size_t	find_j(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == 'j')
	{
		tmp->spec[10] = ON;
		i++;
	}
	return (i);
}

size_t	find_z(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == 'z')
	{
		tmp->spec[11] = ON;
		i++;
	}
	return (i);
}

size_t	find_t(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == 't' && format[i + 1] != 't')
	{
		tmp->spec[12] = ON;
		i++;
	}
	else if (format[i] == 't' && format[i + 1] == 't')
	{
		tmp->spec[13] = ON;
		i = i + 2;
	}
	return (i);
}
