/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:29:43 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/12 22:40:02 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h> //DEEELEEETTEE

int	g_sq_size;
int	g_shift;		//g_shift is the offset each piece has in the puzzle
int	g_eb_max;		//max number empty blocks.

/*
** Checkn_paste is used to see if the space is empty, if it is empty then
** it will paste the piece into the map position.
*/

int		checkn_paste(t_piece p, t_ull *map)
{
	if ((0 == (p.r1 & *map)) && (0 == (p.r2 & *(map + 1))) 
			&& (0 == (p.r3 & *(map + 2))) && (0 == (p.r4 & *(map + 3))))
	{
		*map = p.r1 ^ *map;
		*(map + 1) = p.r2 ^ *(map + 1);
		*(map + 2) = p.r3 ^ *(map + 2);
		*(map + 3) = p.r4 ^ *(map + 3);
		p.placed = 1;
		printf("gets to pastoing");
		return (1);
	}
	return (0);
}

/*
** reset_piece will erase the currently placed piece from the map
** so that a new piece can be tried.
/

t_ull	*reset_piece(t_piece p, t_ull *map)
{

}

/
** Main body of the recursive function.
** 1. Selects first unused piece for checking.
**			If there are no unused pieces, then YAY you did it, return solution.
** 2. If the current number of empty blocks is smaller than the max then proceed 
**		with the piece fitting process (otherwise return NULL))	
**			2a. While we have pieces left, if current piece isn't used check it
**					If piece can fit then place and move otherwise check next piece.
**			2b. If no pieces can fit, then move anyways and increment eb counter.
*/

t_ull	*fit_pieces(t_piece *p, t_ull *map, int eb_nbr, int pnbr)
{
	t_ull	*tail;
	int		pu;

	pu = 0;
	tail = map;
	printf("beginning of fit");
	while (p[pu].placed == 1)
		if (++pu == (pnbr - 1))
			return (map);
	if (eb_nbr < g_eb_max)
	{
		while (pu < pnbr)
		{
			if (p[pu].placed != 1)
				if (checkn_paste(p[pu], tail))
				{
					if((tail = move_bits(p, tail, eb_nbr, pnbr)))
						return (tail);
//					tail = reset_piece(p[pu], tail);
				}
			printf("stuck int fit");
			pu++;
		}
		if((tail = move_bits(p, tail, eb_nbr + 1, pnbr)))
			return (tail);
	}
	return (NULL);
}
