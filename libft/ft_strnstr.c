/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 23:19:18 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/04 09:31:47 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*find)
		return ((char *)s);
	i = -1;
	while (s[++i] != '\0' && i < len)
		if (s[i] == find[0])
		{
			j = -1;
			while (find[++j] != '\0' &&
					s[i + j] == find[j] &&
					i + j < len)
				if (find[j + 1] == '\0')
					return ((char *)&s[i]);
		}
	return (NULL);
}
