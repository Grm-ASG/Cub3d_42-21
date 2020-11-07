/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:42:03 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/04 09:31:06 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen((char *)s);
	while (len + 1)
		if (s[len--] == (unsigned char)c)
			return ((char *)(s + ++len));
	return (NULL);
}
