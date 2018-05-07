/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:04:48 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/31 20:04:50 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_del(t_stack **stack)
{
	t_stack	*del;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack*)malloc(sizeof(t_stack));
	first->num = 0;
	first->diff = 1;
	first->next = NULL;
	return (first);
}

t_stack	*copy_args_in_stack(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*tmp;

	i = 1;
	first = create_new_node();
	tmp = first;
	while (i < argc)
	{
		if (check_argv(argv[i]))
		{
			stack_del(&first);
			return (NULL);
		}
		tmp->num = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
			tmp->diff = 1;
		}
		i++;
	}
	doubles_checker(&first);
	return (first);
}
