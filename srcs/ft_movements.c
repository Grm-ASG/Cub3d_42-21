/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:21:32 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/06 21:56:39 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(int dir)
{
	if (ft_strchr("0NSWE", MAP[(int)PLR_POS_Y]	\
		[(int)(PLR_POS_X + dir * (PLR_DIR_X * PLR_SPEED))]))
		PLR_POS_X += dir * (PLR_DIR_X * PLR_SPEED);
	if (ft_strchr("0NSWE", MAP[(int)(PLR_POS_Y + dir * \
		(PLR_DIR_Y * PLR_SPEED))][(int)PLR_POS_X]))
		PLR_POS_Y += dir * (PLR_DIR_Y * PLR_SPEED);
}

void	ft_strafe(int dir)
{
	if (ft_strchr("0NSWE", MAP[(int)PLR_POS_Y]	\
	[(int)(PLR_POS_X + dir * (PLR_PLANE_X * PLR_SPEED))]))
		PLR_POS_X += dir * (PLR_PLANE_X * PLR_SPEED);
	if (ft_strchr("0NSWE", MAP\
		[(int)(PLR_POS_Y + dir * (PLR_PLANE_Y * PLR_SPEED))][(int)PLR_POS_X]))
		PLR_POS_Y += dir * (PLR_PLANE_Y * PLR_SPEED);
}

void	ft_rotate(int dir)
{
	PLR_OLD_DIR_X = PLR_DIR_X;
	PLR_DIR_X = PLR_DIR_X * cos(dir * PLR_ROT_SPEED) - \
						PLR_DIR_Y * sin(dir * PLR_ROT_SPEED);
	PLR_DIR_Y = PLR_OLD_DIR_X * sin(dir * PLR_ROT_SPEED) + \
						PLR_DIR_Y * cos(dir * PLR_ROT_SPEED);
	PLR_OLD_PLANE_X = PLR_PLANE_X;
	PLR_PLANE_X = PLR_PLANE_X * cos(dir * PLR_ROT_SPEED) - \
						PLR_PLANE_Y * sin(dir * PLR_ROT_SPEED);
	PLR_PLANE_Y = PLR_OLD_PLANE_X * sin(dir * PLR_ROT_SPEED) \
						+ PLR_PLANE_Y * cos(dir * PLR_ROT_SPEED);
}
