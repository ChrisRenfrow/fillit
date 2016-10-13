/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:27:40 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/12 21:15:15 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Checks to see if the piece values are at the right border of the puzzle.
** if they are, move pieces back to far left as well as increment map
** to the next row. NEED TO WORK ON!!! Need a way to keep track of rows
** we have been 
*/

int	g_sq_size;
int	g_shift;		//g_shift is the offset each piece has in the puzzle

t_ull	*move_bits(t_piece *p, t_ull *map, int eb_nbr, int pnbr)
{
	int		pu;
	int		pl;
	t_ull	brd;
	
	brd = ft_power(2, g_sq_size);
	pl = 0;
	pu = 0;
	while (pu < pnbr)
		if (p[pu++].placed != 1)
			pl++;
	while (--pu >= 0)
		if (p[pu].placed != 1)
		{
			if (p[pu].r1 / brd == 1 || p[pu].r2 / brd == 1 || p[pu].r3 / brd == 1)
			{
				if (pl-- == 0)
					return (move_next_line(p, map, eb_nbr, pnbr));
			}
			else
				return (shift_pieces(p, map, eb_nbr, pnbr));
		}
	return (map);
}

/*
** Move to next line is used in move_bits to move map to next line as well
** as move all unused pieces back to their starting values.
*/

t_ull	*move_next_line(t_piece *p, t_ull *map, int eb_nbr, int pnbr)
{
	int	pu;

	pu = 0;
	while (pu < pnbr)
		if (p[pu++].placed != 1)
		{
			p[pu].r1 = p[pu].a1;
			p[pu].r2 = p[pu].a2;
			p[pu].r3 = p[pu].a3;
			p[pu].r4 = p[pu].a4;
			g_shift = 0;
		}
	return (fit_pieces(p, map + 1, eb_nbr, pnbr));
}

/*
** Shift_pieces will move all the pieces horizontally one space so that
** they can be tried against the new pieces. Possibly look for a way to
** tell if the current spot is occupied or not.
*/

t_ull	*shift_pieces(t_piece *p, t_ull *map, int eb_nbr, int pnbr)
{
	int	pu;

	pu = 0;
	while (pu < pnbr)
		if (p[pu++].placed != 1)
		{
			p[pu].r1 = p[pu].r1 << 1;
			p[pu].r2 = p[pu].r2 << 1;
			p[pu].r3 = p[pu].r3 << 1;
			p[pu].r4 = p[pu].r4 << 1;
			g_shift++;
		}
	return (fit_pieces(p, map, eb_nbr, pnbr));
}
