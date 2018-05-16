/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:47:12 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/03 15:50:42 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_min_max(int n)
{
	char	*result;
	int		i;

	i = 9;
	result = (char*)malloc(sizeof(char) * 12);
	if (result == NULL)
		return (NULL);
	result[11] = '\0';
	result[10] = '8';
	n = n / 10;
	n = -n;
	while (i > 0)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	result[i] = '-';
	return (result);
}

static char	*do_negative(int n)
{
	char	*result;
	int		nb;
	int		i;

	n = -n;
	nb = n;
	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	result = (char*)malloc(sizeof(char) * (i + 2));
	if (result == NULL)
		return (NULL);
	result[i + 1] = '\0';
	while (i > 0)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	result[i] = '-';
	return (result);
}

static char	*do_positive(int n)
{
	char	*result;
	int		nb;
	int		i;

	nb = n;
	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	result = (char*)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	while (i > 0)
	{
		result[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (result);
}

static char	*do_null(void)
{
	char	*result;

	result = (char*)malloc(sizeof(char) * 2);
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char		*ft_itoa(int n)
{
	if (n == -2147483648)
		return (do_min_max(n));
	if (n < 0)
		return (do_negative(n));
	if (n > 0)
		return (do_positive(n));
	return (do_null());
}
