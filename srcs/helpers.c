/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:54:45 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/15 18:54:48 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*add_to_string(char *to, char *add)
{
	char *del;

	del = to;
	to = ft_strjoin(to, add);
	ft_strdel(&del);
	return (to);
}

int		*create_array_from_list(t_stack *stack, int len)
{
	int		*array;
	int		i;

	array = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		array[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (array);
}

t_com	*new_result(void)
{
	t_com	*new;
	int		i;

	i = 0;
	new = (t_com*)malloc(sizeof(t_com));
	new->rotator = 0;
	new->final = ft_strdup("\0");
	return (new);
}

int		find_mid_value(t_stack *stack, int len)
{
	int		*array;
	int		mid_value;

	len = s_len(stack) < len ? s_len(stack) : len;
	array = create_array_from_list(stack, len);
	quick_sort(array, 0, len - 1);
	mid_value = array[len / 2];
	free(array);
	return (mid_value);
}

int		s_len(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
