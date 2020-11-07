/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils_sup.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:31:49 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/07 09:56:32 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_hole(int y, int x)
{
	if (MAP[y - 1][x] == ' ' || MAP[y - 1][x] == '\0')
		ft_error(MAP_NOT_CLOSED);
	if (MAP[y + 1][x] == ' ' || MAP[y + 1][x] == '\0')
		ft_error(MAP_NOT_CLOSED);
	if (MAP[y][x + 1] == ' ' || MAP[y][x + 1] == '\0')
		ft_error(MAP_NOT_CLOSED);
	if (MAP[y][x - 1] == ' ' || MAP[y][x - 1] == '\0')
		ft_error(MAP_NOT_CLOSED);
}

void		ft_check_map_valid(void)
{
	int y;
	int x;
	int	len;
	int side;

	y = -1;
	while (++y < MAP_HEIGHT)
	{
		x = -1;
		len = ft_strlen(MAP[y]);
		if (len == 0)
			ft_error(MAP_SOME_TRASH);
		while (++x < len)
		{
			side = y == 0 || y == (MAP_HEIGHT - 1) || x == 0 || x == len - 1;
			if (side && ft_strchr("02NSWE", MAP[y][x]))
				ft_error(MAP_NOT_CLOSED);
			if (ft_strchr("NSWE", MAP[y][x]))
				ft_plr_view(MAP[y][x], y, x);
			if (!side && ft_strchr("02NSWE", MAP[y][x]))
				ft_check_hole(y, x);
			if (!(ft_strchr(" 012NSWE", MAP[y][x])))
				ft_error(MAP_SOME_TRASH);
		}
	}
}

void		ft_check_all_atribute(void)
{
	if (!WIN_SIZE_X_MAP || !WIN_SIZE_Y_MAP)
		ft_error(RESOL_BAD_ERR);
	if (!MAP_TEX_NO)
		ft_error(MAP_NO_TEX_ERR);
	if (!MAP_TEX_SO)
		ft_error(MAP_SO_TEX_ERR);
	if (!MAP_TEX_WE)
		ft_error(MAP_WE_TEX_ERR);
	if (!MAP_TEX_EA)
		ft_error(MAP_EA_TEX_ERR);
	if (!MAP_TEX_SP)
		ft_error(MAP_SP_TEX_ERR);
	if (!MAP_FLR_FL)
		ft_error(MAP_FLR_ERR);
	if (!MAP_CEIL_FL)
		ft_error(MAP_CEIL_ERR);
	ft_check_map_valid();
	if (!MAP_PL_STRT_VIEW)
		ft_error(MAP_PL_STR_VEIW_ERR);
}

void		ft_define_tex(char **tex, char *line, int num)
{
	int i;

	i = 0;
	line = ft_miss_sp(&line[num]);
	if (*tex)
		ft_error(MAP_TEX_REPEAT_ERR);
	if (!(*tex = ft_strdup(line)))
		ft_error(ALLOCATION_FAIL);
	while (!ft_isspace_sp_t_vt(tex[0][i]) && (tex[0][i] != '\0'))
		++i;
	if (tex[0][i] == '\0')
		return ;
	tex[0][i++] = '\0';
	while (ft_isspace_sp_t_vt(tex[0][i]))
		++i;
	if (tex[0][i] != '\0')
		ft_error(BAD_TEX_IN_GAME);
}

void		ft_alloc_map(void)
{
	if (!MAP_SIZE)
		MAP_SIZE = START_MAP_SIZE;
	else
		MAP_SIZE <<= 1;
	if (!(MAP = (char **)malloc(sizeof(char *) * MAP_SIZE)))
		ft_error(ALLOCATION_FAIL);
	ft_bzero(MAP, sizeof(char *) * MAP_SIZE);
}
