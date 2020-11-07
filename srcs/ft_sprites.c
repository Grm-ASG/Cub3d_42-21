/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:26:40 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/06 21:18:05 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_sprite_sup(t_sp_vars *sp_vars, int *x, int *y, int *d)
{
	int		color;

	if ((sp_vars->start_x = -sp_vars->width / 2 + sp_vars->scr_x) < 0)
		sp_vars->start_x = 0;
	if ((sp_vars->end_x = sp_vars->width / 2 + sp_vars->scr_x) >= WIN_SIZE_X)
		sp_vars->end_x = WIN_SIZE_X - 1;
	*x = sp_vars->start_x - 1;
	while (++(*x) < sp_vars->end_x)
	{
		sp_vars->tex_x = (int)(256 * (*x - (-sp_vars->width / 2 + \
		sp_vars->scr_x)) * S_SP_TEX_WIDTH / sp_vars->width) / 256;
		if (sp_vars->transform_y > 0 && *x > 0 && *x < WIN_SIZE_X && \
		sp_vars->transform_y < WALL_DIST_ARR[*x] &&\
		(*y = (sp_vars->start_y - 1)) >= -42)
			while (++(*y) < sp_vars->end_y)
			{
				*d = (*y - sp_vars->vert_offset) * 256 - WIN_SIZE_Y * 128 + \
						sp_vars->height * 128;
				sp_vars->tex_y = (*d * S_SP_TEX_HEIGHT / sp_vars->height) / 256;
				color = *(int*)(S_SP_TEX_ADDR + ((sp_vars->tex_x + \
				sp_vars->tex_y * S_SP_TEX_WIDTH) * (S_SP_TEX_BPP / 8)));
				if (color & 0x00FFFFFF)
					my_mlx_pixel_put(*x, *y, color);
			}
	}
}

void	ft_draw_sprite(t_sp *sp)
{
	t_sp_vars	sp_vars;
	int			d[3];

	sp_vars.dist_x = sp->x - PLR_POS_X;
	sp_vars.dist_y = sp->y - PLR_POS_Y;
	sp_vars.inv_factor = 1.0 / (PLR_PLANE_X * PLR_DIR_Y - \
							PLR_PLANE_Y * PLR_DIR_X);
	sp_vars.transform_x = sp_vars.inv_factor * (PLR_DIR_Y * sp_vars.dist_x - \
							PLR_DIR_X * sp_vars.dist_y);
	sp_vars.transform_y = sp_vars.inv_factor * (-PLR_PLANE_Y * sp_vars.dist_x \
							+ PLR_PLANE_X * sp_vars.dist_y);
	sp_vars.scr_x = (int)((WIN_SIZE_X / 2) * (1 + sp_vars.transform_x / \
					sp_vars.transform_y));
	sp_vars.vert_offset = (int)(WIN_SIZE_Y * 0.2 / sp_vars.transform_y);
	if ((sp_vars.height = (int)(WIN_SIZE_Y / sp_vars.transform_y)) < 0)
		sp_vars.height *= -1;
	if ((sp_vars.start_y = -sp_vars.height / 2 + WIN_SIZE_Y \
		/ 2 + sp_vars.vert_offset) < 0)
		sp_vars.start_y = 0;
	if ((sp_vars.end_y = sp_vars.height / 2 + WIN_SIZE_Y / \
		2 + sp_vars.vert_offset) >= WIN_SIZE_Y)
		sp_vars.end_y = WIN_SIZE_Y - 1;
	if ((sp_vars.width = (int)(WIN_SIZE_Y / sp_vars.transform_y)) < 0)
		sp_vars.width *= -1;
	ft_draw_sprite_sup(&sp_vars, &d[2], &d[1], &d[0]);
}

void	ft_help_swap(int *fl_swap, t_sp **sp)
{
	float	tmp_data;

	if ((*sp)->dist < (*sp)->next->dist)
	{
		tmp_data = (float)(*sp)->next->id;
		(*sp)->next->id = (*sp)->id;
		(*sp)->id = (int)tmp_data;
		tmp_data = (*sp)->next->x;
		(*sp)->next->x = (*sp)->x;
		(*sp)->x = tmp_data;
		tmp_data = (*sp)->next->y;
		(*sp)->next->y = (*sp)->y;
		(*sp)->y = tmp_data;
		tmp_data = (*sp)->next->dist;
		(*sp)->next->dist = (*sp)->dist;
		(*sp)->dist = tmp_data;
		*fl_swap = 1;
	}
	(*sp) = (*sp)->next;
}

void	ft_sp_assembly(void)
{
	t_sp	*sp;
	int		fl_swap;

	sp = S_SP_LIST;
	while (sp)
	{
		sp->dist = sqrt(pow(PLR_POS_X - sp->x, 2) + \
						pow(PLR_POS_Y - sp->y, 2));
		sp = sp->next;
	}
	sp = S_SP_LIST;
	fl_swap = 1;
	while (fl_swap)
	{
		fl_swap = 0;
		while (sp->next)
			ft_help_swap(&fl_swap, &sp);
		sp = S_SP_LIST;
	}
	sp = S_SP_LIST;
	while (sp)
	{
		ft_draw_sprite(sp);
		sp = sp->next;
	}
}
