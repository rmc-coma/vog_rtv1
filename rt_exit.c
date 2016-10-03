/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 07:41:28 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 03:40:55 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	rt_kill_scene(t_scene **main)
{
	t_uint	i;

	if ((*main)->camera)
		free((*main)->camera);
	if ((*main)->objects)
	{
		i = 0;
		while (i < (*main)->n_objects)
			free((*main)->objects[i++]);
		free((*main)->objects);
	}
	if ((*main)->lights)
	{
		i = 0;
		while (i < (*main)->n_lights)
			free((*main)->lights[i++]);
		free((*main)->lights);
	}
	free(*main);
}

static void	rt_kill_mlx_window(t_mlxwindow **win, void *mlx_ptr)
{
	if ((*win)->mlx_ptr)
		mlx_destroy_window(mlx_ptr, (*win)->mlx_ptr);
	if ((*win)->title)
		free((*win)->title);
	free(*win);
}

static void	rt_kill_mlx_context(t_mlxcontext **context, void *mlx_ptr)
{
	if ((*context)->mlx_ptr)
		mlx_destroy_image(mlx_ptr, (*context)->mlx_ptr);
	free(*context);
}

void		rt_exit(char *error, t_env **env)
{
	if (env && *env)
	{
		if ((*env)->main)
			rt_kill_scene(&((*env)->main));
		if ((*env)->mlx_ptr)
		{
			if ((*env)->win)
			{
				if ((*env)->context)
					rt_kill_mlx_context(&((*env)->context), (*env)->mlx_ptr);
				rt_kill_mlx_window(&((*env)->win), (*env)->mlx_ptr);
			}
			free((*env)->mlx_ptr);
		}
		free(*env);
	}
	if (error != NULL)
	{
		ft_putendl(error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
