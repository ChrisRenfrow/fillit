/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 20:20:42 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/24 11:36:48 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

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

t_puzz	*eb_calculator(t_piece *pieces, t_puzz *l)
{
	t_puzz	*solved;
	int		pu;

	pu = 0;
	l->mrow = 0;
	l->shift = 0;
	l->pu = 0;
	if (!(l->map = (t_ull *)ft_memalloc(sizeof(t_ull) * (l->sq_size + 3))))
		return (NULL);
	if ((solved = fit_piece(pieces, l)))
	{
		pieces = sort_pieces(pieces, *solved);
		print_solution(pieces, solved->map, *solved);
		return (l);
	}
	pieces = total_reset(pieces, *l);
	ft_memdel((void *)&l->map);
	l->sq_size++;
	l = eb_calculator(pieces, l);
	return (l);
}

/*
** Initializes the square size and activates the recursion loop.
*/

void	map_maker(t_piece *pieces, t_puzz *legend)
{
	legend->sq_size = ft_sqrt(4 * legend->pnbr);
	legend = eb_calculator(pieces, legend);
	ft_memdel((void *)&legend->map);
}
