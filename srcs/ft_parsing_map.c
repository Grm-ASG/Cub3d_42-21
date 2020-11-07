/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:29:43 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/06 22:07:43 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_rsltn_min(int min_resol, int *resol, char **line)
{
	int num;

	if (((num = ft_atoi(*line)) < min_resol))
		ft_error(RESOL_BAD_ERR);
	*resol = num;
	while (ft_isdigit(**line))
		++(*line);
}

void		ft_parse_rsltn(char *line)
{
	if (WIN_SIZE_X_MAP || WIN_SIZE_Y_MAP)
		ft_error(RESOL_BAD_REPEAT_ERR);
	line = ft_miss_sp(line);
	if (ft_isdigit(*line) && *line != '0')
		ft_check_rsltn_min(MIN_RESOLUTION_X, &WIN_SIZE_X_MAP, &line);
	else
		ft_error(RESOL_BAD_ERR);
	line = ft_miss_sp(line);
	if (ft_isdigit(*line) && *line != '0')
		ft_check_rsltn_min(MIN_RESOLUTION_Y, &WIN_SIZE_Y_MAP, &line);
	else
		ft_error(RESOL_BAD_ERR);
	if (!WIN_SIZE_X_MAP || !WIN_SIZE_Y_MAP)
		ft_error(RESOL_BAD_ERR);
	line = ft_miss_sp(line);
	if (*line != '\0')
		ft_error(RESOL_BAD_ERR);
}

void		ft_parse_map_line(char *line)
{
	int const len = ft_strlen(line);

	if (!(MAP_LINE_CPY = ft_strdup(line)))
		ft_error(ALLOCATION_FAIL);
	line = ft_miss_sp(line);
	if (MAP || *line == '1')
		ft_check_map(len);
	else
		ft_check_atrib(line);
}

void		ft_parse_map(int fd)
{
	char	*line;
	int		err;

	if (!MAP_NAME)
		ft_error(ALLOCATION_FAIL);
	while (1)
	{
		if ((err = get_next_line(fd, &line)) == -1)
			ft_gnl_sup(err, &line);
		ft_parse_map_line(line);
		ft_gnl_sup(err, &line);
		if (err == 0)
			break ;
	}
	ft_check_all_atribute();
	ft_check_textures();
}

void		ft_open_map(int argc, char **argv)
{
	int fd;
	int len;

	ft_bzero(&MLX, sizeof(t_mlx));
	if (argc == 1 || argc > 3)
		ft_error(ARG_WRONG);
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], "--save"))
			MLX_SAVE = 1;
		else
			ft_error(ARG_THIRD_WRONG);
	}
	len = ft_strlen(argv[1]);
	len = len < 4 ? 0 : len - 4;
	if (len == 0 || ft_strncmp(&argv[1][len], ".cub", 4))
		ft_error(ARG_CUB_WRONG);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(ARG_MAP_FD_ERR);
	if (argv[1][0] == '.' || argv[1][0] == '/' || ft_strrchr(argv[1], '/'))
		MAP_NAME = ft_strdup(ft_strrchr(argv[1], '/') + 1);
	else
		MAP_NAME = ft_strdup(argv[1]);
	ft_parse_map(fd);
}
