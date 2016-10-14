/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:11:40 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/14 11:56:47 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define B(i) g_blockdefine[i]
# define C(x, y) ft_strcmp(x, y)
# define IS_PIECE(input, index)while(B(index)){if(C(input, B(index))){index++;}}


// Ordered by weight of candidacy
const char *g_blockdefine[] = {		"#...#...#...#", 	//VT I
									"####",				//HZ I
									"##..##", 			//SQ
									"###.#",			//RT L
									"##..#...#",		//DN J
									"##...##",			//VT Z
									"#...##...#",		//HZ Z
									"#...##..#",		//VT S
									"##.##",			//HZ S
									"#...#...##",		//UP L	
									"##..#..#",			//DN L
									"#.###",			//LT L
									"#...#..##",      	//UP J
									"#...###",        	//RT J
									"###...#",			//LT J
									"#..###",			//UP T
									"#...##..#",		//RT T
									"###..#",			//DN T
									".#..##...#" };		//LT T

typedef	struct			s_piece
{
	unsigned char		label;
	unsigned int		placed;
	unsigned long long	map[4];
}						t_piece;

int 	ct_pieces(char *input);
int 	is_valid_block(char *input);
char	**ft_fillit(t_piece **pieces, int piecenbr);
void	ft_print(char **puzzle);

char	*ft_strchrrm(char *input, char c);
char	*ft_strctrim(char *input, char c);

#endif
