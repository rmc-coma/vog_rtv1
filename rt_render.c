/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 07:40:38 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/07 02:43:50 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_render(t_camera *cam, t_mlxcontext *context, t_scene *scene)
{
	t_uint		i;
	t_uint		j;
	t_vec2		p;
	t_ray		ray;
	float		ratio;

	ratio = (float)(context->width) / (float)(context->height);
	ray.pos = cam->pos;
	i = 0;
	while (i < context->height)
	{
		p.x = -((float)(i + 1) / (float)(context->height) - 0.5f);
		j = 0;
		while (j < context->width)
		{
			p.y = ((float)(j + 1) / (float)(context->width) - 0.5f) * ratio;
			ray.dir = m_vec3nrm(m_vec3val((p.y * cam->right.x + p.x * cam->up.x
	+ cam->dir.x), (p.y * cam->right.y + p.x * cam->up.y + cam->dir.y),
	(p.y * cam->right.z + p.x * cam->up.z + cam->dir.z)));
			context->pixels[j + i * context->width] =
				rt_raytracing(&ray, scene);
			++j;
		}
		++i;
	}
}
