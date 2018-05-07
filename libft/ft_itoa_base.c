/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:14:10 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/25 19:14:12 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(size_t nb, int base, t_res *tmp)
{
	char	*result;
	char	mod;
	size_t	n;
	int		i;

	n = nb;
	i = nb == 0 ? 1 : 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	mod = tmp->c == 'X' ? 'A' : 'a';
	result = ft_strnew(i);
	result[i] = '\0';
	while (i > 0)
	{
		if (nb % base < 10)
			result[i - 1] = nb % base + '0';
		else
			result[i - 1] = nb % base - 10 + mod;
		nb = nb / base;
		i--;
	}
	return (result);
}
