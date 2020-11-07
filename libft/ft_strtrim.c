/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:40 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/03 22:00:41 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_is_set(char const s1, char const *set)
{
	size_t i;

	i = -1;
	while (set[++i])
		if (set[i] == s1)
			return (1);
	return (0);
}

static size_t		ft_trim_front(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	while (ft_is_set(s1[i], set))
		++i;
	return (i);
}

static size_t		ft_trim_back(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	while (s1[i])
		++i;
	while (ft_is_set(s1[i - 1], set))
		--i;
	return (i);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char		*new;
	size_t		start;
	size_t		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_trim_front(s1, set);
	if (start == ft_strlen((char *)s1))
		return ((char *)ft_calloc(1, 1));
	end = ft_trim_back(s1, set);
	return ((new = ft_substr(s1, start, end - start)));
}
