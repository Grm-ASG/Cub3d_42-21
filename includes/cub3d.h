/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:53:25 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/07 10:01:14 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define XK_MISCELLANY
# define XK_LATIN1

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <X11/keysymdef.h>

# include "libft.h"
# include "get_next_line.h"

# define KEY_ESC				XK_Escape
# define KEY_W					XK_w
# define KEY_A					XK_a
# define KEY_S					XK_s
# define KEY_D					XK_d
# define KEY_M					XK_m
# define KEY_LEFT				XK_Left
# define KEY_RIGHT				XK_Right

# define WIN_NAME				"cub3D"

# define RED					0x00FF0000
# define GREEN					0x0000FF00
# define BLUE					0x000000FF
# define BLACK					0x00000000
# define WHITE					0x00FFFFFF

# define MIN_RESOLUTION_X		100
# define MIN_RESOLUTION_Y		100

# define FOV_ANG				66
# define MOVE_SPEED				0.05
# define ROTATE_SPEED			1

# define FD_ERR					2
# define START_MAP_SIZE			8

# define ARG_WRONG				1
# define ARG_THIRD_WRONG		2
# define ARG_CUB_WRONG			3
# define ARG_MAP_FD_ERR			4
# define GNL_ERROR_RETURN		5
# define RESOL_BAD_ERR			6
# define MAP_NO_TEX_ERR			7
# define MAP_SO_TEX_ERR			8
# define MAP_WE_TEX_ERR			9
# define MAP_EA_TEX_ERR			10
# define MAP_SP_TEX_ERR			11
# define MAP_FLR_ERR			12
# define MAP_CEIL_ERR			13
# define MAP_PL_STR_VEIW_ERR	14
# define ALLOCATION_FAIL		15
# define RESOL_BAD_REPEAT_ERR	16
# define MAP_SOME_TRASH			17
# define MAP_FLR_CEIL_ERR		18
# define MAP_BAD_TEX_ERR		19
# define MAP_TEX_REPEAT_ERR		20
# define MLX_BAD_RETURN			21
# define BAD_TEX_IN_GAME		22
# define MAP_NOT_CLOSED			23
# define BAD_SCREEN_SHOT		24
# define BAD_FILE_DESCRIPTOR	25

# define MLX					g_s_mlx
# define MLX_SAVE				g_s_mlx.save

# define WIN_SIZE_X				g_s_mlx.s_win.width
# define WIN_SIZE_X_MAP			g_s_mlx.s_win.width_map
# define WIN_SIZE_Y				g_s_mlx.s_win.higth
# define WIN_SIZE_Y_MAP			g_s_mlx.s_win.higth_map

# define MAP					g_s_mlx.s_map.map
# define MAP_NAME				g_s_mlx.s_map.map_name
# define MAP_SIZE				g_s_mlx.s_map.map_size
# define MAP_LINE_CPY  			g_s_mlx.s_map.line_cpy
# define MAP_VISION				g_s_mlx.s_map.map_visible
# define MAP_PL_STRT_VIEW 		g_s_mlx.s_map.pl_start_view
# define MAP_PL_STRT_X  		g_s_mlx.s_map.pl_start_x
# define MAP_PL_STRT_Y  		g_s_mlx.s_map.pl_start_y

# define MAP_TEX_NO				g_s_mlx.s_map.no_tex
# define MAP_TEX_SO				g_s_mlx.s_map.so_tex
# define MAP_TEX_WE				g_s_mlx.s_map.we_tex
# define MAP_TEX_EA				g_s_mlx.s_map.ea_tex
# define MAP_TEX_SP				g_s_mlx.s_map.sp_tex

# define MAP_WIDTH				g_s_mlx.s_map.width
# define MAP_HEIGHT				g_s_mlx.s_map.height
# define MAP_CEIL				g_s_mlx.s_map.ceil
# define MAP_FLR				g_s_mlx.s_map.flr
# define MAP_CEIL_FL			g_s_mlx.s_map.ceil_fl
# define MAP_FLR_FL				g_s_mlx.s_map.flr_fl
# define MAP_BLOCK_SIZE			g_s_mlx.s_map.block_size

# define MLX_PTR				g_s_mlx.mlx_ptr
# define MLX_WIN				g_s_mlx.win_ptr
# define IMG_PTR				g_s_mlx.s_img.img_ptr
# define IMG_ADDR				g_s_mlx.s_img.addr
# define IMG_BPP				g_s_mlx.s_img.bits_per_pixel
# define IMG_LEN				g_s_mlx.s_img.line_length
# define IMG_END				g_s_mlx.s_img.endian

# define PLR_POS_X				g_s_mlx.s_game.pl_x
# define PLR_POS_Y				g_s_mlx.s_game.pl_y
# define PLR_DIR_X				g_s_mlx.s_game.dir_x
# define PLR_OLD_DIR_X  		g_s_mlx.s_game.old_dir_x
# define PLR_DIR_Y				g_s_mlx.s_game.dir_y
# define PLR_OLD_DIR_Y  		g_s_mlx.s_game.old_dir_y
# define PLR_PLANE_X			g_s_mlx.s_game.plane_x
# define PLR_OLD_PLANE_X 		g_s_mlx.s_game.old_plane_x
# define PLR_PLANE_Y			g_s_mlx.s_game.plane_y
# define PLR_OLD_PLANE_Y  		g_s_mlx.s_game.old_plane_y
# define PLR_SPEED				g_s_mlx.s_game.move_speed
# define PLR_ROT_SPEED  		g_s_mlx.s_game.rot_speed
# define WALL_DIST_ARR  		g_s_mlx.s_game.wall_dist_arr

# define WALL_S					g_s_mlx.s_w_vars
# define WALL_CAM_X				g_s_mlx.s_w_vars.camera_x
# define WALL_RAY_DIR_X  		g_s_mlx.s_w_vars.ray_dir_x
# define WALL_RAY_DIR_Y  		g_s_mlx.s_w_vars.ray_dir_y
# define WALL_MAP_X				g_s_mlx.s_w_vars.map_x
# define WALL_MAP_Y				g_s_mlx.s_w_vars.map_y
# define WALL_DLT_DIST_X 		g_s_mlx.s_w_vars.delta_dist_x
# define WALL_DLT_DIST_Y 		g_s_mlx.s_w_vars.delta_dist_y
# define WALL_STEP_X			g_s_mlx.s_w_vars.step_x
# define WALL_STEP_Y			g_s_mlx.s_w_vars.step_y
# define WALL_SIDE_DIST_X 		g_s_mlx.s_w_vars.side_dist_x
# define WALL_SIDE_DIST_Y 		g_s_mlx.s_w_vars.side_dist_y
# define WALL_SIDE				g_s_mlx.s_w_vars.wall_side
# define WALL_DIST				g_s_mlx.s_w_vars.wall_dist
# define WALL_HIT				g_s_mlx.s_w_vars.hit
# define WALL_X					g_s_mlx.s_w_vars.wall_x
# define WALL_TEX_X				g_s_mlx.s_w_vars.tex_x
# define WALL_TEX_Y				g_s_mlx.s_w_vars.tex_y
# define WALL_TEX_STEP  		g_s_mlx.s_w_vars.tex_step
# define WALL_TEX_POS  			g_s_mlx.s_w_vars.tex_pos

# define WALL_TEX_MIR  			g_s_mlx.s_w_vars.tex_mirror
# define WALL_LINE_HIGHT  		g_s_mlx.s_w_vars.line_height
# define WALL_LINE_START  		g_s_mlx.s_w_vars.line_start
# define WALL_LINE_END  		g_s_mlx.s_w_vars.line_end

# define S_KEY_W				g_s_mlx.s_keys.w
# define S_KEY_A				g_s_mlx.s_keys.a
# define S_KEY_S				g_s_mlx.s_keys.s
# define S_KEY_D				g_s_mlx.s_keys.d
# define S_KEY_LEFT				g_s_mlx.s_keys.left
# define S_KEY_RIGHT			g_s_mlx.s_keys.right

# define S_NO_TEX_IMG_PTR 		g_s_mlx.s_no_tex.img_ptr
# define S_EA_TEX_IMG_PTR 		g_s_mlx.s_ea_tex.img_ptr
# define S_SO_TEX_IMG_PTR 		g_s_mlx.s_so_tex.img_ptr
# define S_WE_TEX_IMG_PTR 		g_s_mlx.s_we_tex.img_ptr
# define S_SP_TEX_IMG_PTR 		g_s_mlx.s_sp_tex.img_ptr

# define S_NO_TEX_BPP  			g_s_mlx.s_no_tex.bits_per_pixel
# define S_EA_TEX_BPP  			g_s_mlx.s_ea_tex.bits_per_pixel
# define S_SO_TEX_BPP  			g_s_mlx.s_so_tex.bits_per_pixel
# define S_WE_TEX_BPP  			g_s_mlx.s_we_tex.bits_per_pixel
# define S_SP_TEX_BPP  			g_s_mlx.s_sp_tex.bits_per_pixel

# define S_NO_TEX				g_s_mlx.s_no_tex
# define S_EA_TEX				g_s_mlx.s_ea_tex
# define S_SO_TEX				g_s_mlx.s_so_tex
# define S_WE_TEX				g_s_mlx.s_we_tex
# define S_SP_TEX				g_s_mlx.s_sp_tex

# define S_NO_TEX_ADDR  		g_s_mlx.s_no_tex.addr
# define S_EA_TEX_ADDR  		g_s_mlx.s_ea_tex.addr
# define S_SO_TEX_ADDR  		g_s_mlx.s_so_tex.addr
# define S_WE_TEX_ADDR  		g_s_mlx.s_we_tex.addr
# define S_SP_TEX_ADDR  		g_s_mlx.s_sp_tex.addr

# define S_NO_TEX_ENDIAN  		g_s_mlx.s_no_tex.endian
# define S_EA_TEX_ENDIAN  		g_s_mlx.s_ea_tex.endian
# define S_SO_TEX_ENDIAN  		g_s_mlx.s_so_tex.endian
# define S_WE_TEX_ENDIAN  		g_s_mlx.s_we_tex.endian
# define S_SP_TEX_ENDIAN  		g_s_mlx.s_sp_tex.endian

# define S_NO_TEX_LINE_LEN 		g_s_mlx.s_no_tex.line_length
# define S_EA_TEX_LINE_LEN 		g_s_mlx.s_ea_tex.line_length
# define S_SO_TEX_LINE_LEN 		g_s_mlx.s_so_tex.line_length
# define S_WE_TEX_LINE_LEN 		g_s_mlx.s_we_tex.line_length
# define S_SP_TEX_LINE_LEN 		g_s_mlx.s_sp_tex.line_length

# define S_NO_TEX_WIDTH  		g_s_mlx.s_no_tex.width
# define S_EA_TEX_WIDTH  		g_s_mlx.s_ea_tex.width
# define S_SO_TEX_WIDTH  		g_s_mlx.s_so_tex.width
# define S_WE_TEX_WIDTH  		g_s_mlx.s_we_tex.width
# define S_SP_TEX_WIDTH  		g_s_mlx.s_sp_tex.width

# define S_NO_TEX_HEIGHT  		g_s_mlx.s_no_tex.height
# define S_EA_TEX_HEIGHT  		g_s_mlx.s_ea_tex.height
# define S_SO_TEX_HEIGHT  		g_s_mlx.s_so_tex.height
# define S_WE_TEX_HEIGHT  		g_s_mlx.s_we_tex.height
# define S_SP_TEX_HEIGHT  		g_s_mlx.s_sp_tex.height

# define S_SP_LIST				g_s_mlx.s_p_sp_list

typedef	struct	s_sp_vars
{
	float		dist_x;
	float		dist_y;
	float		inv_factor;
	float		transform_x;
	float		transform_y;
	int			scr_x;
	int			vert_offset;
	int			width;
	int			height;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			tex_x;
	int			tex_y;
}				t_sp_vars;

typedef	struct	s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef	struct	s_wall
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			line_height;
	int			line_start;
	int			line_end;
	int			hit;
	int			tex_x;
	int			tex_y;
	int			wall_side;
	int			tex_mirror;
	float		camera_x;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		ray_dir_x;
	float		ray_dir_y;
	float		wall_dist;
	float		wall_x;
	float		tex_pos;
	float		tex_step;

}				t_wall;

typedef	struct	s_game
{
	float		pl_x;
	float		pl_y;
	float		plane_x;
	float		plane_y;
	float		dir_x;
	float		dir_y;
	float		move_speed;
	float		rot_speed;
	float		*wall_dist_arr;
	float		old_dir_x;
	float		old_dir_y;
	float		old_plane_x;
	float		old_plane_y;
}				t_game;

typedef	struct	s_win
{
	int			width;
	int			width_map;
	int			higth;
	int			higth_map;
}				t_win;

typedef	struct	s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

/*
**	Need	to	free	all	allocated	memory	of	pointers
**				↓
*/

typedef	struct	s_map
{
	char		*map_name;
	char		flr_fl;
	int			flr;
	char		ceil_fl;
	int			ceil;
	int			block_size;
	int			map_visible;
	int			pl_start_view;
	int			pl_start_x;
	int			pl_start_y;
	int			map_size;
	int			width;
	int			height;
	char		*line_cpy;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	char		*sp_tex;
	char		**map;
}				t_map;

typedef	struct	s_sp
{
	int			id;
	float		x;
	float		y;
	float		dist;
	struct s_sp	*prev;
	struct s_sp	*next;
}				t_sp;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		save;
	t_map		s_map;
	t_img		s_img;
	t_win		s_win;
	t_game		s_game;
	t_keys		s_keys;
	t_wall		s_w_vars;
	t_sp		*s_p_sp_list;
	t_img		s_no_tex;
	t_img		s_ea_tex;
	t_img		s_so_tex;
	t_img		s_we_tex;
	t_img		s_sp_tex;
}				t_mlx;

extern	t_mlx	g_s_mlx;

void			ft_open_map(int argc, char **argv);
void			ft_error(int err_code);
void			ft_init_tex(void);
char			*ft_miss_sp(char *line);
int				ft_isspace_sp_t_vt(char c);
void			my_mlx_pixel_put(int x, int y, int color);
void			ft_error(int err_code);
int				ft_exit(int exit_code);
void			ft_gnl_sup(int exit, char **line);
void			ft_check_all_atribute(void);
void			ft_check_map_valid(void);
void			ft_check_fl_cl(char *line, int color, char type);
void			ft_check_atrib(char *line);
void			ft_check_tex(char *line);
void			ft_check_map(int len);
void			ft_alloc_map(void);
void			ft_define_tex(char **tex, char *line, int num);
void			ft_parse_rsltn(char *line);
int				ft_get_byte_clr(char **line);
void			ft_plr_view(char view, int y, int x);
void			ft_alloc_map(void);
void			ft_define_tex(char **tex, char *line, int num);
void			ft_plr_view(char view, int y, int x);
void			ft_putendl_fd_err(char *line);
void			ft_save_screen(void);
int				ft_buttons(void);
int				ft_release_key(int key);
int				ft_press_key(int key);
void			ft_move(int dir);
void			ft_strafe(int dir);
void			ft_rotate(int dir);
void			ft_init_dir_n_plane(float dir, float plane, char side);
void			ft_draw_background(void);
void			ft_draw_frame(void);
void			ft_calc_tex(void);
int				ft_calc_pix_clr_n_tex(void);
void			ft_init_tex_addr(void);
void			ft_init_sprites(void);
void			ft_sp_assembly(void);
void			ft_draw_minimap(void);
void			ft_draw_walls(void);
void			ft_calc_step_n_side(void);
void			ft_calc_dlt_dist(void);
void			ft_help(void);
void			ft_init_sprites(void);
void			ft_free_sprite_list(void);
void			ft_check_textures(void);

#endif
