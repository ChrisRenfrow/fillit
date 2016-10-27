/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 10:39:21 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/24 10:48:05 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Uses ft_putendl_fd to write a string with a new line to the standard output.
*/

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}
