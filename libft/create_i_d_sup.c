/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_i_d_sup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:23:04 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/22 18:23:06 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	mod_int_i_d(va_list list, t_res *tmp)
{
	if (MOD_Z)
		return ((ssize_t)(va_arg(list, ssize_t)));
	else if (MOD_J)
		return ((intmax_t)(va_arg(list, ssize_t)));
	else if (MOD_LL)
		return ((long long int)(va_arg(list, ssize_t)));
	else if (MOD_L)
		return ((long int)(va_arg(list, ssize_t)));
	else if (MOD_H)
		return ((short int)(va_arg(list, ssize_t)));
	else if (MOD_HH)
		return ((signed char)(va_arg(list, ssize_t)));
	else
		return (int)(va_arg(list, ssize_t));
}

char	*find_prefix_i_d(int key, t_res *tmp)
{
	if (key < 0)
		return ("-");
	else if (PLUS)
		return ("+");
	else if (SPACE)
		return (" ");
	return (NULL);
}

char	*num_first_i_d(int len, char *src, t_res *tmp)
{
	char	*dst;
	int		i;

	i = ft_strlen(src);
	dst = ft_strnew(len);
	ft_memset(dst, ' ', len);
	ft_memset(dst, '0', PREC);
	if ((int)PREC > i)
		ft_strncpy(&dst[PREC - i], src, i);
	else
		ft_strncpy(dst, src, i);
	return (dst);
}

char	filler_finder(t_res *tmp)
{
	if (!DOT && !MINUS && ZERO)
		return ('0');
	return (' ');
}

char	*num_after_i_d(int len, char *src, t_res *tmp)
{
	char	*dst;
	int		i;

	i = ft_strlen(src);
	dst = ft_strnew(len);
	ft_memset(dst, filler_finder(tmp), len);
	ft_memset(&dst[len - PREC], '0', PREC);
	ft_strncpy(&dst[len - i], src, i);
	return (dst);
}
