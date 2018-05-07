/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:35:25 by sshiling          #+#    #+#             */
/*   Updated: 2017/12/22 14:35:28 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	func_pdou(va_list list, t_res *tmp)
{
	if (tmp->c == 'p')
	{
		SHARP = ON;
		MOD_Z = ON;
		tmp->result = create_x(list, tmp);
	}
	if (tmp->c == 'D')
	{
		MOD_L = ON;
		tmp->result = create_i_d(list, tmp);
	}
	if (tmp->c == 'O')
	{
		MOD_L = ON;
		tmp->result = create_o(list, tmp);
	}
	if (tmp->c == 'U')
	{
		MOD_L = ON;
		tmp->result = create_u(list, tmp);
	}
}

static void	func_ints(va_list list, t_res *tmp)
{
	if (tmp->c == 'd' || tmp->c == 'i')
		tmp->result = create_i_d(list, tmp);
	if (tmp->c == 'o')
		tmp->result = create_o(list, tmp);
	if (tmp->c == 'u')
		tmp->result = create_u(list, tmp);
	if (tmp->c == 'x' || tmp->c == 'X')
		tmp->result = create_x(list, tmp);
}

static void	func_finder(va_list list, t_res *tmp)
{
	if (tmp->c == 'c' && !(MOD_L))
		tmp->result = create_c(list, tmp);
	if (tmp->c == 'C' || (tmp->c == 'c' && MOD_L))
		tmp->result = create_b_c(list, tmp);
	if (tmp->c == 's' && !(MOD_L))
		tmp->result = create_s(list, tmp);
	if (tmp->c == 'S' || (tmp->c == 's' && MOD_L))
		tmp->result = create_b_s(list, tmp);
	if (tmp->c == 'p' || tmp->c == 'D' || tmp->c == 'O' || tmp->c == 'U')
		func_pdou(list, tmp);
	if (tmp->c == 'd' || tmp->c == 'i' || tmp->c == 'o' || tmp->c == 'u' ||
		tmp->c == 'x' || tmp->c == 'X')
		func_ints(list, tmp);
	if (tmp->c == 'n')
		tmp->result = create_n(list, tmp);
	if (tmp->c == 'b')
		tmp->result = create_binary(list, tmp);
	if (tmp->c == 'w')
		g_fd = va_arg(list, int);
	if (tmp->c == 'm')
		g_fd = 2;
}

void		result_creator(va_list list, t_res *tmp)
{
	if (SPECIFIER(tmp->c))
		func_finder(list, tmp);
	else
		tmp->result = create_c(list, tmp);
}
