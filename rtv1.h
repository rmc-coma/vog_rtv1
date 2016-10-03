/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 04:37:01 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 11:08:52 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# include "libft/include/libft.h"
# include "libft/include/get_next_line.h"
# include "minilibx/mlx.h"
# include "libmatrices/libmatrices.h"

# define FALSE			0
# define TRUE			!FALSE

# define WIN_WIDTH		800
# define WIN_HEIGHT		600
# define WIN_TITLE		"RTv1"
# define WIN_FOV		90

# define KC_ESCAPE		53
# define KC_W			13
# define KC_A			0
# define KC_S			1
# define KC_D			2
# define KC_ARR_UP		126
# define KC_ARR_LEFT	123
# define KC_ARR_DOWN	124
# define KC_ARR_RIGHT	125
# define KC_SPACE		49
# define KC_LCTRL		256

# define OT_SPHERE		0x0000BA11
# define OT_PLAN		0x0000FACE
# define OT_CYLINDER	0x0000BABE
# define OT_CONE		0x0000C0EF

# define COL_ALPHA		0xFF000000
# define COL_RED		0x00FF0000
# define COL_GREEN		0x0000FF00
# define COL_BLUE		0x000000FF

# define OBJ_N_ARGS		13
# define CAM_N_ARGS		7
# define LIGHT_N_ARGS	8

# define DBL_MAX		1.79769e+308

typedef unsigned int	t_uint;
typedef unsigned char	t_bool;
typedef unsigned char	t_byte;

typedef struct			s_polardir
{
	float			phi;
	float			theta;
}						t_polardir;

typedef struct			s_ray
{
	t_vec3			pos;
	t_vec3			dir;
}						t_ray;

typedef struct			s_cart
{
	double			a;
	double			b;
	double			c;
}						t_cart;

typedef struct			s_camera
{
	t_vec3			pos;
	t_polardir		pdir;
	t_vec3			dir;
	t_vec3			up;
	t_vec3			right;
	float			ambient;
}						t_camera;

typedef struct			s_objectdata
{
	t_vec3			normal;
	float			size;
	float			angle;
	t_uint			color;
}						t_objectdata;

typedef struct			s_object
{
	int				type;
	t_vec3			pos;
	t_vec3			normal;
	float			size;
	float			angle;
	float			spec;
	t_uint			color;
	t_bool			(*inter_func)(t_ray *, struct s_object *, double *);
	t_vec3			(*normal_func)(t_ray *, t_vec3, double,
		struct s_object *);
}						t_object;

typedef struct			s_ilist
{
	t_list			*lst;
	t_uint			n;
}						t_ilist;

typedef struct			s_light
{
	t_vec3			pos;
	t_uint			color;
	float			intensity;
}						t_light;

typedef struct			s_lightdata
{
	t_light			*light;
	t_ray			obj_to_light;
	t_vec3			obj_nrm;
	double			obj_to_light_dist;
	double			diffuse;
	t_uint			pixel_color;
}						t_lightdata;

typedef struct			s_mlxcontext
{
	void			*mlx_ptr;
	t_uint			*pixels;
	float			ratio;
	t_uint			vfov;
	t_uint			hfov;
	t_uint			width;
	t_uint			height;
	int				bpp;
	int				size_line;
	int				endian;
}						t_mlxcontext;

typedef struct			s_mlxwindow
{
	void			*mlx_ptr;
	char			*title;
	t_uint			width;
	t_uint			height;
}						t_mlxwindow;

typedef struct			s_scene
{
	t_camera		*camera;
	t_uint			n_objects;
	t_object		**objects;
	t_uint			n_lights;
	t_light			**lights;
}						t_scene;

typedef	struct			s_env
{
	void			*mlx_ptr;
	t_mlxwindow		*win;
	t_mlxcontext	*context;
	t_scene			*main;
}						t_env;

float					rt_dcos(float var);
float					rt_dsin(float var);
float					rt_dtan(float var);
float					rt_rad_to_deg(float var);
float					rt_deg_to_rad(float var);
double					rt_sq(double var);
double					rt_abs(double var);
float					rt_atof(char *str);

void					rt_delete_arrayarray(void **a);
t_bool					rt_isobject(char *str);
t_uint					rt_arrlen(char **arr);
char					**rt_argssplit(char *line);

t_polardir				rt_polardir(float phi, float theta);
t_ray					rt_ray(t_vec3 pos, t_vec3 dir);
t_objectdata			rt_objectdata(float size, t_uint color, t_vec3 normal,
	float angle);
t_vec3					rt_polardir_to_vec3dir(t_polardir polardir);

t_scene					*rt_new_scene(t_camera *camera, t_uint n_lights,
	t_uint n_objects);
t_camera				*rt_new_camera(t_vec3 pos, t_polardir dir,
	float ambient);
t_light					*rt_new_light(t_vec3 pos, t_uint color,
	float intensity);
t_object				*rt_new_object(int type, t_vec3 pos, float spec,
	t_objectdata objdat);

t_camera				*rt_parse_camera(char **args);
void					*rt_parse_light(char **args);
void					*rt_parse_object(char **args);

t_bool					rt_set_camera(t_vec3 pos, t_polardir dir,
	t_camera *camera);
t_bool					rt_add_light_to_scene(t_scene *scene, t_light *light);
t_bool					rt_add_object_to_scene(t_scene *scene,
	t_object *object);

t_vec3					rt_ray_to_pos(t_ray *ray, double dist);
t_vec3					rt_lookat(t_vec3 *eye, t_vec3 *center);
double					rt_vec3dist(t_vec3 *src, t_vec3 *dest);

t_bool					rt_process_intersection_sphere(t_ray *ray,
	t_object *sphere, double *dist);
t_bool					rt_process_intersection_plan(t_ray *ray, t_object *plan,
	double *dist);
t_bool					rt_process_intersection_cylinder(t_ray *ray,
	t_object *cylinder, double *dist);
t_bool					rt_process_intersection_cone(t_ray *ray, t_object *cone,
	double *dist);

t_vec3					rt_process_sphere_normal(t_ray *ray, t_vec3 hit,
	double dist, t_object *sphere);
t_vec3					rt_process_plan_normal(t_ray *ray, t_vec3 hit,
	double dist, t_object *plan);
t_vec3					rt_process_cylinder_normal(t_ray *ray, t_vec3 hit,
	double dist, t_object *cylinder);
t_vec3					rt_process_cone_normal(t_ray *ray, t_vec3 hit,
	double dist, t_object *cone);

double					rt_process_dist(double delta, t_cart *n);

t_uint					rt_colorfade(t_uint color, float fadefactor);
t_uint					rt_colorshade(t_uint color, float factor);
t_uint					rt_coloradd(t_uint color1, t_uint color2);

int						rt_expose(t_env **env);
int						rt_input_key(int keycode, t_env **env_ptr);
void					rt_loop(t_env **env);
void					rt_render(t_camera *cam, t_mlxcontext *context,
	t_scene *scene);
t_uint					rt_raytracing(t_ray *ray, t_scene *scene);
t_uint					rt_fragment(t_ray *ray, t_scene *scene,
	t_object *object, double hit_dist);
t_scene					*rt_parse_scene(const int fd);
void					rt_exit(char *error, t_env **env);

#endif
