/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:23:18 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/21 13:23:20 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	*find_specif(t_res *tmp, const char *format, size_t i, va_list list)
{
	if (format[i])
		tmp->c = format[i];
	tmp->i = format[i] == '\0' ? i : i + 1;
	result_creator(list, tmp);
	return (tmp);
}

t_res	*pre_res(t_res *tmp, const char *format, size_t i, va_list list)
{
	while (ALL(format[i]))
	{
		i = find_dot(tmp, format, i);
		i = find_minus(tmp, format, i);
		i = find_plus(tmp, format, i);
		i = find_sharp(tmp, format, i);
		i = find_space(tmp, format, i);
		i = find_h(tmp, format, i);
		i = find_l(tmp, format, i);
		i = find_j(tmp, format, i);
		i = find_z(tmp, format, i);
		i = find_zero(tmp, format, i);
		i = find_precision(tmp, format, i, list);
		i = find_width(tmp, format, i, list);
		i = find_t(tmp, format, i);
	}
	return (find_specif(tmp, format, i, list));
}
