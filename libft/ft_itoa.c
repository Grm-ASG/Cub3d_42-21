/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:08:22 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/03 23:21:28 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_neg_itoa(int *n, int *neg, char (*tmp)[12])
{
	if (*n < 0)
	{
		*neg = 1;
		*n = -(*n);
	}
	else if (*n == 0)
		(*tmp)[0] = '0';
}

static char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	buff;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		buff = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = buff;
		++i;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*num;
	char			tmp[12];
	int				i;
	int				neg;

	i = 0;
	neg = 0;
	ft_bzero(tmp, 12);
	if (n <= 0)
		ft_neg_itoa(&n, &neg, &tmp);
	nbr = (unsigned int)n;
	while (nbr)
	{
		tmp[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (neg)
		tmp[i] = '-';
	if (!(num = (char *)malloc(ft_strlen(tmp) + 1)))
		return (NULL);
	return ((char *)ft_memcpy(num, ft_strrev(tmp), ft_strlen(tmp) + 1));
}
