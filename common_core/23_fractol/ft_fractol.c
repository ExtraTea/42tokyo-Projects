/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:37:07 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/28 19:13:23 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	*ft_mlx_struct_init(void **mlx, t_data_img *img)
{
	void	*mlx_win;

	*mlx = mlx_init();
	if (*mlx == NULL)
		return (NULL);
	mlx_win = mlx_new_window(*mlx, (int)WIDTH, (int)HEIGHT, "frac-tol");
	if (mlx_win == NULL)
		return (NULL);
	img->img = mlx_new_image(mlx, (int)WIDTH, (int)HEIGHT);
	if (img->img == NULL)
		return (NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
		return (NULL);
	return (mlx_win);
}

t_data_img	ft_calculate_image(double center[2], double magni,
		int (*f)(double, double), t_data_img img)
{
	int			i;
	int			j;
	int			color;
	static int	num;

	num = (num + 10) % 360;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			color = ft_get_color(f((((double)j - WIDTH / 2.0)
							* ((COODINATE_LIMIT / magni) / (WIDTH * 0.5)))
						- center[0], (((double)i - HEIGHT / 2.0)
							* ((COODINATE_LIMIT / magni) / (HEIGHT * 0.5)))
						- center[1]), num);
			my_mlx_pixel_put(&img, j, i, color);
			j++;
		}
		i++;
	}
	return (img);
}

void	ft_show_window(int (*f)(double, double))
{
	t_mlx_data	mlx_data;

	mlx_data.magni = 1;
	mlx_data.f = f;
	mlx_data.coordinate_center[0] = 0;
	mlx_data.coordinate_center[1] = 0;
	mlx_data.mlx_win = ft_mlx_struct_init(&(mlx_data.mlx), &(mlx_data.img));
	if (mlx_data.mlx_win == NULL)
		exit(1);
	mlx_data.img = ft_calculate_image(mlx_data.coordinate_center,
			1, f, mlx_data.img);
	mlx_put_image_to_window(mlx_data.mlx,
		mlx_data.mlx_win, mlx_data.img.img, 0, 0);
	mlx_hook(mlx_data.mlx_win, 2, 1L << 0, key_press, &mlx_data);
	mlx_hook(mlx_data.mlx_win, 4, 0, mouse_scroll, &mlx_data);
	mlx_hook(mlx_data.mlx_win, 17, 0, close_window, &mlx_data);
	mlx_loop(mlx_data.mlx);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (write(1, "Julia, Mandelbrot, Burning_Ship", 31));
	if (ft_strncmp(av[1], "Julia", 6) == 0)
	{
		if (ac == 2)
			return (write(1, "1, 2", 4));
		if (ft_strncmp(av[2], "1", 1) == 0)
			ft_show_window(ft_julia_calculate_divergence);
		else if (ft_strncmp(av[2], "2", 2) == 0)
			ft_show_window(ft_julia_calculate_divergence2);
		else
			return (write(1, "1, 2", 3));
	}
	else if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
		ft_show_window(ft_mandelbrot_calculate_divergence);
	else if (ft_strncmp(av[1], "Burning_Ship", 13) == 0)
		ft_show_window(ft_burning_calculate_divergence);
	else
		write(1, "Julia, Mandelbrot, Burning_Ship", 31);
}
