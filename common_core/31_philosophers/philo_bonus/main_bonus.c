/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:08:53 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/06 20:13:52 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6 || is_valid_arg(ac, av) != 1)
		return (write(1, "Error\n", 6), 1);
	init_all()
}