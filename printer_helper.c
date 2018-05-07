/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:56:27 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/20 20:56:30 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_pa_pb(char **origin, char **res, int i)
{
	int		pa;
	int		pb;
	int		x;

	pa = 0;
	pb = 0;
	x = 0;
	while (origin[i] && (ft_strequ(origin[i], "pa") ||
		ft_strequ(origin[i], "pb")))
	{
		if (ft_strequ(origin[i], "pa"))
			pa++;
		if (ft_strequ(origin[i], "pb"))
			pb++;
		i++;
	}
	x = pa > pb ? pa - pb : 0;
	while (x-- > 0)
		*res = add_to_string(*res, "pa\n");
	x = pa < pb ? pb - pa : 0;
	while (x-- > 0)
		*res = add_to_string(*res, "pb\n");
	return (i);
}

int	add_ra_rra(char **origin, char **res, int i)
{
	int		ra;
	int		rra;
	int		x;

	ra = 0;
	rra = 0;
	x = 0;
	while (origin[i] && (ft_strequ(origin[i], "ra") ||
		ft_strequ(origin[i], "rra")))
	{
		if (ft_strequ(origin[i], "ra"))
			ra++;
		if (ft_strequ(origin[i], "rra"))
			rra++;
		i++;
	}
	x = ra > rra ? ra - rra : 0;
	while (x-- > 0)
		*res = add_to_string(*res, "ra\n");
	x = ra < rra ? rra - ra : 0;
	while (x-- > 0)
		*res = add_to_string(*res, "rra\n");
	return (i);
}

int	add_rb_rrb(char **origin, char **res, int i)
{
	int		rb;
	int		rrb;
	int		x;

	rb = 0;
	rrb = 0;
	x = 0;
	while (origin[i] && (ft_strequ(origin[i], "rb") ||
		ft_strequ(origin[i], "rrb")))
	{
		if (ft_strequ(origin[i], "rb"))
			rb++;
		if (ft_strequ(origin[i], "rrb"))
			rrb++;
		i++;
	}
	x = rb > rrb ? rb - rrb : 0;
	while (x-- > 0)
		*res = add_to_string(*res, "rb\n");
	x = rb < rrb ? rrb - rb : 0;
	while (x-- > 0)
		*res = add_to_string(*res, "rrb\n");
	return (i);
}

int	add_others(char **tmp, char **res, int i)
{
	while (tmp[i] && !(ft_strequ(tmp[i], "pa") || ft_strequ(tmp[i], "pb") ||
		ft_strequ(tmp[i], "ra") || ft_strequ(tmp[i], "rb") ||
		ft_strequ(tmp[i], "rra") || ft_strequ(tmp[i], "rrb")))
	{
		*res = add_to_string(*res, tmp[i]);
		*res = add_to_string(*res, "\n");
		i++;
	}
	return (i);
}
