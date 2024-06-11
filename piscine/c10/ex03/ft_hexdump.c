/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:58:17 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:18 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hex.h"

int	print_error(char *name, char *f_name)
{
	write(2, basename(name), ft_strlen(basename(name)));
	write(2, ": ", 2);
	write(2, f_name, ft_strlen(f_name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (-1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		noc_stdin(av);
	else if (ft_strcmp(av[1], "-C") != 0)
		noc_files(ac, av);
	else if (ac == 2 && ft_strcmp(av[1], "-C") == 0)
		c_stdin(av);
	else
	{
		c_files(ac, av);
	}
}
