/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:11:40 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/20 15:29:50 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// Ordered by weight of candidacy
extern char *g_blockdefine[20];

typedef	struct				s_puzzle
{
	int						*min_eb;
	int						*po;
	int						sq_size;
	int						pnbr;
	int						shift;
	int						mrow;
	int						eb_max;
}							t_puzz;

typedef unsigned long long t_ull;

typedef	struct				s_piece
{
	unsigned long long		r[4];
	unsigned long long		a[4];
	int						placed;
	int						order;
	unsigned char			label;
}							t_piece;

//Kyle functions// Delete this line
int							check_map(t_piece p, t_ull *map, t_puzz l);
t_piece						edit_map(t_piece p, t_ull *map, t_puzz l, int status);
int							count_empty(t_ull row, t_puzz l);
t_ull						*fit_pieces(t_piece *p, t_ull *map, int eb_nbr, t_puzz l);
t_ull						*move_bits(t_piece *p, t_ull *map, int eb_nbr, t_puzz l);
t_ull	 	 	 	 	 	*move_next_line(t_piece *p, t_ull *map, int eb_nbr, t_puzz l);
t_ull						*shift_pieces(t_piece *p, t_ull *map, int eb_nbr, t_puzz l);
t_ull						*map_maker(t_piece *pieces, t_puzz legend);
t_ull						*eb_calculator(t_piece *pieces, t_ull *map, t_puzz l);
void						print_row(t_ull row, int columns);
void						print_solution(t_piece *p, t_ull *map, t_puzz l);
t_puzz						adjust_coord(t_piece p, t_puzz l, t_ull *map);


int 	ct_pieces(char *input);
int 	is_valid_block(char *input);
char	**ft_fillit(t_piece **pieces, int piecenbr);
void	ft_print(char **puzzle);

char	*ft_strchrrm(char *input, char c);
char	*ft_strctrim(char *input, char c);

#endif
