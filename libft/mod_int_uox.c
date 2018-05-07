/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_int_uox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:44:26 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/22 18:44:28 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	mod_int_uox(va_list list, t_res *tmp)
{
	if (MOD_Z)
		return ((size_t)(va_arg(list, size_t)));
	else if (MOD_J)
		return ((intmax_t)(va_arg(list, size_t)));
	else if (MOD_LL)
		return ((long long unsigned int)(va_arg(list, size_t)));
	else if (MOD_L)
		return ((long unsigned int)(va_arg(list, size_t)));
	else if (MOD_H)
		return ((short unsigned int)(va_arg(list, size_t)));
	else if (MOD_HH)
		return ((unsigned char)(va_arg(list, size_t)));
	else
		return ((unsigned int)(va_arg(list, size_t)));
}
