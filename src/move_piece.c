/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 09:51:30 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/22 13:24:41 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Checks to see if the piece values are at the right border of the puzzle.
** if they are, move pieces back to far left as well as increment map
** to the next row.
*/

t_ull	*move_bits(t_piece *p,/* t_ull *map, int eb_nbr,*/ t_puzz l)
{
	int		pu;

	pu = -1;
	while (++pu < l.pnbr)
		if (p[pu].placed != 1)
		{
			if (l.shift >= l.sq_size)
				return (move_next_line(p,/* map, eb_nbr,*/ l));
			else
				return (shift_pieces(p,/* map, eb_nbr,*/ l));
		}
	return (l.map);
}

/*
** Count_empty counts the number of empty blocks in the row
** that was just completed and adds it to the total eb count.
*/

int		count_empty(t_ull row, t_puzz l)
{
	int	reb;
	int	brd;
	int	shift;

	reb = 0;
	brd = 1 << l.sq_size;
	shift = 0;
	while (brd != 1)
	{
		if ((row & 1) == 0)
			reb++;
		shift++;
		row = row >> 1;
		brd = brd >> 1;
	}
	return (reb);
}

/*
** Move to next line is used in move_bits to move map to next line as well
** as move all unused pieces back to their starting values.
*/

t_ull	*move_next_line(t_piece *p,/* t_ull *map, int eb_nbr,*/ t_puzz l)
{
	int		pu;
	int		i;

	pu = -1;
//	eb_nbr += count_empty(map[l.mrow], l);
	while (++pu < l.pnbr)
		if ((p[pu].placed) != 1)
		{
			i = -1;
			while (++i < 4)
				p[pu].r[i] = p[pu].a[i];
		}
	l.shift = 0;
	l.mrow++;
	return (fit_piece/*s*/(p,/* map, eb_nbr,*/ l));
}

/*
** Shift_pieces will move all the pieces horizontally one space so that
** they can be tried against the new pieces. Possibly look for a way to
** tell if the current spot is occupied or not.
*/

t_ull	*shift_pieces(t_piece *p,/* t_ull *map, int eb_nbr,*/ t_puzz l)
{
	int	pu;
	int	i;

	pu = -1;
	while (++pu < l.pnbr)
		if ((p[pu].placed) != 1)
		{
			i = -1;
			while (++i < 4)
				p[pu].r[i] = p[pu].r[i] << 1;
		}
	l.shift++;
	return (fit_piece/*s*/(p,/* map, eb_nbr,*/ l));
}

/*
** Starting_piece returns the starting piece for fit_pieces. If all the
** pieces have been placed then it returns 42 to signal that all pieces
** have been used. Note: it returns pu - 1 because pu is immediatly iterated
** in fit_pieces after this function.
*/

int		starting_piece(t_piece *p, t_puzz l)
{
	int	pu;

	pu = 0;
	while (p[pu].placed == 1)
		if (++pu == l.pnbr)
			return (42);
	return (pu - 1);
}
