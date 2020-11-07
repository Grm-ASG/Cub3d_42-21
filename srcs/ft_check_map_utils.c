/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:32:17 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/07 10:26:15 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_prepare_map(int *j)
{
	char	**map;
	int		i;

	map = MAP;
	i = 0;
	while (map[i] && i < MAP_SIZE - 1)
		++i;
	*j = i;
	if (i == MAP_SIZE - 1)
	{
		ft_alloc_map();
		while (1)
		{
			MAP[i] = map[i];
			if (i-- == 0)
				break ;
		}
		free(map);
	}
}

void		ft_check_map(int len)
{
	int		j;

	j = 0;
	MAP_WIDTH = len > MAP_WIDTH ? len : MAP_WIDTH;
	if (!MAP)
		ft_alloc_map();
	else
		ft_prepare_map(&j);
	MAP[j] = MAP_LINE_CPY;
	++MAP_HEIGHT;
}

void		ft_check_tex(char *line)
{
	if (!(ft_strncmp(line, "NO", 2)))
		ft_define_tex(&MAP_TEX_NO, line, 2);
	else if (!(ft_strncmp(line, "SO", 2)))
		ft_define_tex(&MAP_TEX_SO, line, 2);
	else if (!(ft_strncmp(line, "WE", 2)))
		ft_define_tex(&MAP_TEX_WE, line, 2);
	else if (!(ft_strncmp(line, "EA", 2)))
		ft_define_tex(&MAP_TEX_EA, line, 2);
	else if (!(ft_strncmp(line, "S", 1)))
		ft_define_tex(&MAP_TEX_SP, line, 1);
	else
		ft_error(MAP_BAD_TEX_ERR);
}

void		ft_check_atrib(char *line)
{
	char	*tmp;
	int		color;

	if (*line == 'R' && ft_isspace_sp_t_vt(line[1]))
		ft_parse_rsltn(&line[2]);
	else if (((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
		!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)) &&
		ft_isspace_sp_t_vt(line[2])) || (!ft_strncmp(line, "S", 1) &&
		ft_isspace_sp_t_vt(line[1])))
		ft_check_tex(line);
	else if ((*line == 'F' || *line == 'C') && ft_isspace_sp_t_vt(line[1]))
	{
		color = 0;
		tmp = ft_miss_sp(&line[2]);
		if (*line == 'F' && MAP_FLR_FL)
			ft_error(MAP_FLR_ERR);
		if (*line == 'C' && MAP_CEIL_FL)
			ft_error(MAP_CEIL_ERR);
		ft_check_fl_cl(tmp, color, *line);
	}
	else if (*line != '\n' && *line != 0)
		ft_error(MAP_SOME_TRASH);
	free(MAP_LINE_CPY);
	MAP_LINE_CPY = NULL;
}

void		ft_check_fl_cl(char *line, int color, char type)
{
	if (type == 'F')
		MAP_FLR_FL = 1;
	if (type == 'C')
		MAP_CEIL_FL = 1;
	if (ft_isdigit(*line))
	{
		color = ft_get_byte_clr(&line) << 16;
		line = ft_miss_sp(line);
		if (*line == ',')
			line++;
		color |= ft_get_byte_clr(&line) << 8;
		line = ft_miss_sp(line);
		if (*line == ',')
			line++;
		color |= ft_get_byte_clr(&line);
		line = ft_miss_sp(line);
		if (*line != '\0')
			ft_error(MAP_FLR_CEIL_ERR);
	}
	else
		ft_error(MAP_FLR_CEIL_ERR);
	if (type == 'F')
		MAP_FLR = color;
	else if (type == 'C')
		MAP_CEIL = color;
}
