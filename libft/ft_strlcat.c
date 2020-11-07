/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:48:58 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/04 09:31:38 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t src_len;
	size_t dest_len;
	size_t i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = -1;
	if (size > dest_len)
	{
		while (++i < size - dest_len - 1 && src[i] != '\0')
			dest[dest_len + i] = src[i];
		dest[dest_len + i] = '\0';
		return (ft_strlen(src) + dest_len);
	}
	return (size + src_len);
}
