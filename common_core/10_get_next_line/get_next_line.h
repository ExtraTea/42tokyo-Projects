/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:05:35 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/18 14:38:00 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	ft_strlcpycat(char *dst, const char *src1,
			const char *src2, size_t dstsize);
void	*ft_mve(void *dest, const void *src, size_t n);

typedef struct s_data
{
	char	*result;
	char	*tmp;
	int		read_bytes;
	int		total_read;
	int		f_l;
	int		br_co;
}	t_data;

#endif