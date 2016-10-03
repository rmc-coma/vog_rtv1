/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_expose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 06:48:23 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 03:38:15 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	rt_expose(t_env **env)
{
	rt_render((*env)->main->camera, (*env)->context, (*env)->main);
	mlx_put_image_to_window((*env)->mlx_ptr, (*env)->win->mlx_ptr,
							(*env)->context->mlx_ptr, 0, 0);
	return (0);
}
