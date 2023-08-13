/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:18:32 by nradal            #+#    #+#             */
/*   Updated: 2023/08/13 17:55:35 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../mlx_linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>

# define M_PI 3.14159265358979323846
# define WIDTH 1920
# define HEIGHT 1080

// map linked list
typedef struct s_map
{
	char			*line;
	struct s_map	*next;
	struct s_map	*first;
}					t_map;

// player movement struct
typedef struct s_move
{
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				rotation_left;
	int				rotation_right;
	double			move_speed;
	double			rotation_speed;
	time_t			last_frame_time;
}					t_move;

// ray_struct
typedef struct s_ray
{
	double			angle;
	double			angle_increment;
	double			delta_x;
	double			delta_y;
	double			ray_x;
	double			ray_y;
	double			sdx;
	double			sdy;
	double			add_x;
	double			add_y;
	double			step_x;
	double			step_y;
	double			wall_size;
	double			hor_x;
	double			hor_y;
	double			hor_dist;
	double			ver_x;
	double			ver_y;
	double			ver_dist;
}					t_ray;

// player struct
typedef struct s_player
{
	double			px;
	double			py;
	double			angle;
	double			fov;
	int				map;
	t_move			move;
}					t_player;

// image struct
typedef struct s_image
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_length;
	int				endian;
	int				padding;
}					t_image;

// draw struct
typedef struct s_draw
{
	int				tex_x;
	int				tex_y;
	int				tex_index;
	int				tex_color;
	double			wall_texture_step;
	double			texture_offset;
	double			wall_height;
}					t_draw;

// sprites struct
typedef struct s_sprites
{
	void			*n_sprite;
	void			*s_sprite;
	void			*w_sprite;
	void			*e_sprite;
	t_image			*n_image;
	t_image			*s_image;
	t_image			*w_image;
	t_image			*e_image;
	char			direction;
}					t_sprites;

// parsing struct
typedef struct s_parsing
{
	char			*n_sprite;
	char			*s_sprite;
	char			*w_sprite;
	char			*e_sprite;
	unsigned char	*f_color;
	unsigned char	*c_color;
	int				floor;
	int				ceiling;
	int				fd;
	int				ps_x;
	int				ps_y;
	int				width;
	int				height;
	t_map			*map;
	char			**c_map;
}					t_parsing;

// minimap_struct
typedef struct s_minimap
{
	int				cube_size;
	int				player_size;
}					t_minimap;

// mlx struct
typedef struct s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	int				x;
	int				y;
}					t_window;

// fps struct
typedef struct s_fps
{
	double			time;
	double			old_time;
	double			fps;
}					t_fps;

// main struct
typedef struct s_data
{
	t_window		window;
	t_parsing		parsing;
	t_player		player;
	t_ray			ray;
	t_sprites		sprites;
	t_fps			fps;
	t_image			*image;
	t_minimap		minimap;
	bool			is_running;
	bool			game_started;
}					t_data;

// cub3d.c
// files_handler.c
int				ft_open_file(const char *file);
bool			ft_extension(const char	*filename, char	*ext);
void			verify_textures(t_data *data);

// parsing.c
void			set_color(t_data *data, char *token,
					unsigned char **color, int index);
unsigned char	*colors_handler(t_data *data, char *line);
void			clean_line(t_data *data, char **line);
void			remove_cub_data_lines(t_data *data);
void			map_parser(t_data *data, const char *map);

// free.c
void			free_maps(t_data *data);
void			free_parsing(t_data *data);
void			free_image(t_data *data, t_image *image);
void			free_images(t_data *data);
void			free_data(t_data *data);
void			error_handler(t_data *data, char *error);
void			safe_free(void *ptr);
void			c_map_free(t_data *data, char **c_map, char *str);
void			free_mlx(t_data *data);

// conditions.c
bool			extract_textures_condition(t_data *data);
bool			is_map(char *line);
bool			is_legal_line(char *line);

// map_data_extractor.c
void			get_cub_data(t_data *data, int fd);
void			map_assignation(t_data *data, t_map **current,
					t_map **new_node);
void			extract_colors(t_data *data, char *line);
void			extract_textures(t_data *data);

// spawn_checker.c
bool			is_player_spawn(char c, int *player_spawn_counter);
void			find_player_spawn(t_data *data, t_map *current, int x, int y);
int				get_map_length(t_data *data, char *line);
int				player_spawn_checker(t_data *data);
void			explore_map_recursive(t_data *data, int x, int y, int *count);

// utils.c
void			ft_access(t_data *data, const char *file);
int				rgb_to_hexa(unsigned char *color);
char			convert_char(char c);
void			convert_line(t_data *data, t_map *current, char **c_map);
void			ll_to_char(t_data *data);

// exec_init.c
void			exec_init(t_data *data);
void			init_sprites(t_data *data);
void			init_image(t_data *data, t_image *image);

// game_loop.c
void			get_fps(t_data *data);
void			loop_movements(t_data *data);
int				game_loop(t_data *data);
void			display_window(t_data *data);

// image.c
t_image			*create_image(void *mlx_ptr, int width, int height);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
t_image			*get_sprites(t_data *data, char *str);

// keys.c
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);

// minimap.c
void			mlx_draw_pixels_cubes(t_data *data, int x, int y, int color);
void			draw_map(t_data *data);
void			draw_player(t_data *data);

// move.c
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

// movements.c
void			move_x(t_data *data, double dx);
void			move_y(t_data *data, double dy);
void			move_player(t_data *data, char direction);

// raycaster_draw.c
t_image			*sprites_selector(t_data *data);
void			draw_loop(t_data *data, t_draw draw, t_image *texture, int x);
void			draw_cf(t_data *data, int column);
void			draw_walls_init(t_data *data, double wall_distance,
					int x, double texture_offset);
void			update_scene(t_data *data, char direction);

// raycaster_values.c
void			horizontal_crossings(t_data *data);
void			vertical_crossing(t_data *data);
void			raycaster_init(t_data *data, int column);

// raycaster.c
bool			raycaster_vertical(t_data *data, int column);
bool			raycater_horizontal(t_data *data, int column);
void			raycaster_loop(t_data *data);
bool			raycaster_ver_or_hor(t_data *data, int column);
void			raycaster_algo(t_data *data);

// rotation.c
void			rotation_left(t_data *data);
void			rotation_right(t_data *data);

// utils.c
void			get_wall_size(t_data *data, double x2, double y2);
int				close_window(t_data *data);

#endif