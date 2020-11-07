/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:13:44 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/07 10:45:46 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_cube(int x, int y, unsigned int *img_addr)
{
	int k;
	int z;

	k = -1;
	while (++k < MAP_BLOCK_SIZE)
	{
		z = -1;
		while (++z < MAP_BLOCK_SIZE)
		{
			if (MAP[y][x] == '1')
				img_addr[k * WIN_SIZE_X + z + (y * WIN_SIZE_X * \
						MAP_BLOCK_SIZE) + (x * MAP_BLOCK_SIZE)] = BLUE;
			else if (MAP[y][x] == '0' || ft_strchr("NESW2", MAP[y][x]))
				img_addr[k * WIN_SIZE_X + z + (y * WIN_SIZE_X * \
						MAP_BLOCK_SIZE) + (x * MAP_BLOCK_SIZE)] = BLACK;
			if (MAP[y][x] == '2' && (k > MAP_BLOCK_SIZE / 3 && \
			k < MAP_BLOCK_SIZE * 2 / 3) && (z > MAP_BLOCK_SIZE / 3 && \
			z < MAP_BLOCK_SIZE * 2 / 3))
				img_addr[k * WIN_SIZE_X + z + (y * WIN_SIZE_X * \
						MAP_BLOCK_SIZE) + (x * MAP_BLOCK_SIZE)] = RED;
			if (y == (int)PLR_POS_Y && x == (int)PLR_POS_X)
				img_addr[k * WIN_SIZE_X + z + (y * WIN_SIZE_X * \
				MAP_BLOCK_SIZE) + (x * MAP_BLOCK_SIZE)] = GREEN;
		}
	}
}

void		ft_draw_minimap(void)
{
	unsigned int	*img_addr;
	int				x;
	int				y;
	int				len;

	y = -1;
	img_addr = (unsigned int *)IMG_ADDR;
	while (++y < MAP_HEIGHT)
	{
		x = -1;
		len = ft_strlen(MAP[y]);
		while (++x < len)
			ft_draw_cube(x, y, img_addr);
	}
}
