/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:49:18 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/04 13:51:28 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_lst;
	t_list	*result;
	t_list	*tmp;

	if (lst != NULL)
	{
		tmp_lst = lst;
		result = f(ft_lstnew(lst->content, lst->content_size));
		tmp_lst = tmp_lst->next;
		tmp = result;
		while (tmp_lst != NULL)
		{
			tmp->next = f(ft_lstnew(tmp_lst->content, tmp_lst->content_size));
			tmp = tmp->next;
			tmp_lst = tmp_lst->next;
		}
		return (result);
	}
	return (NULL);
}
