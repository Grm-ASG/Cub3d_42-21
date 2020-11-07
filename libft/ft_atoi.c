/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:51:29 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/04 12:54:45 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_compare(const char *nptr, int neg, long long num)
{
	char const	ll_base[] = "922337203685477580";
	int			i;

	i = -1;
	if (ft_isdigit(nptr[19]) ? 1 : 0)
		return (neg ? 0 : -1);
	while (nptr[++i])
	{
		if (i == 18)
		{
			if (neg)
				return (nptr[i] > '8' ? 0 : num * -1);
			return (nptr[i] > '7' ? -1 : num);
		}
		if (nptr[i] < ll_base[i])
			break ;
		else if (nptr[i] > ll_base[i])
		{
			if (neg)
				return (0);
			return (-1);
		}
	}
	return (neg ? num * -1 : num);
}

static int		ft_isspace(char c)
{
	return (c == ' ' ||
			c == '\t' ||
			c == '\n' ||
			c == '\r' ||
			c == '\f' ||
			c == '\v');
}

int				ft_atoi(const char *nptr)
{
	long long	num;
	int			neg;
	int			digit;

	digit = 0;
	neg = 0;
	num = 0;
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			++neg;
	while (*nptr == '0')
		++nptr;
	while (ft_isdigit(*nptr))
	{
		num = num * 10 + (*nptr - 48);
		if (digit++ == 18)
			return (ft_compare(nptr - digit + 1, neg, num));
		++nptr;
	}
	return (neg ? num * -1 : num);
}
