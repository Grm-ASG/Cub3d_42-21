/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:21:16 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/02 13:14:57 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_calc_words(char *tmp, char c, int *words)
{
	size_t flag;
	size_t i;

	i = 0;
	*words = 0;
	flag = 0;
	while (tmp[i])
	{
		if (tmp[i] == c)
		{
			if (flag)
				(*words)++;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	if (flag)
		(*words)++;
}

static int		ft_separate(char **new, char *s, char c, int words)
{
	int			i;
	size_t		j;
	size_t		k;

	i = -1;
	j = 0;
	while (++i < words)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[k + j] != c && s[k + j] != '\0')
			k++;
		if (!(new[i] = ft_substr(s, j, k)))
		{
			while (i >= 0)
				free(new[i--]);
			free(new);
			return (1);
		}
		j += k;
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**new;
	int		words;
	int		crs;

	if (!s)
		return (NULL);
	ft_calc_words((char *)s, c, &words);
	if (!(new = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	new[words] = NULL;
	if (words)
		if ((crs = ft_separate(new, (char *)s, c, words)))
			return (NULL);
	return (new);
}
