/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:03:07 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/13 20:03:09 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	arg_index;
	int	len;

	arg_index = 1;
	while (arg_index < argc)
	{
		len = 0;
		while (argv[arg_index][len] != 0)
			len++;
		write (1, argv[arg_index], len);
		write (1, "\n", 1);
		arg_index++;
	}
}
