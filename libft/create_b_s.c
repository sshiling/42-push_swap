/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_b_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:34:57 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/10 19:34:59 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	filler_finder_s(t_res *tmp)
{
	if (!MINUS && ZERO)
		return ('0');
	return (' ');
}

static char	*add_width(char *dst, t_res *tmp)
{
	char	filler;
	char	*new;

	filler = filler_finder_s(tmp);
	if (WIDTH > (int)ft_strlen(dst))
	{
		new = ft_strnew(WIDTH);
		ft_memset(new, filler, WIDTH);
		if (MINUS)
			ft_strncpy(new, dst, ft_strlen(dst));
		else
			ft_strncpy(&new[WIDTH - ft_strlen(dst)], dst, ft_strlen(dst));
		tmp->length = ft_strlen(new);
		free(dst);
		return (new);
	}
	return (dst);
}

static char	*dst_creator(int *val, char *src, char *dst, t_res *tmp)
{
	char	*del;
	int		i;

	i = 0;
	while (val[i])
	{
		src = ft_itoa_base(val[i], 2, tmp);
		del = src;
		src = fill_mask(dst, src, (ft_strlen(src) - 1));
		free(del);
		if (!DOT || (DOT && PREC >= (int)(ft_strlen(dst) + ft_strlen(src))))
		{
			del = dst;
			dst = ft_strjoin(dst, src);
			free(del);
			free(src);
		}
		else
		{
			free(src);
			break ;
		}
		i++;
	}
	return (dst);
}

char		*create_b_s(va_list list, t_res *tmp)
{
	char	*src;
	char	*dst;
	int		*val;

	src = NULL;
	dst = ft_strdup("\0");
	if (!(val = va_arg(list, void*)))
	{
		free(dst);
		return (ft_strdup("(null)"));
	}
	dst = dst_creator(val, src, dst, tmp);
	dst = add_width(dst, tmp);
	tmp->length = ft_strlen(dst);
	return (dst);
}
