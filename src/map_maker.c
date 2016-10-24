/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:31:10 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/24 16:12:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

/*
** Sorts the pieces by the row in which they were placed on the map.
*/

t_piece	*sort_pieces(t_piece *p, t_puzz l)
{
	t_piece	temp;
	int		count;
	int		i;

	count = 1;
	while (count != 0)
	{
		count = 0;
		i = -1;
		while ((++i + 1) < l.pnbr)
		{
			if (p[i].mrow > p[i + 1].mrow)
			{
				temp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = temp;
				count++;
			}
		}
	}
	i = -1;
	return (p);
}

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
** Runs fit_piece at the smallest possible square size,
** and increments the square size if needed.
*/

t_puzz	*initializer(t_piece *pieces, t_puzz *l)
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
	l = initializer(pieces, l);
	return (l);
}

/*
** Initializes the square size and activates the recursion loop.
*/

void	map_maker(t_piece *pieces, t_puzz *legend)
{
	legend->sq_size = ft_sqrt(4 * legend->pnbr);
	legend = initializer(pieces, legend);
	ft_memdel((void *)&legend->map);
}
