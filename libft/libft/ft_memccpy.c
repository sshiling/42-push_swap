/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:47:15 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/02 14:29:44 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	ch;

	i = 0;
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		s1[i] = s2[i];
		dst++;
		if (s2[i] == ch)
			return (dst);
		i++;
	}
	return (0);
}
