/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 10:26:52 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/18 19:31:16 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Check_bottom checks to make sure that the piece won't surpass the bottom
** border.
*/

static int	check_bottom(t_piece p, t_puzz l)
{
	int	i;

	i = -1;
	while (++i < 4)
		if ((l.mrow + i >= l.sq_size) && p.r[i] != 0)
			return (0);
	return (1);
}

/*
** Check_border checks to make sure that the piece won't overflow the
** far right border.
*/

static int	check_border(t_piece p, t_puzz l)
{
	int	brd;
	int	i;

	brd = 1 << l.sq_size;
	i = -1;
/*	ft_putstr("Border value:"); //
	ft_putnbr((int)brd);//
	ft_putchar('\n');//
*/	while (++i < 3)
		if (p.r[i] / brd != 0)
			return (0);
	return (1);
}

/*
** Check_zone checks to make sure that the piece doesn't overlap with any
** pieces that have been placed already.
*/

static int	check_zone(t_piece p, t_ull *map, t_puzz l)
{
	int	i;	

	i = -1;
	while (++i < 4)
		if ((p.r[i] & map[l.mrow + i]) != 0)
			return (0);
	return (1);
}

/*
** Check_map calls on the check functions to determine if the piece can be
** placed in this particular location on the map.
*/

int	check_map(t_piece p, t_ull *map, t_puzz l)
{
	int	result;

//	ft_putendl("10 checking if can paste");//
	result = check_zone(p, map, l) * check_border(p, l) * check_bottom(p, l); 
//	if (result == 0)
//		ft_putendl("11 could not paste"); //
	return (result);
}
