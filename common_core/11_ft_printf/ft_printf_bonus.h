/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:06:25 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/18 13:12:48 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	int				width;
	unsigned char	five_flags[5];
	int				precision;
	int				type;
	unsigned char	is_valid;
	int				width_location;
	int				count;
}	t_flags;

int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		count_digits_u(unsigned long long n, unsigned int base);
int		count_digits(long long n, int base);
int		get_width(int widthloc, va_list arg);

void	putnbr_hexd(unsigned long long n,
			char large_first, char plmi, int suf_zero);
void	ft_putllunbr(unsigned long long n, char first, char plmi, int suf_zero);
void	ft_putllnbr(long long n, char first, char plmi, int suf_zero);

int		case_char(t_flags flag, va_list *args);
int		case_string(t_flags flag, va_list *args, char *other_s);
int		case_pointer(t_flags flag, va_list *args);
int		case_unsigned(t_flags flag, va_list *args);
int		case_signed(t_flags flag, va_list *args);

t_flags	get_format(const char *s);
int		ft_printf(const char *s, ...);
int		vft_printf(const char *s, va_list *args);

#endif