/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:11:40 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/27 12:09:17 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

extern char *g_blockdefine[20];

typedef unsigned long long t_ull;

typedef	struct		s_puzzle
{
	t_ull			*map;
	int				sq_size;
	int				pnbr;
	int				shift;
	int				mrow;
	int				pu;
}					t_puzz;

typedef	struct		s_piece
{
	t_ull			r[4];
	t_ull			a[4];
	int				placed;
	int				shift;
	int				mrow;
	unsigned char	label;
}					t_piece;

/*
** map_maker.c functions
*/
t_piece				*sort_pieces(t_piece *p, t_puzz l);
t_puzz				*solve_puzzle(t_piece *pieces, t_puzz *l);
t_piece				*total_reset(t_piece *pieces, t_puzz l);
int					ft_sqrt(int nbr);

/*
** fit_pieces.c functions
*/
t_puzz				*starting_position(t_piece *p, t_puzz *l);
t_puzz				*fit_piece(t_piece *p, t_puzz *l);
t_puzz				*move_piece(t_piece *p, t_puzz *l);
t_puzz				*edit_map(t_piece *p, t_puzz *l, int status);

/*
** check_map.c functions
*/
int					check_bottom(t_piece p, t_puzz l);
int					check_border(t_piece p, t_puzz l);
int					check_zone(t_piece p, t_ull *map, t_puzz l);
int					check_map(t_piece p, t_ull *map, t_puzz l);

/*
** print_solution.c functions
*/
t_ull				print_empty(t_ull mrow, int *col, int *paste);
t_piece				print_char(t_piece p, t_ull *mrow, int *col, int *paste);
t_piece				*print_reset(t_piece *p, t_puzz l);
void				print_solution(t_piece *p, t_ull *map, t_puzz l);

/*
** input_handler.c
*/
t_piece				make_piece(char *input, int label);
t_piece				*process_input(t_puzz *legend, int fd);
t_ull				*ft_btoull(int *bin);
t_ull				*bitmath(char *input);

/*
** validate_piecec.c
*/
char				*ft_strchrrplc(char *str, int c_a, int c_b);
int					is_piece(char *input);
int					ct_pieces(char *input);
int					is_valid_block(char *input);
void				init_blockdefine(void);

/*
** main.c
*/
t_ull				*shift_piece(t_ull *tmpull);
t_piece				*read_pieces(char *filename, t_puzz *legend);
void				*freer(void *ptr);

#endif
