/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:35:55 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/24 16:07:21 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** If the first bit of mrow is 0 then '.' is printed and mrow is shifted.
** col is also iterated to reflect movement in printing position.
*/

t_ull	print_empty(t_ull mrow, int *col, int *paste)
{
	if (!(mrow & 1))
	{
		ft_putchar('.');
		mrow = mrow >> 1;
		(*col)++;
		*paste = 0;
	}
	return (mrow);
}

/*
** print_char prints the appropriate character.
** 1. Establishes which row of the piece to print.
** 2. Deletes any 0s preceeding a 1 in the piece row.
** 3. Prints characters as long as the piece compares appropriatley to the map
**	as well as its horizontal position in the puzzle.
*/

t_piece	print_char(t_piece p, t_ull *mrow, int *col, int *paste)
{
	int	pri;

	pri = 0;
	while (!(p.a[pri]) && pri < 3)
		pri++;
	while ((p.a[pri]) && ((~p.a[pri]) & 1))
		p.a[pri] = p.a[pri] >> 1;
	while ((p.a[pri] & *mrow) && (p.r[pri] & (1 << *col)))
	{
		ft_putchar(p.label);
		p.a[pri] = p.a[pri] >> 1;
		*mrow = *mrow >> 1;
		p.placed = 1;
		*paste = 1;
		(*col)++;
	}
	return (p);
}

/*
** print_reset sets the placed value of all pieces to 0.
** Indicating that the piece has not been printed on this row yet.
*/

t_piece	*print_reset(t_piece *p, t_puzz l)
{
	int	pu;

	pu = -1;
	while (++pu < l.pnbr)
		p[pu].placed = 0;
	return (p);
}

/*
** Prints the solution by comparing the anchor values of the pieces with map.
** If the pieces match then we shift both map and anchor values to indicate that
** the piece portion and map portion have been printed already.
*/

void	print_solution(t_piece *p, t_ull *map, t_puzz l)
{
	int		pu;
	int		col;
	int		row;
	int		paste;

	row = -1;
	while (++row < l.sq_size)
	{
		col = 0;
		pu = 0;
		p = print_reset(p, l);
		while (col < l.sq_size && pu < l.pnbr)
		{
			map[row] = print_empty(map[row], &col, &paste);
			if (p[pu].placed == 0)
				p[pu] = print_char(p[pu], &map[row], &col, &paste);
			pu++;
			if (paste-- == 1)
				pu = 0;
		}
		ft_putchar('\n');
	}
}
