/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 09:54:14 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/18 15:33:53 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <stdio.h>

/*
** Used to visulaize how the bit map operators work with each other.
** Establish the square size 
*/


int	ft_sqrt(int nbr)
{
	int	result;

	result = 1;
	while ((result * result) < nbr)
		result++;
	return (result);
}
t_piece		*total_reset(t_piece *pieces, t_puzz l)
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
	return(pieces);
}
t_ull	*eb_calculator(t_piece *pieces, t_ull *map, t_puzz l)
{
	t_ull	*solved;
	int		eb_nbr;
	int		pu;

	pu = 0;
	eb_nbr = 0;
	ft_putendl("3");
	l.eb_max = (l.sq_size * l.sq_size) - (4 * l.pnbr);
	l.mrow = 0;
	l.shift = 0;
	map = (t_ull *)ft_memalloc(sizeof(t_ull) * l.sq_size + 3);
	ft_putendl("4");
 	if ((solved = fit_pieces(pieces, map, eb_nbr, l)))
	   return (solved);	
	ft_putendl("5 exited out of fit pieces");
	pieces = total_reset(pieces, l);
/*	while (pu < l.pnbr)
	{
		if (pieces[pu].placed[0] == 0)
		{
			total_reset(pieces, l);
			break;
		}
		if (++pu == l.pnbr)
			return (map);
	}*/
	ft_putstr("6 square size:");
	ft_putnbr(l.sq_size);
	ft_putchar('\n');
	ft_memdel((void *)&map);
	l.sq_size++;
//	if (l.sq_size > 7)
//		return (map);
	map = eb_calculator(pieces, map, l);
	return (map);
}

t_ull	*map_maker(t_piece *pieces, t_puzz legend)
{
	t_ull	*map;

	ft_putendl("1");
	legend.sq_size = ft_sqrt(4 * legend.pnbr);
	map = NULL;
	map = eb_calculator(pieces, map, legend);
	ft_putendl("2");
	return (map);
}

void	print_row(t_ull row, int columns)
{
	ft_putstr(ft_strrev(ft_bitstoa(row, columns)));
}

int			main(void)
{
	t_piece	square;
	t_piece	hz;
	t_piece	hi;
	t_piece	hi2;
	t_piece	tee;
	t_piece	tup;
	t_piece	vi;
	t_piece	tl;
	t_piece	dj;
	t_piece	ll;
	t_piece	hs;
	t_piece	*array;
	t_ull	*map;
	t_puzz	puzzle;	
	int		piece_order;
	int		map_size;
	int		pi;
	int		ai;
//	int		hii;
//	int		squarei;
//	int		vzi;

/*	vz.placed = &(vz.pli);
	hi.placed = &(hi.pli);
	hi2.placed = &(hi2.pli);
	square.placed = &(square.pli);
	tee.placed = &(tee.pli);
	tup.placed = &(tup.pli);
	tl.placed = &(tl.pli);*/
	hz.r[0] = 3;
	hz.r[1] = 6;
	hz.r[2] = 0;
	hz.r[3] = 0;
	hz.a[0] = 3;
	hz.a[1] = 6;
	hz.a[2] = 0;
	hz.a[3] = 0;
	hz.placed = 0;
	hz.label = 'A';
	hz.order = 0;

	square.r[0] = 3;
	square.r[1] = 3;
	square.r[2] = 0;
	square.r[3] = 0;
	square.a[0] = 3;
	square.a[1] = 3;
	square.a[2] = 0;
	square.a[3] = 0;
	square.placed = 0;
	square.label = 'B';
	square.order = 0;

	hi.r[0] = 15;
	hi.r[1] = 0;
	hi.r[2] = 0;
	hi.r[3] = 0;
	hi.a[0] = 15;
	hi.a[1] = 0;
	hi.a[2] = 0;
	hi.a[3] = 0;
	hi.placed = 0;
	hi.label = 'C';
	hi.order = 0;

	hi2.r[0] = 15;
	hi2.r[1] = 0;
	hi2.r[2] = 0;
	hi2.r[3] = 0;
	hi2.a[0] = 15;
	hi2.a[1] = 0;
	hi2.a[2] = 0;
	hi2.a[3] = 0;
	hi2.placed = 0;
	hi2.label = 'D';
	hi2.order = 0;

	tee.r[0] = 7;
	tee.r[1] = 2;
	tee.r[2] = 0;
	tee.r[3] = 0;
	tee.a[0] = 7;
	tee.a[1] = 2;
	tee.a[2] = 0;
	tee.a[3] = 0;
	tee.placed = 0;
	tee.label = 'E';
	tee.order = 0;
	
	tup.r[0] = 2;
	tup.r[1] = 7;
	tup.r[2] = 0;
	tup.r[3] = 0;
	tup.a[0] = 2;
	tup.a[1] = 7;
	tup.a[2] = 0;
	tup.a[3] = 0;
	tup.placed = 0;
	tup.label = 'F';
	tup.order = 0;

	tl.r[0] = 2;
	tl.r[1] = 3;
	tl.r[2] = 2;
	tl.r[3] = 0;
	tl.a[0] = 2;
	tl.a[1] = 3;
	tl.a[2] = 2;
	tl.a[3] = 0;
	tl.placed = 0;
	tl.label = 'G';
	tl.order = 0;
	
	vi.r[0] = 1;
	vi.r[1] = 1;
	vi.r[2] = 1;
	vi.r[3] = 1;
	vi.a[0] = 1;
	vi.a[1] = 1;
	vi.a[2] = 1;
	vi.a[3] = 1;
	vi.placed = 0;
	vi.label = 'H';
	vi.order = 0;

	dj.r[0] = 7;
	dj.r[1] = 4;
	dj.r[2] = 0;
	dj.r[3] = 0;
	dj.a[0] = 7;
	dj.a[1] = 4;
	dj.a[2] = 0;
	dj.a[3] = 0;
	dj.placed = 0;
	dj.label = 'I';
	dj.order = 0;

	ll.r[0] = 3;
	ll.r[1] = 2;
	ll.r[2] = 2;
	ll.r[3] = 0;
	ll.a[0] = 3;
	ll.a[1] = 2;
	ll.a[2] = 2;
	ll.a[3] = 0;
	ll.placed = 0;
	ll.label = 'J';
	ll.order = 0;

	hs.r[0] = 6;
	hs.r[1] = 3;
	hs.r[2] = 0;
	hs.r[3] = 0;
	hs.a[0] = 6;
	hs.a[1] = 3;
	hs.a[2] = 0;
	hs.a[3] = 0;
	hs.placed = 0;
	hs.label = 'K';
	hs.order = 0;

	array = (t_piece *)ft_memalloc(sizeof(t_piece) * 8);
	array[0] = vi;
	array[1] = hi;
	array[2] = dj;
	array[3] = square;
	array[4] = tee;
	array[5] = hz;
	array[6] = ll;
	array[7] = hs;
//	array[1] = hi2;
//	array[2] = tl;
//	array[6] = tup;

	puzzle.pnbr = 8;
	piece_order = 0;
	puzzle.po = &piece_order;
	map_size = ft_sqrt(4 * puzzle.pnbr);

	printf("2 to the 31th:%llu 2 to the 6th:%llu 2 to the 0:%llu\n",ft_power(2, 31),ft_power(2, 6),ft_power(2, 8));

	ai = -1;
	while (++ai < puzzle.pnbr)
	{
		pi = -1;
		while (++pi < 4)
		{
			print_row(array[ai].r[pi], map_size);
			ft_putchar('\n');
		}
		ft_putchar('\n');
	}
/*	if ((0 == (array[0].r1 & array[1].r1)) && (0 == (array[0].r2 & array[1].r2)) 
			&& (0 == (array[0].r3 & array[1].r3)) && (0 == (array[0].r4 & array[1].r4)))
	{
		*map = array[0].r1 ^ array[1].r1;
		*(map + 1) = array[0].r2 ^ array[1].r2;
		*(map + 2) = array[0].r3 ^ array[1].r3;
		*(map + 3) = array[0].r4 ^ array[1].r4;
	}*/
	map = map_maker(array, puzzle);
	pi = -1;
	while (++pi < puzzle.pnbr)
	{
		ft_putnbr(array[pi].order);
		ft_putchar(array[pi].label);
		ft_putchar('\n');
	}
/*	piece_nbr = 0;
	while (piece_nbr++ < map_size)
	{
		ft_putstr("reuslt:");
		print_row(*map++, 5);
		ft_putchar('\n');
	}

/
** Think about calling the XOR operation within a function call. Possibly have
** 4 functions going at once, one for each row.
*/
}
