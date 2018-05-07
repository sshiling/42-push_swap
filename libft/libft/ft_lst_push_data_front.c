/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_data_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:14:29 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/09 12:14:33 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_data_front(t_list **alst,
	void const *content, size_t content_size)
{
	t_list	*new;

	if (!(*alst))
		return ;
	new = ft_lstnew(content, content_size);
	if (!new)
		return ;
	ft_lstadd(alst, new);
}
