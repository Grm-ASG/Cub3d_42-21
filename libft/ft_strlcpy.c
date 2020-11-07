/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:17:41 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/03 19:40:45 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (!src || !dest)
		return (0);
	if (size)
	{
		while (++i < size - 1 && src[i] != '\0')
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
