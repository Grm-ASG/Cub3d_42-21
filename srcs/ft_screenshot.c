/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:17:07 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/06 22:18:16 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_filename_helper(char **name, char **id, int fd, char **tmp)
{
	static int		i;

	free(*name);
	if (close(fd) < 0)
		ft_error(BAD_SCREEN_SHOT);
	if (!(*id = ft_itoa(++i)))
		ft_error(ALLOCATION_FAIL);
	if (!(*name = ft_substr(MAP_NAME, 0, ft_strlen(MAP_NAME) - 4)))
	{
		free(*id);
		ft_error(ALLOCATION_FAIL);
	}
	if (!(*tmp = ft_strjoin(*name, *id)))
	{
		free(*id);
		free(*name);
		ft_error(ALLOCATION_FAIL);
	}
	free(*name);
	free(*id);
	if (!(*name = ft_strjoin(*tmp, ".bmp")))
		ft_error(ALLOCATION_FAIL);
	free(*tmp);
}

static char	*ft_screen_filename(void)
{
	int		fd;
	char	*filename;
	char	*id;
	char	*tmp;

	if (!(filename = ft_substr(MAP_NAME, 0, ft_strlen(MAP_NAME) - 4)))
		return (NULL);
	tmp = filename;
	filename = ft_strjoin(filename, ".bmp");
	free(tmp);
	while ((fd = open(filename, O_RDONLY)) > 0)
		ft_filename_helper(&filename, &id, fd, &tmp);
	return (filename);
}

static void	ft_bmp_image_write(char *bitmap_file_header, char *dib_header)
{
	int		fd;
	char	*filename;
	int		i;
	int		win_width;

	i = -1;
	win_width = IMG_BPP / 8 * WIN_SIZE_X;
	if (!(filename = ft_screen_filename()))
		ft_error(ALLOCATION_FAIL);
	if ((fd = open(filename, O_RDWR | O_CREAT, 0664)) < 0)
		ft_error(BAD_SCREEN_SHOT);
	write(fd, bitmap_file_header, 14);
	write(fd, dib_header, 40);
	while (++i < WIN_SIZE_Y)
		write(fd, IMG_ADDR + i * IMG_LEN, win_width);
	ft_putstr_fd(filename, 1);
	ft_putstr_fd(" saved\n", 1);
	free(filename);
	if (close(fd) < 0)
		ft_error(BAD_SCREEN_SHOT);
}

static void	ft_bmp_head_gen(char *bitmap_file_header, char *dib_header)
{
	int		file_size;

	file_size = 14 + 40 + WIN_SIZE_X * WIN_SIZE_Y * IMG_BPP / 8;
	bitmap_file_header[0] = 'B';
	bitmap_file_header[1] = 'M';
	bitmap_file_header[2] = (char)(file_size);
	bitmap_file_header[3] = (char)(file_size >> 8);
	bitmap_file_header[4] = (char)(file_size >> 16);
	bitmap_file_header[5] = (char)(file_size >> 24);
	bitmap_file_header[10] = (char)(14 + 40);
	dib_header[0] = (char)(40);
	dib_header[4] = (char)(WIN_SIZE_X);
	dib_header[5] = (char)(WIN_SIZE_X >> 8);
	dib_header[6] = (char)(WIN_SIZE_X >> 16);
	dib_header[7] = (char)(WIN_SIZE_X >> 24);
	dib_header[8] = (char)(-WIN_SIZE_Y);
	dib_header[9] = (char)(-WIN_SIZE_Y >> 8);
	dib_header[10] = (char)(-WIN_SIZE_Y >> 16);
	dib_header[11] = (char)(-WIN_SIZE_Y >> 24);
	dib_header[12] = (char)(1);
	dib_header[14] = (char)(IMG_BPP);
}

void		ft_save_screen(void)
{
	char	bitmap_file_header[14];
	char	dib_header[40];

	ft_bzero(bitmap_file_header, 14);
	ft_bzero(dib_header, 40);
	ft_draw_background();
	ft_draw_walls();
	ft_bmp_head_gen(bitmap_file_header, dib_header);
	ft_bmp_image_write(bitmap_file_header, dib_header);
	ft_exit(0);
}
