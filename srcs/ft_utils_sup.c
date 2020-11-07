/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:56:02 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/06 16:37:32 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_dlt_dist(void)
{
	if (!WALL_RAY_DIR_Y)
		WALL_DLT_DIST_X = 0;
	else
		WALL_DLT_DIST_X = (!WALL_RAY_DIR_X) ? 1 : fabs(1 / WALL_RAY_DIR_X);
	if (!WALL_RAY_DIR_X)
		WALL_DLT_DIST_Y = 0;
	else
		WALL_DLT_DIST_Y = (!WALL_RAY_DIR_Y) ? 1 : fabs(1 / WALL_RAY_DIR_Y);
}

void	ft_init_dir_n_plane(float dir, float plane, char side)
{
	if (side == 'N' || side == 'S')
	{
		PLR_DIR_Y = dir;
		PLR_PLANE_X = plane;
	}
	else
	{
		PLR_DIR_X = dir;
		PLR_PLANE_Y = plane;
	}
}

void	ft_calc_step_n_side(void)
{
	if (WALL_RAY_DIR_X < 0)
	{
		WALL_STEP_X = -1;
		WALL_SIDE_DIST_X = (PLR_POS_X - WALL_MAP_X) * WALL_DLT_DIST_X;
	}
	else
	{
		WALL_STEP_X = 1;
		WALL_SIDE_DIST_X = (1.0 + WALL_MAP_X - PLR_POS_X) * WALL_DLT_DIST_X;
	}
	if (WALL_RAY_DIR_Y < 0)
	{
		WALL_STEP_Y = -1;
		WALL_SIDE_DIST_Y = (PLR_POS_Y - WALL_MAP_Y) * WALL_DLT_DIST_Y;
	}
	else
	{
		WALL_STEP_Y = 1;
		WALL_SIDE_DIST_Y = (1.0 + WALL_MAP_Y - PLR_POS_Y) * WALL_DLT_DIST_Y;
	}
}

void	ft_plr_view(char view, int y, int x)
{
	if (MAP_PL_STRT_VIEW)
		ft_error(MAP_PL_STR_VEIW_ERR);
	MAP_PL_STRT_VIEW = view;
	MAP_PL_STRT_Y = y;
	MAP_PL_STRT_X = x;
}

void	ft_help(void)
{
	ft_putstr_fd("\n\t\tUsage:\t\t./cub3D [MAP] [OPTION]\n\
		Example:\t./cub3D map.cub --save\n", 2);
}
