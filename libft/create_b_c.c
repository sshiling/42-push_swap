/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_b_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:42:00 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/10 12:42:03 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pow(int nb, int power)
{
	int rengers;

	rengers = nb;
	if (power < 0)
		rengers = 0;
	if (power > 0)
	{
		while (power > 1)
		{
			rengers = rengers * nb;
			power--;
		}
	}
	if (power == 0)
		rengers = 1;
	return (rengers);
}

char	make_num_from_bi(char *src, int len)
{
	int		rem;
	int		sum;
	int		power;

	rem = 0;
	sum = 0;
	power = 0;
	len--;
	while (len >= 0)
	{
		rem = (src[len] - '0') % 10;
		len--;
		sum = sum + rem * ft_pow(2, power);
		power++;
	}
	return (sum);
}

char	*find_mask(int len)
{
	if (len <= 7)
		return ("0xxxxxxx");
	if (len <= 11)
		return ("110xxxxx10xxxxxx");
	if (len > 11 && len <= 16)
		return ("1110xxxx10xxxxxx10xxxxxx");
	else
		return ("11110xxx10xxxxxx10xxxxxx10xxxxxx");
}

char	*fill_mask(char *dst, char *src, int len)
{
	char	*tmp;
	int		i;

	dst = ft_strnew(4);
	tmp = ft_strdup(find_mask(len + 1));
	i = ft_strlen(tmp) - 1;
	while (i >= 0)
	{
		if (tmp[i] == 'x' && len >= 0)
		{
			tmp[i] = src[len];
			len--;
		}
		else if (tmp[i] == 'x' && len < 0)
			tmp[i] = '0';
		i--;
	}
	while (++i < (int)ft_strlen(tmp) / 8)
		dst[i] = make_num_from_bi(&tmp[i * 8], 8);
	free(tmp);
	return (dst);
}

char	*create_b_c(va_list list, t_res *tmp)
{
	char	*src;
	char	*dst;

	dst = NULL;
	src = ft_itoa_base(va_arg(list, int), 2, tmp);
	if (src[0] == '0' && src[1] == '\0')
	{
		tmp->length = 1;
		free(src);
		return (ft_strdup("\0"));
	}
	dst = fill_mask(dst, src, (ft_strlen(src) - 1));
	tmp->length = ft_strlen(dst);
	free(src);
	return (dst);
}
