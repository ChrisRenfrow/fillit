/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 12:08:20 by kdavis            #+#    #+#             */
/*   Updated: 2016/09/29 07:29:53 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Allocates a substring from the source string. The substring begins at
** 'start' index and is 'len' characters long.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (!(sub = ft_strnew(len)))
		return (NULL);
	s += start;
	sub = ft_strncpy(sub, s, len);
	return (sub);
}
