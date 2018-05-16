/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:16:55 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/15 19:16:57 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_three_a(t_stack **stack, t_com **res)
{
	if ((*stack)->num < (*stack)->next->num &&
		(*stack)->next->num < (*stack)->next->next->num)
		return ;
	if ((*stack)->num > (*stack)->next->num &&
		(*stack)->next->num < (*stack)->next->next->num &&
		(*stack)->num < (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_1(stack, res) : swap_two(stack, res);
	else if ((*stack)->num < (*stack)->next->num &&
		(*stack)->next->num > (*stack)->next->next->num &&
			(*stack)->num < (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_2(stack, res) : comb_6(stack, res);
	else if ((*stack)->num > (*stack)->next->num &&
		(*stack)->num > (*stack)->next->next->num &&
			(*stack)->next->num < (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_3(stack, res) : comb_7(stack, res);
	else if ((*stack)->num < (*stack)->next->num &&
		(*stack)->num > (*stack)->next->next->num &&
			(*stack)->next->num > (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_4(stack, res) : comb_8(stack, res);
	else if ((*stack)->num > (*stack)->next->num &&
		(*stack)->next->num > (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_5(stack, res) : comb_9(stack, res);
}

void	swap_three_b(t_stack **stack, t_com **res)
{
	if ((*stack)->num > (*stack)->next->num &&
		(*stack)->next->num > (*stack)->next->next->num)
		return ;
	else if ((*stack)->num < (*stack)->next->num &&
		(*stack)->num > (*stack)->next->next->num &&
			(*stack)->next->num > (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_1(stack, res) : swap_two(stack, res);
	else if ((*stack)->num > (*stack)->next->num &&
		(*stack)->num > (*stack)->next->next->num &&
			(*stack)->next->num < (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_2(stack, res) : comb_6(stack, res);
	else if ((*stack)->num < (*stack)->next->num &&
		(*stack)->next->num > (*stack)->next->next->num &&
			(*stack)->num < (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_3(stack, res) : comb_7(stack, res);
	else if ((*stack)->num > (*stack)->next->num &&
		(*stack)->next->num < (*stack)->next->next->num &&
			(*stack)->num < (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_4(stack, res) : comb_8(stack, res);
	else if ((*stack)->num < (*stack)->next->num &&
		(*stack)->next->num < (*stack)->next->next->num)
		s_len(*stack) > 3 ? comb_5(stack, res) : comb_9(stack, res);
}

void	swap_three(t_stack **stack, t_com **result)
{
	if ((*stack)->diff == 1)
		swap_three_a(stack, result);
	else
		swap_three_b(stack, result);
}

void	swap_two(t_stack **stack, t_com **result)
{
	if ((*stack)->diff == 1 && ((*stack)->num > (*stack)->next->num))
	{
		sab(stack);
		(*result)->final = add_to_string((*result)->final, "sa\n");
	}
	else if ((*stack)->diff == 2 && ((*stack)->num < (*stack)->next->num))
	{
		sab(stack);
		(*result)->final = add_to_string((*result)->final, "sb\n");
	}
}
