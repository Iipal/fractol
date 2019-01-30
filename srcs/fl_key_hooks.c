/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:40:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/30 17:42:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			fl_khook_killwindow(t_fl *fl)
{
	fl_free(fl);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	add_change_color(int *color)
{
	if (*color == IRGB_WHITE)
		*color = IRGB_LIME;
	else if (*color == IRGB_LIME)
		*color = IRGB_CHERRY;
	else if (*color == IRGB_CHERRY)
		*color = IRGB_AQUA;
	else if (*color == IRGB_AQUA)
		*color = IRGB_PINK;
	else if (*color == IRGB_PINK)
		*color = IRGB_ORANGE;
	else if (*color == IRGB_ORANGE)
		*color = IRGB_PURPLE;
	else if (*color == IRGB_PURPLE)
		*color = IRGB_GRAY;
	else
		*color = IRGB_WHITE;
}

int			fl_key_hooks(int key, t_fl *fl)
{
	if (key == ESC)
	{
		fl_free(fl);
		exit(EXIT_SUCCESS);
	}
	if (key == MINUS_KEYBOARD || key == MINUS_NUMPAD)
		if ((fl->depth -= DEPTH_INC) < DEPTH_MIN)
			fl->depth = DEPTH_MIN;
	if (key == PLUS_NUMPAD || key == PLUS_KEYBOARD)
		if ((fl->depth += DEPTH_INC) > DEPTH_MAX)
			fl->depth = DEPTH_MAX;
	if (key == KEY_C)
		add_change_color(&(fl->color));
	fl_refresh_screen(fl);
	return (0);
}
