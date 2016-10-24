/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:11:40 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/24 11:01:24 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

extern char *g_blockdefine[20];

typedef unsigned long long t_ull;

typedef	struct				s_puzzle
{
//	int						*po;
	t_ull					*map;
	int						sq_size;
	int						pnbr;
	int						shift;
	int						mrow;
//	int						eb_max;
	int						pu;
}							t_puzz;

typedef	struct				s_piece
{
	unsigned long long		r[4];
	unsigned long long		a[4];
	int						placed;
	int						order;
	int						shift;
	int						mrow;
	unsigned char			label;
}							t_piece;

//t_piece						edit_map(t_piece p, t_ull *map,
//								t_puzz l, int status);
t_piece						*sort_pieces(t_piece *p, t_puzz l);
t_piece						*placed_reset(t_piece *p, t_puzz l);

t_puzz						adjust_coord(t_piece p, t_puzz l, t_ull *map);

//t_ull						*fit_pieces(t_piece *p, t_ull *map,
//								int eb_nbr, t_puzz l);
/*
t_ull						*move_bits(t_piece *p, t_ull *map, int eb_nbr, t_puzz l);
t_ull						*move_next_line(t_piece *p, t_ull *map, int eb_nbr, t_puzz l);
t_ull						*shift_pieces(t_piece *p, t_ull *map, int eb_nbr, t_puzz l);
t_puzz						eb_calculator(t_piece *pieces, t_puzz l);
*/
// New functions
t_puzz	*starting_position(t_piece *p, t_puzz *l);
t_puzz	*fit_piece(t_piece *p, t_puzz *l);
t_puzz	*move_piece(t_piece *p, t_puzz *l);
t_puzz	*edit_map(t_piece *p, t_puzz *l);
int		check_bottom(t_piece p, t_puzz l);
int		check_border(t_piece p, t_puzz l);
void	map_maker(t_piece *pieces, t_puzz *legend);

char						*ft_strchrrm(char *input, char c);
char						*ft_strctrim(char *input, char c);

//void						map_maker(t_piece *pieces, t_puzz legend);
void						print_solution(t_piece *p, t_ull *map, t_puzz l);

int							check_map(t_piece p, t_ull *map, t_puzz l);
int							count_empty(t_ull row, t_puzz l);
int							starting_piece(t_piece *p, t_puzz l);
int							ct_pieces(char *input);
int							is_valid_block(char *input);

void	print_row(t_ull row, int columns);//

#endif
