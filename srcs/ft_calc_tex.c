/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:29:33 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/06 22:17:45 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_textures(void)
{
	int fd;

	if ((fd = open(MAP_TEX_NO, O_RDONLY)) < 0)
		ft_error(MAP_BAD_TEX_ERR);
	if ((close(fd) < 0))
		ft_error(BAD_FILE_DESCRIPTOR);
	if ((fd = open(MAP_TEX_SO, O_RDONLY)) < 0)
		ft_error(MAP_BAD_TEX_ERR);
	if ((close(fd) < 0))
		ft_error(BAD_FILE_DESCRIPTOR);
	if ((fd = open(MAP_TEX_WE, O_RDONLY)) < 0)
		ft_error(MAP_BAD_TEX_ERR);
	if ((close(fd) < 0))
		ft_error(BAD_FILE_DESCRIPTOR);
	if ((fd = open(MAP_TEX_EA, O_RDONLY)) < 0)
		ft_error(MAP_BAD_TEX_ERR);
	if ((close(fd) < 0))
		ft_error(BAD_FILE_DESCRIPTOR);
	if ((fd = open(MAP_TEX_SP, O_RDONLY)) < 0)
		ft_error(MAP_BAD_TEX_ERR);
	if ((close(fd) < 0))
		ft_error(BAD_FILE_DESCRIPTOR);
}

void	ft_init_tex_addr(void)
{
	if (!(S_NO_TEX_ADDR = mlx_get_data_addr(S_NO_TEX_IMG_PTR, \
		&S_NO_TEX_BPP, &S_NO_TEX_LINE_LEN, &S_NO_TEX_ENDIAN)))
		ft_error(BAD_TEX_IN_GAME);
	if (!(S_SO_TEX_ADDR = mlx_get_data_addr(S_SO_TEX_IMG_PTR, \
		&S_SO_TEX_BPP, &S_SO_TEX_LINE_LEN, &S_SO_TEX_ENDIAN)))
		ft_error(BAD_TEX_IN_GAME);
	if (!(S_WE_TEX_ADDR = mlx_get_data_addr(S_WE_TEX_IMG_PTR, \
		&S_WE_TEX_BPP, &S_WE_TEX_LINE_LEN, &S_WE_TEX_ENDIAN)))
		ft_error(BAD_TEX_IN_GAME);
	if (!(S_EA_TEX_ADDR = mlx_get_data_addr(S_EA_TEX_IMG_PTR, \
		&S_EA_TEX_BPP, &S_EA_TEX_LINE_LEN, &S_EA_TEX_ENDIAN)))
		ft_error(BAD_TEX_IN_GAME);
	if (!(S_SP_TEX_ADDR = mlx_get_data_addr(S_SP_TEX_IMG_PTR, \
		&S_SP_TEX_BPP, &S_SP_TEX_LINE_LEN, &S_SP_TEX_ENDIAN)))
		ft_error(BAD_TEX_IN_GAME);
}

void	ft_init_tex(void)
{
	if (!(S_NO_TEX_IMG_PTR = mlx_xpm_file_to_image(MLX_PTR, \
		MAP_TEX_NO, &S_NO_TEX_WIDTH, &S_NO_TEX_HEIGHT)))
		ft_error(BAD_TEX_IN_GAME);
	if (!(S_SO_TEX_IMG_PTR = mlx_xpm_file_to_image(MLX_PTR, \
		MAP_TEX_SO, &S_SO_TEX_WIDTH, &S_SO_TEX_HEIGHT)))
		ft_error(BAD_TEX_IN_GAME);
	if (!(S_WE_TEX_IMG_PTR = mlx_xpm_file_to_image(MLX_PTR, \
		MAP_TEX_WE, &S_WE_TEX_WIDTH, &S_WE_TEX_HEIGHT)))
		ft_error(BAD_TEX_IN_GAME);
	if (!(S_EA_TEX_IMG_PTR = mlx_xpm_file_to_image(MLX_PTR, \
		MAP_TEX_EA, &S_EA_TEX_WIDTH, &S_EA_TEX_HEIGHT)))
		ft_error(BAD_TEX_IN_GAME);
	if (!(S_SP_TEX_IMG_PTR = mlx_xpm_file_to_image(MLX_PTR, \
		MAP_TEX_SP, &S_SP_TEX_WIDTH, &S_SP_TEX_HEIGHT)))
		ft_error(BAD_TEX_IN_GAME);
	ft_init_tex_addr();
}

int		ft_calc_pix_clr_n_tex(void)
{
	t_img	*tex_img;

	tex_img = NULL;
	if (WALL_SIDE == 0)
		tex_img = &S_NO_TEX;
	else if (WALL_SIDE == 1)
		tex_img = &S_SO_TEX;
	else if (WALL_SIDE == 2)
		tex_img = &S_WE_TEX;
	else if (WALL_SIDE == 3)
		tex_img = &S_EA_TEX;
	WALL_TEX_Y = (int)WALL_TEX_POS & (tex_img->height - 1);
	return (*(int*)(tex_img->addr + ((WALL_TEX_X + (WALL_TEX_Y * \
				tex_img->width)) * (tex_img->bits_per_pixel / 8))));
}

void	ft_calc_tex(void)
{
	t_img	*tex_img;

	tex_img = NULL;
	WALL_X = (WALL_SIDE > 1) ? PLR_POS_Y + \
		WALL_DIST * WALL_RAY_DIR_Y : PLR_POS_X + \
		WALL_DIST * WALL_RAY_DIR_X;
	WALL_X -= (int)(WALL_X);
	if (WALL_SIDE == 0)
		tex_img = &S_NO_TEX;
	else if (WALL_SIDE == 1)
		tex_img = &S_SO_TEX;
	else if (WALL_SIDE == 2)
		tex_img = &S_WE_TEX;
	else if (WALL_SIDE == 3)
		tex_img = &S_EA_TEX;
	WALL_TEX_MIR = (WALL_SIDE == 1 || WALL_SIDE == 2) ? 1 : 0;
	WALL_TEX_X = (!WALL_TEX_MIR) ? (int)(WALL_X * \
		(float)(tex_img->width)) : (int)((float)(tex_img->width) - \
		WALL_X * (float)(tex_img->width) - 1);
	WALL_TEX_STEP = 1.0 * tex_img->height / WALL_LINE_HIGHT;
	WALL_TEX_POS = (WALL_LINE_START - WIN_SIZE_Y / 2 + \
							WALL_LINE_HIGHT / 2) * WALL_TEX_STEP;
}
