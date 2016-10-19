/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 09:51:30 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/19 11:26:25 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Checks to see if the piece values are at the right border of the puzzle.
** if they are, move pieces back to far left as well as increment map
** to the next row. NEED TO WORK ON!!! Need a way to keep track of rows
** we have been 
*/

t_ull	*move_bits(t_piece *p, t_ull *map, int eb_nbr, t_puzz l)
{
	int		pu;
	
//	ft_putendl("14");//
	pu = -1;
	while (++pu <  l.pnbr)
		if (p[pu].placed != 1)
		{
	/*		ft_putstr(" 16:");//
			ft_putstr(" g_shift:");//
			ft_putnbr(l.shift);//
			ft_putstr(" square size:");//
			ft_putnbr(l.sq_size);//
			ft_putchar('\n');//
	*/		if (l.shift >= l.sq_size)
				return (move_next_line(p, map, eb_nbr, l));
			else
			{
	//			ft_putendl("18");//
				return (shift_pieces(p, map, eb_nbr, l));
			}
		}
	return (map);
}

/*
** Count_empty counts the number of empty blocks in the row that was just completed
** and adds it to the total eb count.
*/

int		count_empty(t_ull row, t_puzz l)
{
	int	reb;
	int	brd;
	int	shift;
	int	ceb;

	reb = 0;
	brd = 1 << l.sq_size;
	shift = 0;
	while (brd != 1)
	{
		if ((row & 1) == 0)
		{
			ceb = shift + l.mrow;
			if (ceb < l.min_eb[0])
				l.min_eb[0] = ceb;
			reb++;
		}
		shift++;
		row = row >> 1;
		brd = brd >> 1;
	}
	/*	ft_putstr("Count_empty count:");//
		ft_putnbr(l.min_eb[0]); //
		ft_putchar('\n');//
*/	return (reb);
}

/*
** Move to next line is used in move_bits to move map to next line as well
** as move all unused pieces back to their starting values.
*/

t_ull	*move_next_line(t_piece *p, t_ull *map, int eb_nbr, t_puzz l)
{
	int		pu;
	int		i;

	pu = -1;
/*			ft_putstr("l.shift: ");//
			ft_putnbr(l.shift);//
			ft_putchar('\n');//
			ft_putendl("19 move_next_line");//
*/	eb_nbr += count_empty(map[l.mrow], l);
	while (++pu < l.pnbr)
		if ((p[pu].placed) != 1)
		{
			i = -1;
/*			ft_putstr("Coordinates of ");//
	 		ft_putchar(p[pu].label); //
			ft_putstr(" before shift:");//
*/			while (++i < 4)
			{
//				ft_putnbr((int)p[pu].r[i]);//
//				ft_putchar(',');//
				p[pu].r[i] = p[pu].a[i];
			}
/*			ft_putchar('\n');//
			ft_putstr("Coordinates of ");//
			ft_putchar(p[pu].label); //
			ft_putstr(" after shift:");//
			i = -1; //
			while (++i < 4)//
			{
				ft_putnbr((int)p[pu].r[i]);//
				ft_putchar(',');//
			}
			ft_putchar('\n');//
*/		}
/*	ft_putstr("20 row number:");//
	ft_putnbr(l.mrow);//
	ft_putchar('\n');//
	ft_putstr("empty block count:");//
	ft_putnbr(eb_nbr);//
	ft_putchar('\n');//
*/	l.shift = 0;
	l.mrow++;
	return (fit_pieces(p, map, eb_nbr, l));
}

/*
** Shift_pieces will move all the pieces horizontally one space so that
** they can be tried against the new pieces. Possibly look for a way to
** tell if the current spot is occupied or not.
*/

t_ull	*shift_pieces(t_piece *p, t_ull *map, int eb_nbr, t_puzz l)
{
	int	pu;
	int	i;

	pu = -1;
//	ft_putendl("21 shift_pieces");//
	while (++pu < l.pnbr)
		if ((p[pu].placed) != 1)
		{
			i = -1;
/*			ft_putstr("Coordinates of ");//
			ft_putchar(p[pu].label); //
			ft_putstr(" before shift:");//
*/			while (++i < 4)
			{
//				ft_putnbr((int)p[pu].r[i]);
//				ft_putchar(',');
				p[pu].r[i] = p[pu].r[i] << 1;

			}
/*			ft_putchar('\n');//
			i = -1;//
			ft_putstr("Coordinates of ");//
			ft_putchar(p[pu].label); //
			ft_putstr(" after shift:");//
			while (++i < 4)//
			{
				ft_putnbr((int)p[pu].r[i]);//
				ft_putchar(',');//
			}
			ft_putchar('\n');//
	*/	}
//	ft_putendl("22");//
	l.shift++;
	return (fit_pieces(p, map, eb_nbr, l));
}
