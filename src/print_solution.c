/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:35:55 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/19 09:54:23 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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
	pi = -1;//
	while (++pi < l.pnbr)//
	{
		ft_putnbr(p[pi].order);//
		ft_putchar(p[pi].label);//
		ft_putchar('\n');//
	}
	while (printtest++ < l.sq_size)//
	{
		ft_putstr("reuslt:");//
		print_row(*map++, l.sq_size);//
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
	p = sort_pieces(p, l);
	ft_putendl("After sorting:");
	pi = -1;//
	while (++pi < l.pnbr)//
	{
		ft_putnbr(p[pi].order);//
		ft_putchar(p[pi].label);//
		ft_putchar('\n');//
	}
}
