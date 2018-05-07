/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:32:48 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/01 18:44:15 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*z1;
	char	*z2;

	i = 0;
	j = 0;
	z1 = (char*)s1;
	z2 = (char*)s2;
	while (z1[i] != '\0')
		i++;
	if (n > ft_strlen(z2))
		n = ft_strlen(z2);
	while (n > 0)
	{
		z1[i] = z2[j];
		i++;
		j++;
		n--;
	}
	z1[i] = '\0';
	return (s1);
}
