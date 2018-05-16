/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:15:01 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/09 12:15:04 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size(t_list **alst)
{
	int		n;
	t_list	*list;

	if (!(*alst))
		return (0);
	n = 0;
	list = *alst;
	while (list)
	{
		list = list->next;
		n++;
	}
	return (n);
}
