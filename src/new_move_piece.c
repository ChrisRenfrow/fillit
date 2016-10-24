/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_move_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:51:31 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/24 11:29:00 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Checks to see if the piece values are at the right border of the puzzle.
** if they are, move pieces back to far left as well as increment map
** to the next row.
*/

t_puzz	*move_piece(t_piece *p, t_puzz *l)
{
	int i;

	i = -1;
	if (l->shift >= l->sq_size)
	{
		while (++i < 4)
			p[l->pu].r[i] = p[l->pu].a[i];
		l->shift = 0;
		l->mrow++;
	}
	else
	{
		while (++i < 4)
			p[l->pu].r[i] = p[l->pu].r[i] << 1;
			l->shift++;
	}
	p[l->pu].mrow = l->mrow;
	p[l->pu].shift = l->shift;
	return (fit_piece(p, l));
}
/*
** Move to next line is used in move_bits to move map to next line as well
** as move all unused pieces back to their starting values.
/

t_ull	*move_next_line(t_piece *p, t_puzz l)
{
	int		pu;
	int		i;

		if ((p[l.pu].placed) != 1)
		{
			i = -1;
		}
	l.shift = 0;
	l.mrow++;
	return (fit_piece(p, l));
}

*
** Shift_pieces will move all the pieces horizontally one space so that
** they can be tried against the new pieces. Possibly look for a way to
** tell if the current spot is occupied or not.
/

t_ull	*shift_pieces(t_piece *p, t_puzz l)
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
	return (fit_piece(p, l));
}
*/
