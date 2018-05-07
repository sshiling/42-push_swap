/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:50:38 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/22 15:50:53 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	str_fill(t_res *tmp)
{
	if (ZERO && !MINUS)
		return ('0');
	return (' ');
}

char	*create_c(va_list list, t_res *tmp)
{
	char	*str;
	int		c;
	int		i;

	tmp->length = !(WIDTH) ? 1 : WIDTH;
	str = ft_strnew(tmp->length);
	ft_memset(str, str_fill(tmp), tmp->length);
	c = !(SPECIFIER(tmp->c)) ? tmp->c : va_arg(list, int);
	i = (WIDTH && !(MINUS)) ? WIDTH - 1 : 0;
	str[i] = (char)c;
	return (str);
}
