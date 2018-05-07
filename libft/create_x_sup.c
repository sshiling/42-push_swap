/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_x_sup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:51:45 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/22 18:51:47 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_precision_x(char *prefix, char *src, t_res *tmp)
{
	char	*dst;
	int		prefix_len;
	int		len;

	len = ft_strlen(src);
	prefix_len = !(prefix) ? 0 : 2;
	if (PREC > len)
	{
		dst = ft_strnew(PREC + prefix_len);
		ft_memset(dst, '0', PREC + prefix_len);
		if (prefix)
			ft_strncpy(dst, prefix, prefix_len);
		ft_strncpy(&dst[PREC + prefix_len - len], src, len);
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

char	*create_result_x(char *dst, t_res *tmp)
{
	char	*new;

	if (WIDTH <= (int)ft_strlen(dst))
		return (dst);
	new = ft_strnew(WIDTH);
	if (MINUS)
	{
		ft_strncpy(new, dst, ft_strlen(dst));
		ft_memset(&new[ft_strlen(dst)], ' ', WIDTH - ft_strlen(dst));
		free(dst);
	}
	else
	{
		ft_strncpy(&new[WIDTH - ft_strlen(dst)], dst, ft_strlen(dst));
		ft_memset(new, ' ', WIDTH - ft_strlen(dst));
		free(dst);
	}
	return (new);
}

char	*fill_zero_x(char *prefix, char *src, char *dst, t_res *tmp)
{
	char	filler;
	int		prefix_len;
	int		len;

	len = ft_strlen(src);
	filler = filler_finder(tmp);
	prefix_len = !(prefix) ? 0 : 2;
	if (prefix)
		ft_strncpy(dst, prefix, prefix_len);
	ft_strncpy(&dst[WIDTH - len], src, len);
	ft_memset(&dst[prefix_len], filler, WIDTH - (len + prefix_len));
	return (dst);
}

char	*fill_minus_x(char *prefix, char *src, char *dst, t_res *tmp)
{
	char	filler;
	int		prefix_len;
	int		len;

	len = ft_strlen(src);
	filler = filler_finder(tmp);
	prefix_len = !(prefix) ? 0 : 2;
	if (prefix)
		ft_strncpy(dst, prefix, prefix_len);
	ft_strncpy(&dst[prefix_len], src, len);
	ft_memset(&dst[prefix_len + len], filler, WIDTH - len - prefix_len);
	return (dst);
}

char	*fill_space_x(char *prefix, char *src, char *dst, t_res *tmp)
{
	char	filler;
	int		prefix_len;
	int		len;

	len = ft_strlen(src);
	filler = filler_finder(tmp);
	prefix_len = !(prefix) ? 0 : 2;
	ft_memset(dst, filler, WIDTH - len - prefix_len);
	if (prefix)
		ft_strncpy(&dst[WIDTH - len - prefix_len], prefix, prefix_len);
	ft_strncpy(&dst[WIDTH - len], src, len);
	return (dst);
}
