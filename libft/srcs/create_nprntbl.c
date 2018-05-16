/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nprntbl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:14:16 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/23 15:14:18 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_nprntbl(va_list list, t_res *tmp)
{
	char	*src;
	char	*dst;
	int		i;

	i = 0;
	src = va_arg(list, char*);
	if (src == NULL)
	{
		src = ft_strdup("null");
		WIDTH = 4;
		return (src);
	}
	dst = ft_strnew(WIDTH);
	while (i < WIDTH)
	{
		dst[i] = src[i];
		i++;
	}
	tmp->length = WIDTH;
	return (dst);
}
