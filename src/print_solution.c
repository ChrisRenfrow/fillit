/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:35:55 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/20 15:00:40 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	print_shit(t_piece *p, t_ull *map, t_puzz l)
{
	int	pi;//
	int ai;//
	int printtest = 0;//
		l.mrow = -1;//
		l.min_eb[0] = 10000;//
		while (++l.mrow < l.sq_size)//
			count_empty(map[l.mrow], l);//
		ft_putendl("Square size");//
		ft_putnbr(l.sq_size);//
		ft_putchar('\n');//
	while (printtest++ < l.sq_size)//
	{
		ft_putstr("reuslt:");//
		print_row(*map++, l.sq_size);//
		ft_putchar('\n');//
	}
	ft_putendl("After sorting:");//
	pi = -1;//
	while (++pi < l.pnbr)//
	{
		ft_putnbr(p[pi].order);//
		ft_putchar(p[pi].label);//
		ft_putchar('\n');//
	}
	ai = -1;//
	while (++ai < l.pnbr)//
	{
		pi = -1;//
		while (++pi < 4)//
		{
			print_row(p[ai].r[pi], l.sq_size);//
			ft_putchar('\n');//
		}
		ft_putchar('\n');//
	}

}

/*
** Sorts the pieces into the order of which they were placed into the map.
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
			if (p[i].order > p[i + 1].order)
			{
				temp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = temp;
				count++;
			}
		}
	}
	return (p);
}

void	print_solution(t_piece *p, t_ull *map, t_puzz l)
{
//	char	**puzzle;
	int		pu;
	int		col;
	int		row;
	int		pri;
	int		paste;
//	int		size;

	p = sort_pieces(p, l);
//	size = l.sq_size + 1;
//	if(!(puzzle = (char **)ft_new_handle(size, size, sizeof(char))))
//		return ;
	row = -1;
	col = -1;
	paste = 0;
	while (++row < l.sq_size)
	{
		col = 0;
		pu = 0;
/*	ft_putstr("Row:");//
	ft_putnbr(row);//
	ft_putchar('\n');//
*/		while (col < l.sq_size && pu < l.pnbr)
		{
			if (!(map[row] & 1))
			{
//			ft_putstr("Empty: ");//
				ft_putchar('.');
//			ft_putchar('\n');//
				map[row] = map[row] >> 1;
				col++;
			}
			pri = 0;
			while  (!(p[pu].a[pri]) && pri < 3)
				pri++;
/*		ft_putchar(p[pu].label);//
		ft_putnbr(p[pu].order);//
		ft_putnbr(pri);//
		ft_putstr(" Piece: ");//
		print_row(p[pu].a[pri], l.sq_size);//
		ft_putchar('\n');//
*/			while  ((p[pu].a[pri]) && ((~p[pu].a[pri]) & 1))
				p[pu].a[pri] = p[pu].a[pri] >> 1;
/*		ft_putstr("    Piece: ");//
		print_row(p[pu].a[pri], l.sq_size);//
		ft_putchar('\n');//
		if ((p[pu].a[pri] & map[row]))//
			ft_putendl(" passed a & m");//
		if ((p[pu].r[pri] & (1 << col)))//
			ft_putendl("   passed r & c");//
*/			while ((p[pu].a[pri] & map[row]) && p[pu].a[pri] && 
					(p[pu].r[pri] & (1 << col)))
			{
//			ft_putendl("Enter while");//
				ft_putchar(p[pu].label);
/*			ft_putnbr(p[pu].order);//
			ft_putnbr(pri);//
			ft_putstr(" Piece: ");//
			print_row(p[pu].a[pri], l.sq_size);//
			ft_putchar('\n');//
			ft_putstr("    Map:   ");//
			print_row(map[row], l.sq_size);//
			ft_putchar('\n');//
	*/			p[pu].a[pri] = p[pu].a[pri] >> 1;
				map[row] = map[row] >> 1;
/*			ft_putstr("After Piece: ");//
			print_row(p[pu].a[pri], l.sq_size);//
			ft_putchar('\n');//
			ft_putstr("After Map:   ");//
			print_row(map[row], l.sq_size);//
			ft_putchar('\n');//
			ft_putchar('\n');//
*/			paste = 1;
				col++;
		}
		pu++;
		if (paste-- == 1)
			pu = 0;
//		ft_putendl("Next piece");//
		}
		ft_putchar('\n');
	}

//	print_shit(p, map, l);
}
