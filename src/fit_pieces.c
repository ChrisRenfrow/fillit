/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:29:43 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/18 15:34:18 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h> //DEEELEEETTEE


/*
** Edit_map will either cut or paste a piece depending on the status.
** status = 1 indicates that the piece was  pasted into the map.
** status = 0 indicates that the piece was cut from the map.
*/

t_piece		edit_map(t_piece p, t_ull *map, t_puzz l, int status)
{
	int	printtest = 0;//
	int	i;

	i = -1;
	while (++i < 4)
	{
		map[l.mrow + i] = p.r[i] ^ map[l.mrow + i];
		ft_putnbr(p.r[i]);//
		ft_putchar(',');//
	}
	ft_putchar('\n');//
	p.placed = status;
	if (p.placed)
	{
		l.po[0]++;
		p.order = *l.po;
	}
	else
		l.po[0]--;

	ft_putendl("12 editing map");//
	ft_putstr("1 = paste, 0 = reset: ");//
	ft_putnbr(p.placed);//
	ft_putchar('\n');//
	while (printtest++ < l.sq_size)//
	{
		ft_putstr("reuslt:");//
		print_row(*map++, l.sq_size);//
		ft_putchar('\n');//
	}
	ft_putchar(p.label);//
	ft_putnbr(p.order);//
	ft_putchar('\n');//
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
	ft_putendl("Resetting pieces");//
	ft_putstr("puzzle.shift: ");//
	ft_putnbr(l.shift);//
	ft_putchar('\n'); //

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
** Main body of the recursive function.
** 1. Selects first unused piece for checking.
**			If there are no unused pieces, then YAY you did it, return solution.
** 2. If the current number of empty blocks is smaller than the max then proceed 
**		with the piece fitting process (otherwise return NULL))	
**			2a. While we have pieces left, if current piece isn't used check it
**					If piece can fit then place and move otherwise check next piece.
**			2b. If no pieces can fit, then move anyways and increment eb counter.
*/

t_ull	*fit_pieces(t_piece *p, t_ull *map, int eb_nbr, t_puzz legend)
{
	t_ull	*tail;
	int		pu;
	int		pl;

	pu = 0;
	pl = 0;
	while (pu < legend.pnbr)//
		if (p[pu++].placed == 0)//
			pl++;//
	ft_putendl("7");//
	pu = 0;
	while ((p[pu].placed) == 1)
		if (++pu == legend.pnbr)
			return (map);
	ft_putstr("8: eb before check:");//
	ft_putnbr(eb_nbr);//
	ft_putstr(" max eb:");//
	ft_putnbr(legend.eb_max);//
	ft_putchar('\n');//
	while (pu < legend.pnbr && eb_nbr <= legend.eb_max)
	{
		ft_putendl("9");//
		if ((p[pu].placed) != 1)
		{
			if ((check_map(p[pu], map, legend)))
				p[pu] = edit_map(p[pu], map, legend, 1);
			if (p[pu].placed == 1 || --pl == 0)
			{
				if (pl == 0)//
					ft_putendl("moving to next space");//
				if((tail = move_bits(p, map, eb_nbr, legend)))
					return (tail);
				if (p[pu].placed == 1)
				{
					p[pu] = edit_map(p[pu], map, legend, 0);
					p = reset_pieces(p, legend); 
				}
			}
		}
		ft_putendl("12");//
		pu++;
	}
	ft_putendl("Backtracking");
	return (NULL);
}
