/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 09:54:14 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/20 19:06:17 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** ft_sqrt gives the smallest square size that can be created given the number
** of pieces.
*/

int		ft_sqrt(int nbr)
{
	int	result;

	result = 1;
	while ((result * result) < nbr)
		result++;
	return (result);
}

/*
** Total_reset resets all the pieces to their base state after a failure to
** fit a puzzle.
*/

t_piece	*total_reset(t_piece *pieces, t_puzz l)
{
	int	pu;
	int	i;

	pu = 0;
	while (pu < l.pnbr)
	{
		i = -1;
		while (++i < 4)
			pieces[pu].r[i] = pieces[pu].a[i];
		pieces[pu++].placed = 0;
	}
	return (pieces);
}

/*
** Calculates the max number of empty blocks that can be present in the puzzle
** given the square size and number of pieces.
** Also acts as the top level of recursion, increasing the square size if the
** pieces can't fit in the previous square.
*/

t_ull	*eb_calculator(t_piece *pieces, t_ull *map, t_puzz l)
{
	t_ull	*solved;
	int		eb_nbr;
	int		pu;

	pu = 0;
	eb_nbr = 0;
	l.eb_max = (l.sq_size * l.sq_size) - (4 * l.pnbr);
	l.mrow = 0;
	l.shift = 0;
	map = (t_ull *)ft_memalloc(sizeof(t_ull) * l.sq_size + 3);
	if ((solved = fit_pieces(pieces, map, eb_nbr, l)))
	{
		pieces = sort_pieces(pieces, l);
		print_solution(pieces, solved, l);
		return (solved);
	}
	pieces = total_reset(pieces, l);
	ft_memdel((void *)&map);
	l.sq_size++;
	map = eb_calculator(pieces, map, l);
	return (map);
}

/*
** Initializes the square size and activates the recursion loop.
*/

void	map_maker(t_piece *pieces, t_puzz legend)
{
	t_ull	*map;

	legend.sq_size = ft_sqrt(4 * legend.pnbr);
	map = NULL;
	map = eb_calculator(pieces, map, legend);
	ft_memdel((void *)&map);
}
