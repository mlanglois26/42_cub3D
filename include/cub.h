/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:18:44 by malanglo          #+#    #+#             */
/*   Updated: 2024/10/16 17:36:23 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define PI 3.14159265358979323846
# define _POSIX_C_SOURCE 200809L

# define WIDTH 800
# define HEIGHT 800

# define TALE_H 64
# define TALE_W 64

# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_player_vec
{
	double			x;
	double			y;
	char			z;
}					t_player_vec;

typedef struct s_direction_vec
{
	double			angle;
	double			x;
	double			y;
}					t_direction_vec;

typedef struct s_camera_vec
{
	double			x;
	double			y;
}					t_camera_vec;

typedef struct s_ray
{
	t_direction_vec	*dir_vec;
	t_camera_vec	*cam_vec;
	t_player_vec	*player_vec;
	double			dir_x;
	double			dir_y;
	double			camera_pos_x;
	double			delta_x;
	double			delta_y;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	int				map_x;
	int				map_y;
	int				side;
	double			perp_wall_dist;
	double			line_height;
	double			start_draw;
	double			end_draw;
}					t_ray;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_image
{
	void			*img_ptr;
	char			*img_addr;
	int				bpp;
	int				line_len;
	int				endian;
	t_point			dimensions;
}					t_image;

typedef struct s_designs
{
	char			*path_wall_no;
	t_image			t_wall_north;
	char			*path_wall_we;
	t_image			t_wall_west;
	char			*path_wall_ea;
	t_image			t_wall_east;
	char			*path_wall_so;
	t_image			t_wall_south;
	t_rgb			floor;
	t_rgb			ceiling;
}					t_designs;

typedef struct s_mlx
{
	void			*mlx_connection;
	void			*window;
	t_image			image;
}					t_mlx;

typedef struct s_data
{
	char			**map;
	char			***elements;
	int				map_height;
	int				map_width;
	double			move_speed;
	t_mlx			*mlx;
	t_player_vec	*player;
	t_direction_vec	*direction;
	t_camera_vec	*camera;
	t_ray			*ray;
	t_designs		*designs;
	double			ray_dir_x0;
	double			ray_dir_y0;
	double			ray_dir_x1;
	double			ray_dir_y1;
	double			floor_x;
	double			floor_y;
	double			floor_step_x;
	double			floor_step_y;
	int				floor_color;
	int				ceiling_color;
}					t_data;

////////////// MLX STUFF ///////////////////////////////////

/* hooks.c */

void				rotate_right(t_data *data);
void				rotate_left(t_data *data);
int					on_key_press(int key, t_data *data);

/* mlx_init.c */

t_image				new_img(int w, int h, t_mlx *mlx);
t_image				new_file_img(char *path, t_data *data);
t_mlx				*my_mlx_init(void);

/* mlx_moves.c */

void				move_forward(t_data *data);
void				move_backward(t_data *data);
void				move_right(t_data *data);
void				move_left(t_data *data);

////////////// PARSING ///////////////////////////////////

/* Check and stock */

/* args.c */

void				check_args_and_envp(int argc, char **argv, char **envp);

/* env.c */

int					check_if_env_i(char **envp);

/* open_file.c */

int					file_height(char *file);
char				**stock_file_content(char *file);
int					this_line_has_content(char *line);
void				file_worth_analysing(char *file, t_data *data);

/* Clean */

/* exit.c */

void				exit_and_free_double_pointer(char **ptr);
void				exit_and_free_triple_pointer(char ***ptr);
void				free_mlx_ptr_and_exit(t_mlx *mlx);
int					quit(t_data *data);

/* free.c */

void				free_designs(t_data *data);
void				free_double_pointer(char **elems);
void				free_triple_pointer(char ***elems);
void				free_wrapper(char **new_map,
						char **all_lines, t_data *data);

/* Elements */

/* col_and_text.c */

int					rgb_has_three_parts(const char *rgb_str);
int					rgb_nb_is_valid(char *elem_second_part);

/* get_rgb.c */

int					parse_rgb(char *rgb_str, t_rgb *rgb);
int					handle_texture_path(char *line, t_data *data);
int					handle_rgb_value(char *line, t_data *data, char identifier);

/* get_textures.c */

char				*trim_whitespace(char *str);
char				*trim_trailing_whitespace(char *str);
int					extract_texture_path(char *line,
						char **destination, const char *identifier);
void				extract_floor_ceiling_and_textures(char **stocked_line,
						t_data *data);
int					handle_texture_path(char *line, t_data *data);

/* parse_elements.c */

void				clean_map_data_and_elems(char ***splitted_elems,
						t_data *data, char **elems, char **stocked_line);
void				check_elements_validity(char ***splitted_elems,
						t_data *data, char **elems, char **stocked_line);
char				***parse_elements(char *file, t_data *data);

/* verif_elements.c */

int					elems_are_all_splitted_into_two_parts(char ***elem);
int					elems_first_part_content_is_valid(char ***elem);
int					elems_first_part_are_unique(char ***elem);
int					elems_second_part_content_is_valid(char ***elems);
int					elems_second_part_are_unique(char ***elems);

/* verif_elements2.c */

int					color_check(char ***elems, int i);
int					xpm_check(char ***elems, int i);

/* char_verif.c */

int					there_is_unwanted_character_in_array(char **h_line_array);
int					n_s_e_w_are_unique_in_array(char **h_line_array);
int					there_is_empty_line_in_array(char **h_line_array);

/* get_mapc.c */

int					map_height(char **all_lines);
char				**stock_map(char **all_lines);

/* get_new_map.c */

int					get_width_of_longest_h_line(char **map);
char				**fill_map_with_spaces(char **map, char **all_lines);

/* parse_map.c */

char				**parse_map(char *file, t_data *data);
int					get_final_map_height(char **map);

////////////// RAY CASTING ///////////////////////////////////

/* draw.c */

void				draw(t_data *data, int x);

/* floor_ceiling.c */

void				floor_ceiling_casting(t_data *data);

/* init_data.c */

t_data				*init_data(void);
int					get_final_map_height(char **map);
void				parse_file_content(char *file, t_data *data);
void				set_data_for_raycasting(t_data *data);

/* init_vect_utils.c */

int					is_player_char(char c);
double				degrees_to_radians(double degrees);
double				ft_abs(double n);

/* vector_init.c */

t_player_vec		*init_player_vector(char **map);
t_direction_vec		*init_direction_vector(t_player_vec *player);
t_camera_vec		*init_camera_vector(t_direction_vec *dir);

/* rays_calculs.c */

void				calculate_ray_dir(t_data *data, int x);
void				calculate_deltas(t_data *data, int x);
void				get_step_and_initial_side_dist(t_data *data, int x);
void				perform_dda(t_data *data, int x);
void				get_line_height(t_data *data, int x);
void				draw(t_data *data, int x);

/* rays_casting.c */

t_ray				*init_ray(t_data *data);
void				reset_everything(t_data *data, int x);
int					raycasting(t_data *data);

#endif
