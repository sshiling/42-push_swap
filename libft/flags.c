/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:06:56 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/22 18:06:58 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	find_minus(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == '-')
	{
		tmp->spec[2] = ON;
		i++;
	}
	return (i);
}

size_t	find_plus(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == '+')
	{
		tmp->spec[3] = ON;
		i++;
	}
	return (i);
}

size_t	find_sharp(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == '#')
	{
		tmp->spec[4] = ON;
		i++;
	}
	return (i);
}

size_t	find_space(t_res *tmp, const char *format, size_t i)
{
	if (format[i] == ' ')
	{
		tmp->spec[5] = ON;
		i++;
	}
	return (i);
}

size_t	find_zero(t_res *tmp, const char *format, size_t i)
{
	if (format[0] == '0')
	{
		tmp->spec[0] = ON;
		i++;
	}
	else if (format[i] == '0' && format[i - 1] != '.')
	{
		tmp->spec[0] = ON;
		i++;
	}
	return (i);
}
