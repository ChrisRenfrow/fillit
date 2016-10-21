/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:29:43 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/20 17:32:59 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Edit_map will either cut or paste a piece depending on the status.
** status = 1 indicates that the piece was  pasted into the map.
** status = 0 indicates that the piece was cut from the map.
*/

t_piece		edit_map(t_piece p, t_ull *map, t_puzz l, int status)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		map[l.mrow + i] = p.r[i] ^ map[l.mrow + i];
	}
	p.placed = status;
	if (p.placed)
	{
		l.po[0]++;
		p.order = *l.po;
	}
	else
		l.po[0]--;
	return (p);
}

/*
** Reset pieces will move all unused pieces to the horizontal location that
** the map was reset from. It will also set the g_shift to reflect the new
** horizontal position of all pieces.
*/

t_piece		*reset_pieces(t_piece *p, t_puzz l)
{
	int	pu;
	int	i;

	pu = -1;
	while (++pu < l.pnbr)
	{
		if (p[pu].placed == 0)
		{
			i = -1;
			while (++i < 4)
				p[pu].r[i] = p[pu].a[i] << l.shift;
		}
	}
	return (p);
}

/*
** Adjust_coord adjusts the paste coordinates for pieces such as the S
** piece that will paste earlier than designated empty space should be.
*/

t_puzz		adjust_coord(t_piece p, t_puzz l, t_ull *map)
{
	int	row;
	int	cs;

	row = p.a[0];
	cs = 1 << l.shift;
	row = row ^ 15;
	if (cs & map[l.mrow])
		while ((row & 1))
		{
			l.shift++;
			row = row >> 1;
		}
	return (l);
}

/*
** Pieces_left calculates how many pieces have still not been placed
** into the map yet.
*/

int			pieces_left(t_piece *p, t_puzz l)
{
	int	pu;
	int	pl;

	pu = 0;
	pl = 0;
	while (pu < l.pnbr)
		if (p[pu++].placed == 0)
			pl++;
	return (pl);
}

/*
** Main body of the recursive function.
** 117. Calculates the number of pieces left.
** 118-119: Selects the first unused piece to fit into the puzzle.
** 122-138: Trying to fit pieces into puzzle as long as there are pieces left
**			and the maximum number of empty blocks has not been exceeded.
**	If the piece fits then add it to the map and move to the next map position.
**	If the piece was placed in the incorrect position remove it from the map
**		and reset all unused pieces to the appropriate horizontal value.
*/

t_ull		*fit_pieces(t_piece *p, t_ull *map, int eb_nbr, t_puzz legend)
{
	t_ull	*tail;
	int		pu;
	int		pl;

	pl = pieces_left(p, legend);
	if ((pu = starting_piece(p, legend)) == 42)
		return (map);
	while (++pu < legend.pnbr && eb_nbr <= legend.eb_max)
		if ((p[pu].placed) != 1)
		{
			if ((check_map(p[pu], map, legend)))
			{
				p[pu] = edit_map(p[pu], map, legend, 1);
				legend = adjust_coord(p[pu], legend, map);
			}
			if (p[pu].placed == 1 || --pl == 0)
				if ((tail = move_bits(p, map, eb_nbr, legend)))
					return (tail);
			if (p[pu].placed == 1)
			{
				p[pu] = edit_map(p[pu], map, legend, 0);
				p = reset_pieces(p, legend);
			}
		}
	return (NULL);
}
