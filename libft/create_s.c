/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 13:21:07 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/28 13:21:10 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	filler_finder_s(t_res *tmp)
{
	if (MINUS)
		return (' ');
	if (ZERO)
		return ('0');
	return (' ');
}

static char	*fill_minus(char *src, int len, t_res *tmp)
{
	char	*dst;
	char	filler;
	int		size;

	size = (int)WIDTH >= len ? (int)WIDTH : len;
	dst = ft_strnew(size);
	filler = filler_finder_s(tmp);
	dst = ft_strncpy(dst, src, len);
	ft_memset(&dst[len], filler, size - len);
	tmp->length = ft_strlen(dst);
	return (dst);
}

static char	*fill_first(char *src, int len, t_res *tmp)
{
	char	*dst;
	char	filler;
	int		size;

	size = (int)WIDTH >= len ? (int)WIDTH : len;
	dst = ft_strnew(size);
	filler = filler_finder_s(tmp);
	ft_memset(dst, filler, size - len);
	ft_strncpy(&dst[size - len], src, len);
	tmp->length = ft_strlen(dst);
	return (dst);
}

char		*change_case(char *src, t_res *tmp)
{
	int		i;

	i = 0;
	if (UPPER)
	{
		while (src[i])
		{
			src[i] = ft_toupper(src[i]);
			i++;
		}
	}
	else
	{
		while (src[i])
		{
			src[i] = ft_tolower(src[i]);
			i++;
		}
	}
	return (src);
}

char		*create_s(va_list list, t_res *tmp)
{
	char	*src;
	int		len;
	int		fin_len;

	src = va_arg(list, char*);
	if (src == NULL)
		src = "(null)";
	len = ft_strlen(src);
	fin_len = DOT == ON ? PREC : len;
	fin_len = fin_len >= len ? len : fin_len;
	if (MINUS)
		src = fill_minus(src, fin_len, tmp);
	else
		src = fill_first(src, fin_len, tmp);
	if (LOWER || UPPER)
		src = change_case(src, tmp);
	return (src);
}
