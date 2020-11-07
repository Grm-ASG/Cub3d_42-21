/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:09:12 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/04 11:39:42 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size * nmemb)))
		return (NULL);
	return (ft_memset(ptr, '\0', size * nmemb));
}
