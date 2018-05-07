/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:10:26 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/25 17:10:29 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_create_mid_l(char *src, t_res *tmp, int len)
{
	char	*dst;

	dst = ft_strnew(len);
	ft_memset(dst, ' ', len);
	if (PREC > (int)ft_strlen(src))
	{
		ft_memset(dst, '0', PREC);
		ft_strncpy(&dst[PREC - ft_strlen(src)], src, ft_strlen(src));
	}
	else
		ft_strncpy(dst, src, ft_strlen(src));
	return (dst);
}

static char		*ft_create_mid_r(char *src, t_res *tmp, int len)
{
	char	filler;
	char	*dst;

	filler = filler_finder(tmp);
	dst = ft_strnew(len);
	ft_memset(dst, filler, len);
	ft_memset(&dst[len - PREC], '0', PREC);
	ft_strncpy(&dst[len - ft_strlen(src)], src, ft_strlen(src));
	return (dst);
}

char			*create_u(va_list list, t_res *tmp)
{
	char	*src;
	char	*dst;
	int		len;

	src = ft_itoa_base(mod_int_uox(list, tmp), 10, tmp);
	if (DOT && !PREC && src[0] == '0')
	{
		free(src);
		src = ft_strdup("");
	}
	len = WIDTH > (int)ft_strlen(src) ? WIDTH : ft_strlen(src);
	len = (int)PREC > len ? (int)PREC : len;
	if (MINUS)
		dst = ft_create_mid_l(src, tmp, len);
	else
		dst = ft_create_mid_r(src, tmp, len);
	free(src);
	tmp->length = ft_strlen(dst);
	return (dst);
}
