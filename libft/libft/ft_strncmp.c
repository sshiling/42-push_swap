/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:18:18 by sshiling          #+#    #+#             */
/*   Updated: 2017/10/30 16:27:12 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char*)s1;
	z2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	if (*z1 == '\0')
		return (-(*z2));
	if (*z2 == '\0')
		return (*z1);
	while (z1[i] != '\0' || z2[i] != '\0')
	{
		if (i == n - 1 || z1[i] != z2[i])
			return (z1[i] - z2[i]);
		i++;
	}
	return (z1[i] - z2[i]);
}
