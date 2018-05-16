/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:48:17 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/15 18:48:19 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_rotator(t_stack **stack, t_com **result, int rot)
{
	rab(stack);
	if ((*stack)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "ra\n");
	else
		(*result)->final = add_to_string((*result)->final, "rb\n");
	rot++;
	return (rot);
}

static int	stack_pusher(t_stack **stack1, t_stack **stack2,
	t_com **result, int half)
{
	(*stack1)->diff = (*stack1)->diff == 1 ? 2 : 1;
	pab(stack2, stack1);
	if ((*stack1)->diff == 1)
		(*result)->final = add_to_string((*result)->final, "pb\n");
	else
		(*result)->final = add_to_string((*result)->final, "pa\n");
	half--;
	return (half);
}

int			div_stack_a(t_stack **stack1, t_stack **stack2,
	t_com **result, int len)
{
	int		rot;
	int		mid;
	t_stack	*tmp;
	int		half;

	half = len / 2;
	tmp = *stack1;
	rot = 0;
	mid = find_mid_value(*stack1, len);
	while (tmp && half >= 0)
	{
		if (((*stack1)->diff == 1 && tmp->num < mid) ||
			((*stack1)->diff == 2 && tmp->num <= mid))
		{
			while ((*stack1)->num != tmp->num)
				rot = stack_rotator(stack1, result, rot);
			tmp = tmp->next;
			half = stack_pusher(stack1, stack2, result, half);
		}
		else
			tmp = tmp->next;
	}
	return (rot);
}

int			div_stack_b(t_stack **stack1, t_stack **stack2,
	t_com **result, int len)
{
	int		rot;
	int		mid;
	t_stack	*tmp;
	int		half;

	half = len - len / 2;
	tmp = *stack1;
	rot = 0;
	mid = find_mid_value(*stack1, len);
	while (tmp && half > 0)
	{
		if (((*stack1)->diff == 1 && tmp->num > mid) ||
			((*stack1)->diff == 2 && tmp->num >= mid))
		{
			while ((*stack1)->num != tmp->num)
				rot = stack_rotator(stack1, result, rot);
			tmp = tmp->next;
			half = stack_pusher(stack1, stack2, result, half);
		}
		else
			tmp = tmp->next;
	}
	return (rot);
}
