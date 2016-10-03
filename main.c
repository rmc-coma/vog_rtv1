/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 05:39:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 11:08:50 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_mlxwindow	*rt_new_window(void *mlx_ptr)
{
	t_mlxwindow		*win;

	if (!(win = (t_mlxwindow *)malloc(sizeof(t_mlxwindow))))
		return (NULL);
	win->title = ft_strdup(WIN_TITLE);
	win->height = WIN_HEIGHT;
	win->width = WIN_WIDTH;
	if (!(win->mlx_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH,
		WIN_HEIGHT, WIN_TITLE)))
		return (NULL);
	return (win);
}

static t_mlxcontext	*rt_new_context(void *mlx_ptr)
{
	t_mlxcontext	*context;

	if (!(context = (t_mlxcontext *)malloc(sizeof(t_mlxcontext))))
		return (NULL);
	context->width = WIN_WIDTH;
	context->height = WIN_HEIGHT;
	context->hfov = WIN_FOV;
	context->ratio = WIN_WIDTH / (float)WIN_HEIGHT;
	context->vfov = WIN_FOV / context->ratio;
	if (!(context->mlx_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH,
		WIN_HEIGHT)))
		return (NULL);
	if (!(context->pixels = (t_uint *)mlx_get_data_addr(context->mlx_ptr,
		&(context->bpp), &(context->size_line), &(context->endian))))
		return (NULL);
	return (context);
}

int					main(int argc, char **argv)
{
	t_env	*env;

	if (argc > 1)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env))))
			rt_exit("Failed to allocate memory to environment", &env);
		env->mlx_ptr = NULL;
		if (!(env->main = rt_parse_scene(open(argv[1], O_RDONLY))))
			rt_exit("Parse error", &env);
		if (!(env->mlx_ptr = mlx_init()))
			rt_exit("Failed to initialize minilibx", &env);
		if (!(env->win = rt_new_window(env->mlx_ptr)))
			rt_exit("Failed to create window", &env);
		if (!(env->context = rt_new_context(env->mlx_ptr)))
			rt_exit("Failed to create context", &env);
		rt_loop(&env);
	}
	else
		ft_putendl("Usage : rtv1 SCENE_PATH");
	rt_exit(NULL, &env);
	return (0);
}
