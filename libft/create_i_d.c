/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_i_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:46:30 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/16 11:46:34 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*do_str_shorter(char *dst)
{
	int i;

	i = 0;
	while (dst[i])
		i++;
	i--;
	if (!(NUM(dst[0])) && dst[i] == ' ')
		dst[i] = '\0';
	return (dst);
}

static char	*add_prefix(char *prefix, char *dst, t_res *tmp)
{
	char	*del;
	int		i;

	i = 0;
	if (prefix)
	{
		if ((dst[i] == '0' && dst[ft_strlen(dst) - 1] == ' ') ||
			(NUM(dst[i]) && dst[i] != '0') || PREC ==
			(int)ft_strlen(dst) || (dst[i] == '0' && dst[i + 1] == '\0'))
		{
			del = dst;
			dst = ft_strjoin(prefix, dst);
			free(del);
		}
		else if (dst[i] == '0')
			ft_strncpy(&dst[i], prefix, 1);
		else
		{
			while (!NUM(dst[i]))
				i++;
			ft_strncpy(&dst[i - 1], prefix, 1);
		}
	}
	return (dst);
}

static char	*null_exception_i_d(int len)
{
	char	*new;

	new = ft_strnew(len);
	ft_memset(new, ' ', len);
	return (new);
}

static char	*exceptions_i_d(char *src, t_res *tmp)
{
	if (DOT && !PREC && !WIDTH && src[0] == '0')
	{
		free(src);
		return (ft_strdup(""));
	}
	if (DOT && !PREC && src[0] == '0')
	{
		free(src);
		return (null_exception_i_d(WIDTH));
	}
	return (NULL);
}

char		*create_i_d(va_list list, t_res *tmp)
{
	char	*src;
	char	*dst;
	char	*del;
	int		len;
	int		key;

	src = ft_itoa_max(mod_int_i_d(list, tmp));
	del = src;
	key = src[0] == '-' ? -1 : 1;
	src = src[0] == '-' ? &src[1] : src;
	len = WIDTH >= (int)ft_strlen(src) ? WIDTH : ft_strlen(src);
	len = (int)PREC >= len ? (int)PREC : len;
	if ((dst = exceptions_i_d(src, tmp)) != NULL)
		return (dst);
	if (MINUS)
		dst = num_first_i_d(len, src, tmp);
	else
		dst = num_after_i_d(len, src, tmp);
	free(del);
	dst = do_str_shorter(add_prefix(find_prefix_i_d(key, tmp), dst, tmp));
	tmp->length = ft_strlen(dst);
	return (dst);
}
