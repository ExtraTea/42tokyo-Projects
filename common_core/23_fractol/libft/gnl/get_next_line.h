/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:05:32 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/28 17:16:11 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
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