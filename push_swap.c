/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:08:01 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/12 20:08:03 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_three(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num && (*stack)->next->num <
		(*stack)->next->next->num)
		return ;
	if ((*stack)->num > (*stack)->next->num && (*stack)->next->num <
		(*stack)->next->next->num &&
		(*stack)->num < (*stack)->next->next->num)
		ft_printf("sa\n");
	else if ((*stack)->num < (*stack)->next->num && (*stack)->next->num >
		(*stack)->next->next->num &&
		(*stack)->num < (*stack)->next->next->num)
		ft_printf("rra\nsa\n");
	else if ((*stack)->num > (*stack)->next->num && (*stack)->num >
		(*stack)->next->next->num &&
		(*stack)->next->num < (*stack)->next->next->num)
		ft_printf("ra\n");
	else if ((*stack)->num < (*stack)->next->num && (*stack)->num >
		(*stack)->next->next->num &&
		(*stack)->next->num > (*stack)->next->next->num)
		ft_printf("rra\n");
	else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num >
		(*stack)->next->next->num)
		ft_printf("ra\nsa\n");
}

void		short_sort(t_stack **stack, int len)
{
	if (len == 1)
		return ;
	if (len == 2 && (*stack)->num > (*stack)->next->num)
		ft_printf("sa\n");
	if (len == 3)
		do_three(stack);
	return ;
}

void		sort_stacks(t_stack **stack1, t_stack **stack2, t_com **result,
	int len)
{
	int		rot;

	if (len == 2 || len == 3)
		return ;
	if ((*stack1)->diff == 1)
		rot = div_stack_a(stack1, stack2, result, len);
	else
		rot = div_stack_b(stack1, stack2, result, len);
	if ((*result)->rotator == 1)
		rotate_back(stack1, result, rot);
	if ((*stack1)->diff == 1 && (len / 2 == 3 || len / 2 == 2))
		swap_elements(stack1, stack2, result, len);
	else if ((*stack1)->diff == 2 && (len / 2 == 3 || len / 2 == 2))
		swap_elements(stack1, stack2, result, len);
	sort_stacks(stack1, stack2, result, (*stack1)->diff != 1 ?
		len / 2 : len - len / 2);
	sort_stacks(stack2, stack1, result, (*stack1)->diff == 1 ?
		len / 2 : len - len / 2);
	if ((*stack1)->diff == 1)
		push_back(stack1, stack2, result, len / 2);
	else
		push_back(stack1, stack2, result, len - len / 2);
}

int			main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;
	t_com	*result;
	int		len;

	if (!(stack1 = copy_args_in_stack(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	len = s_len(stack1);
	stack2 = NULL;
	result = new_result();
	if (len < 4)
	{
		short_sort(&stack1, len);
		stack_del(&stack1);
		return (0);
	}
	else
		sort_stacks(&stack1, &stack2, &result, len);
	print_final_result(result->final);
	stack_del(&stack1);
	free(result);
	return (0);
}
