/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:49:23 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/22 15:50:25 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	*create_n(va_list list, t_res *tmp)
{
	if (MOD_Z)
		return (size_t*)(va_arg(list, size_t*));
	else if (MOD_J)
		return (size_t*)(va_arg(list, intmax_t*));
	else if (MOD_LL)
		return (size_t*)(va_arg(list, long long unsigned int*));
	else if (MOD_L)
		return (size_t*)(va_arg(list, long unsigned int*));
	else if (MOD_H)
		return (size_t*)(va_arg(list, short unsigned int*));
	else if (MOD_HH)
		return (size_t*)(va_arg(list, unsigned char*));
	else
		return (size_t*)(va_arg(list, unsigned int*));
}
