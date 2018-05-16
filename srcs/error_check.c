/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:34:14 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/20 15:34:16 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doubles_checker(t_stack **stack)
{
	int		*array;
	int		len;
	int		i;

	i = 0;
	len = s_len(*stack);
	array = create_array_from_list(*stack, len);
	quick_sort(array, 0, len - 1);
	while (i < len - 1)
	{
		if (array[i] >= array[i + 1])
		{
			stack_del(stack);
			free(array);
			return ;
		}
		i++;
	}
	free(array);
}

int		check_int_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int		check_argv(char *str)
{
	int		i;
	int		len;

	i = 0;
	if (str[i] == '-' && !NUM(str[i + 1]))
		return (1);
	if (str[i] == '-' && NUM(str[i + 1]))
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10)
		return (1);
	while (str[i])
	{
		if (!NUM(str[i]))
			return (1);
		i++;
	}
	if (len == 10 && check_int_overflow(str))
		return (1);
	return (0);
}
