/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:20:43 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/06 21:26:39 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_press_key(int key)
{
	if (key == KEY_ESC)
		ft_exit(0);
	else if (key == 'm')
		MAP_VISION = MAP_VISION ? 0 : 1;
	else if (key == KEY_W)
		S_KEY_W = 1;
	else if (key == KEY_A)
		S_KEY_A = 1;
	else if (key == KEY_S)
		S_KEY_S = 1;
	else if (key == KEY_D)
		S_KEY_D = 1;
	else if (key == KEY_LEFT)
		S_KEY_LEFT = 1;
	else if (key == KEY_RIGHT)
		S_KEY_RIGHT = 1;
	return (0);
}

int		ft_release_key(int key)
{
	if (key == KEY_W)
		S_KEY_W = 0;
	else if (key == KEY_A)
		S_KEY_A = 0;
	else if (key == KEY_S)
		S_KEY_S = 0;
	else if (key == KEY_D)
		S_KEY_D = 0;
	else if (key == KEY_LEFT)
		S_KEY_LEFT = 0;
	else if (key == KEY_RIGHT)
		S_KEY_RIGHT = 0;
	return (0);
}

int		ft_buttons(void)
{
	mlx_do_sync(MLX_PTR);
	if (S_KEY_W && !S_KEY_S)
		ft_move(1);
	if (S_KEY_S && !S_KEY_W)
		ft_move(-1);
	if (S_KEY_A && !S_KEY_D)
		ft_strafe(-1);
	if (S_KEY_D && !S_KEY_A)
		ft_strafe(1);
	if (S_KEY_LEFT && !S_KEY_RIGHT)
		ft_rotate(-1);
	if (S_KEY_RIGHT && !S_KEY_LEFT)
		ft_rotate(1);
	ft_draw_frame();
	return (0);
}
