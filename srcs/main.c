/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:35:23 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/05 22:17:08 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx g_s_mlx;

static void	ft_play(void)
{
	mlx_hook(MLX_WIN, 17, 1L << 17, ft_exit, &MLX);
	mlx_hook(MLX_WIN, 2, 1L << 0, ft_press_key, &MLX);
	mlx_hook(MLX_WIN, 3, 1L << 1, ft_release_key, &MLX);
	mlx_loop_hook(MLX_PTR, ft_buttons, &MLX);
	mlx_loop(MLX_PTR);
}

static void	ft_init_game(void)
{
	const char	view = MAP_PL_STRT_VIEW;
	const float	tan_circle = tan(M_PI * FOV_ANG / 360);

	PLR_POS_X = (float)MAP_PL_STRT_X + 0.5;
	PLR_POS_Y = (float)MAP_PL_STRT_Y + 0.5;
	if (view == 'W')
		ft_init_dir_n_plane(-1, -tan_circle, view);
	else if (view == 'E')
		ft_init_dir_n_plane(1, tan_circle, view);
	else if (view == 'N')
		ft_init_dir_n_plane(-1, tan_circle, view);
	else if (view == 'S')
		ft_init_dir_n_plane(1, -tan_circle, view);
	PLR_SPEED = MOVE_SPEED * 1.5;
	PLR_ROT_SPEED = ROTATE_SPEED * M_PI / 180;
	if (!(WALL_DIST_ARR = (float*)malloc(sizeof(float) * WIN_SIZE_X)))
		ft_error(ALLOCATION_FAIL);
	ft_init_sprites();
}

static void	ft_init_mlx(void)
{
	int bl_hi;
	int bl_wi;

	if (!(MLX_PTR = mlx_init()))
		ft_error(MLX_BAD_RETURN);
	mlx_get_screen_size(MLX_PTR, &WIN_SIZE_X, &WIN_SIZE_Y);
	WIN_SIZE_X = WIN_SIZE_X_MAP < WIN_SIZE_X ? WIN_SIZE_X_MAP : WIN_SIZE_X;
	WIN_SIZE_Y = WIN_SIZE_Y_MAP < WIN_SIZE_Y ? WIN_SIZE_Y_MAP : WIN_SIZE_Y;
	bl_hi = WIN_SIZE_Y / (MAP_HEIGHT - 1) / 4;
	bl_wi = WIN_SIZE_X / MAP_WIDTH / 3;
	MAP_BLOCK_SIZE = bl_hi < bl_wi ? bl_hi : bl_wi;
	if (!MLX_SAVE)
	{
		if (!(MLX_WIN = mlx_new_window(MLX_PTR, WIN_SIZE_X, \
		WIN_SIZE_Y, WIN_NAME)))
			ft_error(MLX_BAD_RETURN);
	}
	if (!(IMG_PTR = mlx_new_image(MLX_PTR, WIN_SIZE_X, WIN_SIZE_Y)))
		ft_error(MLX_BAD_RETURN);
	if (!(IMG_ADDR = mlx_get_data_addr(IMG_PTR, &IMG_BPP, &IMG_LEN, &IMG_END)))
		ft_error(MLX_BAD_RETURN);
	ft_init_tex();
}

int			main(int argc, char **argv)
{
	ft_open_map(argc, argv);
	ft_init_mlx();
	ft_init_game();
	if (MLX_SAVE)
		ft_save_screen();
	ft_play();
	return (0);
}
