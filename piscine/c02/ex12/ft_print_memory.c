/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:49:20 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/12 14:04:47 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr_16(uintptr_t num)
{
	char	s[17];
	int		index;

	s[16] = '\0';
	index = 15;
	while (num > 0 && index >= 0)
	{
		s[index] = "0123456789abcdef"[(num) & 0xf];
		num = num >> 4;
		index--;
	}
	while (index >= 0)
	{
		s[index] = '0';
		index--;
	}
	write(1, s, 16);
	write(1, ": ", 2);
}

int	print_15(char *c, unsigned int remain)
{
	int		index;
	char	s[3];
	int		printnum;

	index = 0;
	if (remain >= 16)
		printnum = 16;
	else
		printnum = remain;
	while (index < printnum)
	{
		s[0] = "0123456789abcdef"[(c[index] >> 4) & 0xf];
		s[1] = "0123456789abcdef"[c[index] & 0xf];
		s[2] = '\0';
		write (1, s, 2);
		if (index % 2 == 1)
			write (1, " ", 1);
		index++;
	}
	return (index - 1);
}

void	print_16_str(char *p, int str_num)
{
	int	index;

	index = 0;
	while (index < str_num + 1)
	{
		if (p[index] < 32 || 126 < p[index])
			write (1, ".", 1);
		else
			write (1, &p[index], 1);
		index++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*p;
	unsigned int	index;
	int				returned_value;
	int				space_index;

	index = 0;
	while (index < size)
	{
		p = addr;
		print_addr_16((uintptr_t)addr);
		returned_value = print_15(p, size - index);
		space_index = (returned_value + 1) / 2 + (returned_value + 1) * 2;
		while (space_index++ < 40)
			write(1, " ", 1);
		print_16_str(p, returned_value);
		write(1, "\n", 1);
		addr += returned_value + 1;
		if (returned_value != 15)
			break ;
		index += returned_value + 1;
	}
	addr -= (size);
	return (addr);
}
