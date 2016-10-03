/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_argssplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 08:33:50 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/09/09 08:58:55 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	**rt_argssplit(char *line)
{
	char	*tmp;
	char	**args;

	tmp = ft_strtrim(line);
	args = ft_strsplit(tmp, ' ');
	free(tmp);
	return (args);
}
