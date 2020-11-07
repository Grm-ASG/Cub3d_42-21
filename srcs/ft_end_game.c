/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:05:43 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/07 10:53:02 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free(int i)
{
	if (MLX_WIN)
		mlx_destroy_window(MLX_PTR, MLX_WIN);
	free(MLX_PTR);
	free(MAP_NAME);
	free(MLX_WIN);
	free(MAP_TEX_SP);
	free(MAP_TEX_NO);
	free(MAP_TEX_SO);
	free(MAP_TEX_WE);
	free(MAP_TEX_EA);
	free(WALL_DIST_ARR);
	if (S_SP_LIST)
		ft_free_sprite_list();
	if (MAP)
		while (MAP[++i])
		{
			free(MAP[i]);
			MAP[i] = NULL;
			MAP_LINE_CPY = NULL;
		}
	free(MAP);
	MAP = NULL;
	free(MAP_LINE_CPY);
}

int			ft_exit(int exit_code)
{
	int i;

	i = -1;
	if (MLX_WIN)
		mlx_destroy_window(MLX_PTR, MLX_WIN);
	MLX_WIN = NULL;
	ft_free(i);
	exit(exit_code);
}

static void	ft_error_2(int err_code)
{
	if (err_code == MAP_NOT_CLOSED)
		ft_putendl_fd_err("Invalid map!");
	else if (err_code == BAD_SCREEN_SHOT)
		ft_putendl_fd_err("Somsing goes wrong while screenshot");
	else if (err_code == BAD_FILE_DESCRIPTOR)
		ft_putendl_fd_err("Something goes wrong when close fd");
	ft_exit(err_code);
}

static void	ft_error_1(int err_code)
{
	if (err_code >= 23)
		ft_error_2(err_code);
	if (err_code == MAP_SP_TEX_ERR)
		ft_putendl_fd_err("Bad Sprite texture in \"*.cub\" file");
	else if (err_code == MAP_FLR_ERR)
		ft_putendl_fd_err("Bad Floor color in \"*.cub\" file");
	else if (err_code == MAP_CEIL_ERR)
		ft_putendl_fd_err("Bad Ceiling color in \"*.cub\" file");
	else if (err_code == MAP_PL_STR_VEIW_ERR)
		ft_putendl_fd_err("Something bad with player view in \"*.cub\" file");
	else if (err_code == RESOL_BAD_REPEAT_ERR)
		ft_putendl_fd_err("Double definition of Resolution in \"*.cub\" file");
	else if (err_code == MAP_SOME_TRASH)
		ft_putendl_fd_err("Some trash simbols in \"*.cub\" file");
	else if (err_code == MAP_FLR_CEIL_ERR)
		ft_putendl_fd_err("Something bad with ceil or floor in \"*.cub\" file");
	else if (err_code == MAP_BAD_TEX_ERR)
		ft_putendl_fd_err("Something bad with textures in \"*.cub\" file");
	else if (err_code == MAP_TEX_REPEAT_ERR)
		ft_putendl_fd_err("Repeat textures in \"*.cub\" file");
	else if (err_code == MLX_BAD_RETURN)
		ft_putendl_fd_err("Mlx return NULL ¯\\_(ツ)_/¯");
	else if (err_code == BAD_TEX_IN_GAME)
		ft_putendl_fd_err("Something bad whith textures");
	ft_exit(err_code);
}

void		ft_error(int err_code)
{
	if (err_code >= 11)
		ft_error_1(err_code);
	if (err_code == ARG_WRONG)
		ft_help();
	else if (err_code == ARG_THIRD_WRONG)
		ft_putendl_fd_err("The 3rd ARG can be only \"--save\"");
	else if (err_code == ARG_CUB_WRONG)
		ft_putendl_fd_err("Not a cube map");
	else if (err_code == ARG_MAP_FD_ERR)
		ft_putendl_fd_err("File dicsriptor error\nCan't open \"*.cub\" file.");
	else if (err_code == GNL_ERROR_RETURN)
		ft_putendl_fd_err("Error while reading from map!");
	else if (err_code == ALLOCATION_FAIL)
		ft_putendl_fd_err("Error while trying allocate some memory");
	else if (err_code == RESOL_BAD_ERR)
		ft_putendl_fd_err("Bad screen Resolution in \"*.cub\" file");
	else if (err_code == MAP_NO_TEX_ERR)
		ft_putendl_fd_err("Bad North texture in \"*.cub\" file");
	else if (err_code == MAP_SO_TEX_ERR)
		ft_putendl_fd_err("Bad South texture in \"*.cub\" file");
	else if (err_code == MAP_WE_TEX_ERR)
		ft_putendl_fd_err("Bad West texture in \"*.cub\" file");
	else if (err_code == MAP_EA_TEX_ERR)
		ft_putendl_fd_err("Bad East texture in \"*.cub\" file");
	ft_exit(err_code);
}
