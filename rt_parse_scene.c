/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 22:41:48 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 08:59:16 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_scene	*rt_parsed_to_scene(t_ilist *objects, t_ilist *lights,
	t_camera *camera)
{
	t_scene		*new;
	t_list		*prev;

	new = NULL;
	if (objects->n > 0 && lights->n > 0)
	{
		new = rt_new_scene(camera, lights->n, objects->n);
		while (lights->n)
		{
			rt_add_light_to_scene(new, (t_light *)(lights->lst->content));
			prev = lights->lst;
			lights->lst = lights->lst->next;
			free(prev);
			--(lights->n);
		}
		while (objects->n)
		{
			rt_add_object_to_scene(new, (t_object *)(objects->lst->content));
			prev = objects->lst;
			objects->lst = objects->lst->next;
			free(prev);
			--(objects->n);
		}
	}
	return (new);
}

static t_bool	rt_fill_ilist(t_ilist *ilist, char **args,
	void *(*parse_func)(char **), int content_size)
{
	void			*tmp;

	if ((tmp = parse_func(args)) != NULL)
	{
		ft_lstapp(&(ilist->lst), ft_lstnew(tmp, content_size));
		free(tmp);
		++(ilist->n);
		return (TRUE);
	}
	else
	{
		ft_putendl("Parse error");
		exit(EXIT_FAILURE);
		return (FALSE);
	}
}

static void		rt_init_ilists(t_ilist *i1, t_ilist *i2)
{
	i1->n = 0;
	i1->lst = NULL;
	i2->n = 0;
	i2->lst = NULL;
}

t_scene			*rt_parse_scene(const int fd)
{
	char		*line;
	char		**el;
	t_camera	*camera;
	t_ilist		objects;
	t_ilist		lights;

	rt_init_ilists(&objects, &lights);
	while (get_next_line(fd, &line) > 0)
	{
		if (line != NULL && line[0] != 0)
		{
			el = rt_argssplit(line);
			if (ft_strequ(el[0], "CAMERA"))
				camera = rt_parse_camera(el);
			else if (ft_strequ(el[0], "LIGHT"))
				rt_fill_ilist(&lights, el, rt_parse_light, sizeof(t_light));
			else if (rt_isobject(el[0]))
				rt_fill_ilist(&objects, el, rt_parse_object, sizeof(t_object));
			rt_delete_arrayarray((void **)el);
		}
		if (line != NULL)
			free(line);
	}
	close(fd);
	return (rt_parsed_to_scene(&objects, &lights, camera));
}
