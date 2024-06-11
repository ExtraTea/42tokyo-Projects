/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:44:34 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 20:49:46 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include "./libft/libft.h"

# define HEIGHT 500.0
# define WIDTH 500.0
# define COODINATE_LIMIT 2.0
# ifndef C_REAL
#  define C_REAL -0.7436435
# endif
# ifndef C_IMAGINAL
#  define C_IMAGINAL 0.131825
# endif
# define MAX_CALCULATION 100
# define SCROLL_SPEED 0.1

typedef struct s_data_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data_img;

typedef struct s_mlx_data{
	void		*mlx;
	void		*mlx_win;
	t_data_img	img;
	double		coordinate_center[2];
	double		magni;
	int			(*f)(double, double);
}	t_mlx_data;

int			ft_julia_calculate_divergence(double real, double imaginal);
int			ft_julia_calculate_divergence2(double real, double imaginal);
int			ft_mandelbrot_calculate_divergence(double real, double imaginal);
int			ft_burning_calculate_divergence(double real, double imaginal);

int			ft_get_color(int i, int num);
void		ft_show_window(int (*f)(double, double));

int			key_press(int keycode, void *mlx_data);
int			mouse_scroll(int button, int x, int y, void *mlx_data);
int			close_window(void *param);

t_data_img	ft_calculate_image(double center[2],
				double magni, int (*f)(double, double), t_data_img img);

#endif
