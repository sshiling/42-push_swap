/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:56:20 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/23 14:56:21 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_binary(va_list list, t_res *tmp)
{
	char	*src;

	src = ft_itoa_base((int)(va_arg(list, ssize_t)), 2, tmp);
	if (src == NULL)
		src = ft_strdup("null");
	return (src);
}
