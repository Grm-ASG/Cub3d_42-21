/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:48:15 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/03 22:10:29 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (!s || !f || !(new = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = (*f)(i, s[i]);
	new[i] = '\0';
	return (new);
}
