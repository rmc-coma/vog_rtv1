#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 13:18:15 by rmc-coma          #+#    #+#              #
#    Updated: 2016/09/09 09:24:38 by rmc-coma         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rtv1

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Ofast
LFLAGS = -lm -lc -framework OpenGL -framework AppKit

HDR = 	-I ./libft/include/ \
		-I ./minilibx/		\
		-I ./

LIB =	./libft/libft.a \
		./libmatrices/libmatrices.a \
		./minilibx/libmlx.a

SRC =	main.c \
		rt_polardir.c rt_polardir_to_vec3dir.c rt_ray.c rt_dcos.c rt_dsin.c		\
		rt_dtan.c rt_rad_to_deg.c rt_deg_to_rad.c rt_sq.c rt_abs.c rt_expose.c	\
		rt_add_light_to_scene.c rt_add_object_to_scene.c rt_delete_arrayarray.c	\
		rt_input_key.c rt_loop.c rt_new_light.c rt_new_object.c rt_new_camera.c	\
		rt_new_scene.c rt_render.c rt_raytracing.c rt_objectdata.c rt_fragment.c\
		rt_process_intersection_sphere.c rt_process_intersection_plan.c			\
		rt_set_camera.c rt_process_intersection_cylinder.c rt_lookat.c			\
		rt_process_intersection_cone.c rt_ray_to_pos.c rt_coloradd.c 			\
		rt_colorfade.c rt_vec3dist.c rt_parse_scene.c rt_atof.c	rt_arrlen.c		\
		rt_process_sphere_normal.c rt_process_plan_normal.c rt_exit.c			\
		rt_process_cone_normal.c rt_process_cylinder_normal.c rt_colorshade.c	\
		rt_parse_camera.c rt_parse_light.c rt_parse_object.c rt_isobject.c		\
		rt_process_dist.c rt_argssplit.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./libmatrices
	$(CC) $(CFLAGS) $(HDR) -c $(SRC)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ./libft clean
	make -C ./libmatrices clean
	rm -f $(OBJ)


fclean: clean
	make -C ./libft fclean
	make -C ./libmatrices fclean
	rm -f $(NAME)

re: fclean all