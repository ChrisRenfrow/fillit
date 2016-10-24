/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fit_pieces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 11:02:34 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/24 11:37:07 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Edit_map will either cut or paste a piece depending on the status.
** status = 1 indicates that the piece was  pasted into the map.
** status = 0 indicates that the piece was cut from the map.
*/

t_puzz	*edit_map(t_piece *p, t_puzz *l)
{
	int	i;

	i = -1;
	while (++i < 4)
		l->map[l->mrow + i] = p[l->pu].r[i] ^ l->map[l->mrow + i];
	l->pu++;
	return (fit_piece(p, l));
}

/*
** Edit_map will either cut or paste a piece depending on the status.
** status = 1 indicates that the piece was  pasted into the map.
** status = 0 indicates that the piece was cut from the map.
*/

t_puzz	*reset_map(t_piece *p, t_puzz *l)
{
	int	i;
	i = -1;
	l->pu--;
	l->mrow = p[l->pu].mrow;
	while (++i < 4)
		l->map[l->mrow + i] = p[l->pu].r[i] ^ l->map[l->mrow + i];
	return (l);
}

/*
** Starting_position determines where in the map to start trying to place 
** the next piece. Normally the starting position is at the top left of the
** map unless the piece is a duplicate of an already placed piece. In that
** case the piece starts after the already placed piece.
*/

t_puzz	*starting_position(t_piece *p, t_puzz *l)
{
	int	i;
	int	pri;
	int	counter;

	i = -1;
	if (p[l->pu].placed == 0)
	{
		l->shift = 0;
		l->mrow = 0;
	}
	while (++i < l->pnbr)
	{
		pri = -1;
		counter = 0;
		if (p[i].placed == 1)
			while (++pri < 4)
				if (p[l->pu].a[pri] == p[i].a[pri])
					counter++;
		if (counter == 4)
		{
			l->shift = p[i].shift;
			l->mrow = p[i].mrow;
		}
	}
	p[l->pu].shift = l->shift;
	p[l->pu].mrow = l->mrow;
	return (l);
}

/*
** 
*/

t_puzz	*fit_piece(t_piece *p, t_puzz *l)
{
	t_puzz *solved;

	if (l->pu == l->pnbr)
		return (l);
	l = starting_position(p, l);
	p[l->pu].placed = 1;
	if (check_map(p[l->pu], l->map, *l))
	{
		if ((solved = edit_map(p, l)))
			return (solved);
		l = reset_map(p, l);
	}
	if ((check_bottom(p[l->pu], *l)) || (check_border(p[l->pu], *l)))
	{
		if ((solved = move_piece(p, l)))
			return (solved);
		p[l->pu].placed = 0;
	}
	return (NULL);
}
