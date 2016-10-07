/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:11:40 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/07 14:28:23 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

enum					e_tetr
{
	SQUARE,
	VERT_I,
	HORZ_I,
	HORZ_Z,
	VERT_Z,
	HORZ_RZ,
	VERT_RZ,
	VERT_L,
	HORZ_L,
	UPDN_L,
	UPDN_HL,
	VERT_RL,
	HORZ_RL,
	UPDN_RL,
	UPDN_HRL,
	T,
	RIGHT_T,
	UPDN_T,
	LEFT_T,
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
