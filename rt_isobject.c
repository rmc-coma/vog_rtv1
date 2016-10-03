/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_isobject.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 05:32:48 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 05:35:24 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	rt_isobject(char *str)
{
	return (ft_strequ(str, "SPHERE") || ft_strequ(str, "PLAN") ||
			ft_strequ(str, "CONE") || ft_strequ(str, "CYLINDER"));
}
