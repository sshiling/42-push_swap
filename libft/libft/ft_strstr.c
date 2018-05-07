/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:07:13 by sshiling          #+#    #+#             */
/*   Updated: 2017/10/30 14:56:52 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		i = 0;
		while (haystack[i] == needle[i] &&
			haystack[i] != '\0' && needle[i] != '\0')
			i++;
		if (needle[i] == '\0')
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
