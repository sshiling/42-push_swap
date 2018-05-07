/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:26:23 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/25 19:26:24 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_width(char *prefix, char *src, t_res *tmp)
{
	char	*dst;
	int		prefix_len;
	int		len;

	len = ft_strlen(src);
	prefix_len = !(prefix) ? 0 : 2;
	if (WIDTH > len + prefix_len)
	{
		dst = ft_strnew(WIDTH);
		if (filler_finder(tmp) == '0')
			fill_zero_x(prefix, src, dst, tmp);
		else if (MINUS)
			fill_minus_x(prefix, src, dst, tmp);
		else
			fill_space_x(prefix, src, dst, tmp);
	}
	else
	{
		if (prefix)
			dst = ft_strjoin(prefix, src);
		else
			dst = ft_strdup(src);
	}
	return (dst);
}

char	*exceptions_x(char *src, t_res *tmp)
{
	if ((tmp->c == 'x' || tmp->c == 'X') && src[0] == '0' &&
		src[1] == '\0' && !WIDTH && DOT && !PREC)
		return (ft_strdup(""));
	if ((tmp->c == 'x' || tmp->c == 'X') && src[0] == '0' &&
		src[1] == '\0' && !WIDTH && SHARP && !DOT)
		return (ft_strdup("0"));
	if (tmp->c == 'p' && src[0] == '0' && src[1] == '\0' &&
		!WIDTH && DOT && !PREC)
		return (ft_strdup("0x"));
	if (tmp->c == 'p' && src[0] == '0' && src[1] == '\0' &&
		!WIDTH && !DOT)
		return (ft_strdup("0x0"));
	return (NULL);
}

char	*create_x(va_list list, t_res *tmp)
{
	char	*src;
	char	*dst;
	char	*prefix;

	src = ft_itoa_base(mod_int_uox(list, tmp), 16, tmp);
	if ((dst = exceptions_x(src, tmp)) != NULL)
	{
		free(src);
		return (dst);
	}
	if (DOT && !PREC && src[0] == '0' && src[1] == '\0')
		src[0] = ' ';
	prefix = tmp->c == 'X' ? "0X" : "0x";
	prefix = !(SHARP) ? NULL : prefix;
	if (DOT)
		dst = create_precision_x(prefix, src, tmp);
	if (dst)
		dst = create_result_x(dst, tmp);
	else
		dst = create_width(prefix, src, tmp);
	tmp->length = ft_strlen(dst);
	free(src);
	return (dst);
}
