/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:49:42 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/01 17:37:51 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*result;

	i = 0;
	ch = (unsigned char)c;
	result = (unsigned char*)s;
	while (i < n)
	{
		if (result[i] == ch)
			return (&result[i]);
		i++;
	}
	result = NULL;
	return (result);
}
