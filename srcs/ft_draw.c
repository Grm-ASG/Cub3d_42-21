/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:27:32 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/06 21:23:48 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_calc_dist_n_hit(void)
{
	WALL_HIT = 0;
	while (!WALL_HIT)
	{
		if (WALL_SIDE_DIST_X < WALL_SIDE_DIST_Y)
		{
			WALL_SIDE_DIST_X += WALL_DLT_DIST_X;
			WALL_MAP_X += WALL_STEP_X;
			WALL_SIDE = (WALL_RAY_DIR_X < 0) ? 2 : 3;
		}
		else
		{
			WALL_SIDE_DIST_Y += WALL_DLT_DIST_Y;
			WALL_MAP_Y += WALL_STEP_Y;
			WALL_SIDE = (WALL_RAY_DIR_Y < 0) ? 0 : 1;
		}
		if (!ft_strchr("02NSWE", MAP[WALL_MAP_Y][WALL_MAP_X]))
			WALL_HIT = 1;
	}
	if (WALL_SIDE > 1)
		WALL_DIST = (WALL_MAP_X - PLR_POS_X + \
				(1 - WALL_STEP_X) / 2) / WALL_RAY_DIR_X;
	else
		WALL_DIST = (WALL_MAP_Y - PLR_POS_Y + \
				(1 - WALL_STEP_Y) / 2) / WALL_RAY_DIR_Y;
}

static void	ft_draw_vert_line(int x)
{
	int			color;
	int			y;

	WALL_LINE_HIGHT = (int)((WIN_SIZE_Y / WALL_DIST) * 1.25);
	WALL_LINE_START = WIN_SIZE_Y / 2 - WALL_LINE_HIGHT / 2;
	if (WALL_LINE_START < 0)
		WALL_LINE_START = 0;
	WALL_LINE_END = WIN_SIZE_Y / 2 + WALL_LINE_HIGHT / 2;
	if (WALL_LINE_END >= WIN_SIZE_Y)
		WALL_LINE_END = WIN_SIZE_Y - 1;
	y = WALL_LINE_START;
	ft_calc_tex();
	while (y <= WALL_LINE_END)
	{
		color = ft_calc_pix_clr_n_tex();
		WALL_TEX_POS += WALL_TEX_STEP;
		my_mlx_pixel_put(x, y++, color);
	}
}

void		ft_draw_walls(void)
{
	int			x;

	ft_bzero(&WALL_S, sizeof(WALL_S));
	WALL_TEX_MIR = 0;
	x = -1;
	while (++x < WIN_SIZE_X)
	{
		WALL_CAM_X = 2 * x / (float)WIN_SIZE_X - 1;
		WALL_RAY_DIR_X = PLR_DIR_X + PLR_PLANE_X * WALL_CAM_X;
		WALL_RAY_DIR_Y = PLR_DIR_Y + PLR_PLANE_Y * WALL_CAM_X;
		WALL_MAP_X = (int)PLR_POS_X;
		WALL_MAP_Y = (int)PLR_POS_Y;
		ft_calc_dlt_dist();
		ft_calc_step_n_side();
		ft_calc_dist_n_hit();
		WALL_DIST_ARR[x] = WALL_DIST;
		ft_draw_vert_line(x);
	}
	if (S_SP_LIST)
		ft_sp_assembly();
}

void		ft_draw_frame(void)
{
	ft_draw_background();
	ft_draw_walls();
	if (MAP_VISION)
		ft_draw_minimap();
	mlx_put_image_to_window(MLX_PTR, MLX_WIN, IMG_PTR, 0, 0);
}

void		ft_draw_background(void)
{
	int			x;
	int			y;

	x = -1;
	while (++x < WIN_SIZE_X)
	{
		y = -1;
		while (++y < (WIN_SIZE_Y / 2))
			my_mlx_pixel_put(x, y, MAP_CEIL);
		while (y < WIN_SIZE_Y)
			my_mlx_pixel_put(x, y++, MAP_FLR);
	}
}
