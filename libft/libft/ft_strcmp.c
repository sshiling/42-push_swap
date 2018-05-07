/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:06:54 by sshiling          #+#    #+#             */
/*   Updated: 2017/10/30 16:15:42 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char*)s1;
	z2 = (unsigned char*)s2;
	if (*z1 == '\0')
		return (-(*z2));
	if (*z2 == '\0')
		return (*z1);
	while (*z1 != '\0' || *z2 != '\0')
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
	}
	return (0);
}
