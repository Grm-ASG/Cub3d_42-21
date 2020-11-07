/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_n_check_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:00:06 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/07 10:23:20 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_free_sprite_list(void)
{
	t_sp	*tmp;
	t_sp	*prev;
	t_sp	*next;

	tmp = S_SP_LIST;
	next = tmp->next;
	while (tmp->prev)
	{
		prev = tmp->prev;
		free(tmp);
		tmp = prev;
	}
	tmp = next;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
	free(S_SP_LIST);
}

static void	ft_sprite_add_front(t_sp *sp)
{
	t_sp	*new_sp;

	if (S_SP_LIST && sp)
	{
		new_sp = sp;
		new_sp->next = S_SP_LIST;
		S_SP_LIST->prev = new_sp;
		S_SP_LIST = new_sp;
	}
}

void		ft_init_sprites(void)
{
	t_sp	*sp;
	int		k;
	int		y;
	int		x;

	y = 0;
	k = 0;
	while (++y < MAP_HEIGHT - 1 && !(x = 0))
	{
		while (MAP[y][++x])
			if (MAP[y][x] == '2')
			{
				if (!(sp = (t_sp*)malloc(sizeof(t_sp))))
					ft_error(ALLOCATION_FAIL);
				ft_bzero(sp, sizeof(t_sp));
				sp->id = ++k;
				sp->x = (float)x + 0.5;
				sp->y = (float)y + 0.5;
				if (S_SP_LIST)
					ft_sprite_add_front(sp);
				else
					S_SP_LIST = sp;
			}
	}
}

int			ft_get_byte_clr(char **line)
{
	int res;

	if (!**line || !ft_isdigit(**line) || (**line == '0' && line[0][1] == '0'))
		ft_error(MAP_FLR_CEIL_ERR);
	if (**line == '0')
	{
		if (line[0][1] == '\0')
		{
			(*line)++;
			return (0);
		}
		if (!ft_isspace_sp_t_vt(line[0][1]) && line[0][1] != ',')
			ft_error(MAP_FLR_CEIL_ERR);
		res = 0;
	}
	else if ((res = ft_atoi(*line)) > 255)
		ft_error(MAP_FLR_CEIL_ERR);
	while (ft_isdigit(**line))
		(*line)++;
	return (res);
}
