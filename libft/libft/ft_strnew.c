/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:49:18 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/02 16:49:47 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char*)malloc(sizeof(char) * (size + 1));
	if (string == NULL)
		return (NULL);
	ft_bzero(string, (size + 1));
	return (string);
}
