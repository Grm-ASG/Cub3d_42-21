/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:24:52 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/04 11:44:24 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*new;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (s_len < start + 1)
		return ((char *)ft_calloc(1, 1));
	s += start;
	s_len = ft_strlen((char *)s);
	s_len = s_len > len ? len + 1 : s_len + 1;
	ft_strlcpy((new = (char *)malloc(s_len)), s, s_len);
	return (new);
}
