/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 09:54:14 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/26 15:54:36 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>

void	print_row(t_ull row, int columns)
{
	ft_putstr(ft_strrev(ft_bitstoa(row, columns)));
}

int			main(void)
{
	t_piece	square;
	t_piece	hz;
	t_piece	vz;
	t_piece	hi;
	t_piece	vi;
	t_piece	tee;
	t_piece	tup;
	t_piece	tr;
	t_piece	tl;
	t_piece	ll;
	t_piece	ld;
	t_piece	lu;
	t_piece	lr;
	t_piece	vs;
	t_piece	hs;
	t_piece	dj;
	t_piece	ju;
	t_piece	j;
	t_piece	jr;
	t_piece	*array;
//	t_ull	*map;
	t_puzz	puzzle;	
//	int		map_size;
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

	vs.r[0] = 1;
	vs.r[1] = 3;
	vs.r[2] = 2;
	vs.r[3] = 0;
	vs.a[0] = 1;
	vs.a[1] = 3;
	vs.a[2] = 2;
	vs.a[3] = 0;
	vs.placed = 0;
	vs.label = 'D';

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

	j.r[0] = 2;
	j.r[1] = 2;
	j.r[2] = 3;
	j.r[3] = 0;
	j.a[0] = 2;
	j.a[1] = 2;
	j.a[2] = 3;
	j.a[3] = 0;
	j.placed = 0;
	j.label = 'L';

	tr.r[0] = 1;
	tr.r[1] = 3;
	tr.r[2] = 1;
	tr.r[3] = 0;
	tr.a[0] = 1;
	tr.a[1] = 3;
	tr.a[2] = 1;
	tr.a[3] = 0;
	tr.placed = 0;
	tr.label = 'M';

	ld.r[0] = 7;
	ld.r[1] = 1;
	ld.r[2] = 0;
	ld.r[3] = 0;
	ld.a[0] = 7;
	ld.a[1] = 1;
	ld.a[2] = 0;
	ld.a[3] = 0;
	ld.placed = 0;
	ld.label = 'N';
	
	vz.r[0] = 2;
	vz.r[1] = 3;
	vz.r[2] = 1;
	vz.r[3] = 0;
	vz.a[0] = 2;
	vz.a[1] = 3;
	vz.a[2] = 1;
	vz.a[3] = 0;
	vz.placed = 0;
	vz.label = 'O';

	ju.r[0] = 1;
	ju.r[1] = 7;
	ju.r[2] = 0;
	ju.r[3] = 0;
	ju.a[0] = 1;
	ju.a[1] = 7;
	ju.a[2] = 0;
	ju.a[3] = 0;
	ju.placed = 0;
	ju.label = 'P';
	
	jr.r[0] = 3;
	jr.r[1] = 1;
	jr.r[2] = 1;
	jr.r[3] = 0;
	jr.a[0] = 3;
	jr.a[1] = 1;
	jr.a[2] = 1;
	jr.a[3] = 0;
	jr.placed = 0;
	jr.label = 'Q';

	lu.r[0] = 4;
	lu.r[1] = 7;
	lu.r[2] = 0;
	lu.r[3] = 0;
	lu.a[0] = 4;
	lu.a[1] = 7;
	lu.a[2] = 0;
	lu.a[3] = 0;
	lu.placed = 0;
	lu.label = 'R';

	lr.r[0] = 1;
	lr.r[1] = 1;
	lr.r[2] = 3;
	lr.r[3] = 0;
	lr.a[0] = 1;
	lr.a[1] = 1;
	lr.a[2] = 3;
	lr.a[3] = 0;
	lr.placed = 0;
	lr.label = 'S';

	dj.label = 'A';
	ld.label = 'B';
	hi.label = 'C';
	lu.label = 'D';
	hz.label = 'E';
	tr.label = 'F';
//	ll.label = 'G';
//	tee.label = 'H';
	array = (t_piece *)ft_memalloc(sizeof(t_piece) * 6);
	array[0] = dj;
	array[1] = ld;
	array[2] = hi;
	array[3] = lu;
	array[4] = hz;
	array[5] = tr;
	array[6] = dj;
/*	array[7] = tee;//
	array[2] = vi;//
	array[3] = hi;
	array[4] = hi;//
	array[5] = hi;//
	array[8] = dj;
	array[9] = dj;//
	array[10] = tee;
	array[11] = tee;//
	array[13] = square;//
	array[14] = hz;
	array[15] = hz;//
	array[16] = ll;
	array[17] = ll;//
	array[19] = hs;//
	array[20] = tl;
	array[22] = tl;//
	array[23] = tup;//
	array[23] = j;
	array[24] = dj;
	array[25] = square;
*/
	puzzle.pnbr = 6;
//	map_size = ft_sqrt(4 * puzzle.pnbr);

	ai = -1;
	while (++ai < puzzle.pnbr)
	{
		pi = -1;
		ft_putchar(array[ai].label);
		ft_putchar('\n');
		while (++pi < 4)
		{
			print_row(array[ai].r[pi], 4);
			ft_putchar('\n');
		}
		ft_putchar('\n');
	}
	 initializer(array, &puzzle);
}
