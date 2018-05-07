/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:09:20 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/25 19:09:24 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_create_mid_l(char *src, t_res *tmp, int len)
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

static char	*ft_create_mid_r(char *src, t_res *tmp, int len)
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

static int	find_symbol_o(char *dst)
{
	int i;

	i = 0;
	while (dst[i])
		i++;
	i--;
	while (!NUM(dst[i]))
	{
		if (dst[i] == ' ')
			return (1);
		i--;
	}
	return (0);
}

static char	*upgrade_o(char *pre, char *dst, t_res *tmp)
{
	int		i;
	char	*del;

	i = 0;
	if (SHARP && dst[0] == ' ')
	{
		while (dst[i] && dst[i] == ' ')
			i++;
		if (i != 0 && dst[i] != '0')
			dst[i - 1] = pre[0];
	}
	else if (SHARP && dst[0] != ' ' && dst[0] != '0')
	{
		if (find_symbol_o(dst))
			dst[ft_strlen(dst) - 1] = '\0';
		del = dst;
		dst = ft_strjoin(pre, dst);
		free(del);
	}
	return (dst);
}

char		*create_o(va_list list, t_res *tmp)
{
	char	*src;
	char	*dst;
	char	*pre;
	int		len;

	src = ft_itoa_base(mod_int_uox(list, tmp), 8, tmp);
	if (DOT && !PREC && src[0] == '0')
	{
		free(src);
		src = ft_strdup("");
	}
	len = WIDTH > (int)ft_strlen(src) ? WIDTH : ft_strlen(src);
	len = (int)PREC > len ? (int)PREC : len;
	pre = SHARP == ON ? "0" : "";
	if (MINUS)
		dst = ft_create_mid_l(src, tmp, len);
	else
		dst = ft_create_mid_r(src, tmp, len);
	dst = upgrade_o(pre, dst, tmp);
	free(src);
	tmp->length = ft_strlen(dst);
	return (dst);
}
