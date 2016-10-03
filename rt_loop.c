/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 06:46:52 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 03:37:17 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_loop(t_env **env)
{
	mlx_expose_hook((*env)->win->mlx_ptr, rt_expose, (void *)env);
	mlx_key_hook((*env)->win->mlx_ptr, rt_input_key, (void *)env);
	mlx_loop((*env)->mlx_ptr);
}
