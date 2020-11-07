/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:14:27 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/07 10:06:45 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isspace_sp_t_vt(char c)
{
	return (c == ' ' ||
			c == '\t' ||
			c == '\v');
}

char	*ft_miss_sp(char *line)
{
	while (ft_isspace_sp_t_vt(*line) && *line)
		++line;
	return (line);
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char		*dst;

	dst = IMG_ADDR + (y * IMG_LEN + x * (IMG_BPP / 8));
	*(unsigned int*)dst = color;
}

void	ft_gnl_sup(int exit, char **line)
{
	free(*line);
	*line = NULL;
	if (exit == -1)
		ft_error(GNL_ERROR_RETURN);
}

void	ft_putendl_fd_err(char *line)
{
	ft_putendl_fd("Error", FD_ERR);
	ft_putendl_fd(line, FD_ERR);
}
