/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:34:50 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/04 09:29:12 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *s;
	unsigned char *d;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
		if (*(s - 1) == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
