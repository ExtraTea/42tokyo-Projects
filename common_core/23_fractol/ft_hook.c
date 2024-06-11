/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:40:11 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/28 19:13:39 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_finish_process(void *mlx_data)
{
	mlx_destroy_image(((t_mlx_data *)mlx_data)->mlx,
		((t_mlx_data *)mlx_data)->img.img);
	mlx_destroy_window(((t_mlx_data *)mlx_data)->mlx,
		((t_mlx_data *)mlx_data)->mlx_win);
	exit(0);
}

int	key_press(int keycode, void *mlx_data)
{
	if (keycode == 53)
		ft_finish_process(mlx_data);
	else if (keycode == 123)
		((t_mlx_data *)mlx_data)->coordinate_center[0]
			+= SCROLL_SPEED / ((t_mlx_data *)mlx_data)->magni;
	else if (keycode == 124)
		((t_mlx_data *)mlx_data)->coordinate_center[0]
			-= SCROLL_SPEED / ((t_mlx_data *)mlx_data)->magni;
	else if (keycode == 125)
		((t_mlx_data *)mlx_data)->coordinate_center[1]
			-= SCROLL_SPEED / ((t_mlx_data *)mlx_data)->magni;
	else if (keycode == 126)
		((t_mlx_data *)mlx_data)->coordinate_center[1]
			+= SCROLL_SPEED / ((t_mlx_data *)mlx_data)->magni;
	((t_mlx_data *)mlx_data)->img = ft_calculate_image(
			((t_mlx_data *)mlx_data)->coordinate_center,
			((t_mlx_data *)mlx_data)->magni, ((t_mlx_data *)mlx_data)->f,
			((t_mlx_data *)mlx_data)->img);
	mlx_put_image_to_window(((t_mlx_data *)mlx_data)->mlx,
		((t_mlx_data *)mlx_data)->mlx_win,
		((t_mlx_data *)mlx_data)->img.img, 0, 0);
	return (0);
}

int	mouse_scroll(int button, int x, int y, void *mlx_data)
{
	(void)x;
	(void)y;
	if (button == 4)
		((t_mlx_data *)mlx_data)->magni *= 0.75;
	else if (button == 5)
		((t_mlx_data *)mlx_data)->magni /= 0.75;
	((t_mlx_data *)mlx_data)->img = ft_calculate_image(
			((t_mlx_data *)mlx_data)->coordinate_center,
			((t_mlx_data *)mlx_data)->magni, ((t_mlx_data *)mlx_data)->f,
			((t_mlx_data *)mlx_data)->img);
	mlx_put_image_to_window(((t_mlx_data *)mlx_data)->mlx,
		((t_mlx_data *)mlx_data)->mlx_win,
		((t_mlx_data *)mlx_data)->img.img, 0, 0);
	return (0);
}

int	close_window(void *mlx_data)
{
	ft_finish_process(mlx_data);
	return (0);
}
