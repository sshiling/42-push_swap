/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:56:08 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/15 18:56:10 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_a_creator(t_stack **stack1, t_com **result, int len)
{
	int		res;

	if ((*stack1)->diff == 1)
	{
		(*result)->rotator = 1;
		res = len - len / 2;
	}
	else
		res = len / 2;
	return (res);
}

static int	len_b_creator(t_stack **stack1, t_com **result, int len)
{
	int		res;

	if ((*stack1)->diff == 1)
	{
		(*result)->rotator = 1;
		res = len / 2;
	}
	else
		res = len - len / 2;
	return (res);
}

static void	swap_for_len1_two(t_stack **stack1, t_stack **stack2,
	t_com **result, int len)
{
	int		len_1;
	int		len_2;

	len_1 = len_a_creator(stack1, result, len);
	len_2 = len_b_creator(stack1, result, len);
	if (len_1 == 2 && (!(*stack1) || s_len(*stack1) < 2))
		return ;
	else if (len_1 == 2 && (!(*stack2) || s_len(*stack2) < 2 || len_2 > 3))
		swap_two(stack1, result);
	else if (len_1 == 2 && len_2 == 2)
	{
		swap_two(stack1, result);
		swap_two(stack2, result);
	}
	else if (len_1 == 2 && len_2 == 3 && s_len(*stack2) > 2)
	{
		swap_two(stack1, result);
		swap_three(stack2, result);
	}
}

static void	swap_for_len1_three(t_stack **stack1, t_stack **stack2,
	t_com **result, int len)
{
	int		len_1;
	int		len_2;

	len_1 = len_a_creator(stack1, result, len);
	len_2 = len_b_creator(stack1, result, len);
	if (len_1 > 3 && len_2 == 2)
		swap_two(stack2, result);
	else if (len_1 == 3 && (!(*stack1) || s_len(*stack1) < 3))
		return ;
	else if (len_1 == 3 && (!(*stack2) || s_len(*stack2) < 2 || len_2 > 3))
		swap_three(stack1, result);
	else if (len_1 == 3 && len_2 == 2)
	{
		swap_three(stack1, result);
		swap_two(stack2, result);
	}
	else if (len_1 == 3 && len_2 == 3 && s_len(*stack2) > 2)
	{
		swap_three(stack1, result);
		swap_three(stack2, result);
	}
	else if (len_1 > 3 && len_2 == 3)
		swap_three(stack2, result);
}

void		swap_elements(t_stack **stack1, t_stack **stack2,
	t_com **result, int len)
{
	int		len_1;

	len_1 = len_a_creator(stack1, result, len);
	if (len_1 == 2)
		swap_for_len1_two(stack1, stack2, result, len);
	else if (len_1 > 2)
		swap_for_len1_three(stack1, stack2, result, len);
}
