/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:11:40 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/08 16:57:20 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

const char g_blockdefine[19][] = {	{"##..##"}, 		//SQ
									{"#...#...#...#"}, 	//VT I
									{"####"},			//HZ I
									{"##...##"},		//VT Z
									{"#...##...#"},		//HZ Z
									{"#...##..#"},		//VT S
									{"##.##"},			//HZ S
									{"#...#...##"},		//UP L
									{"###.#"},			//RT L
									{"##..#..#"},		//DN L
									{"#.###"},			//LT L
									{"#...#..##"},      //UP J
									{"#...###"},        //RT J
									{"##..#...#"},		//DN J
									{"###...#"},		//LT J
									{"#..###"},			//UP T
									{"#...##..#"},		//RT T
									{"###..#"},			//DN T
									{".#..##...#"} };	//LT T


enum					e_block
{
	SQUARE, 	//SQUARE IS SQUARE
	VRT_I,		//VERTICAL 'I' BLOCK
	HRZ_I,		//HORIZONTAL 'I' BLOCK
	VER_ZE,		//VERTICAL 'Z' BLOCK
	HRZ_ZE,		//HORIZONTAL 'Z' BLOCK
	VER_ES,		//VERTICAL 'S' BLOCK
	HRZ_ES,		//HORIZONTAL 'S' BLOCK
	UP_ELL,		//UP-FACING 'L' BLOCK
	RT_ELL,		//RIGHT-FACING 'L' BLOCK
	DN_ELL,		//DOWN-FACING 'L' BLOCK
	LT_ELL,		//LEFT-FACING 'L' BLOCK
	UP_JAY,		//UP-FACING 'J' BLOCK
	RT_JAY,		//RIGHT-FACING 'J' BLOCK
	DN_JAY,		//DOWN-FACING 'J' BLOCK
	LT_JAY,		//LEFT-FACING 'J' BLOCK
	UP_TEE,		//UP-FACING 'T' BLOCK
	RT_TEE,		//RIGHT-FACING 'T' BLOCK
	DN_TEE,		//DOWN-FACING 'T' BLOCK
	LT_TEE,		//LEFT-FACING 'T' BLOCK
};



typedef	struct			s_piece
{
	unsigned char		order;
	unsigned long long	bitmap;
}						t_piece;

t_piece					**ft_input_validator(char *str, int	*piecenbr);

char					**ft_fillit(t_piece **pieces, int piecenbr);

void					ft_print(char **puzzle);
#endif
