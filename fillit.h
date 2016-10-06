/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:11:40 by kdavis            #+#    #+#             */
/*   Updated: 2016/10/06 11:27:36 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

enum			e_tetr
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

typedef	struct	s_piece
{
	int			order;
	int			b1x;
	int			b1y;
	int			b2x;
	int			b2y;
	int			b3x;
	int			b3y;
	int			b4x;
	int			b4y;
}				t_piece;

#endif
