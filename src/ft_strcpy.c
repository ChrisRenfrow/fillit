/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:11:00 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/27 09:25:51 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Copies the src string into the dst string and returns the adress of the
** dst string.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	index;

	index = -1;
	while (src[++index])
		dst[index] = src[index];
	dst[index] = '\0';
	return (dst);
}
