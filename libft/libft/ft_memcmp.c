/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:43:10 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/04 15:48:10 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char*)s1;
	z2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
		n--;
	}
	return (0);
}
