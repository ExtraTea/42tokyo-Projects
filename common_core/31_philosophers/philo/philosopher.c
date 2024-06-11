/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:53:12 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/07 21:20:15 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

void	*philosophers(void *phi_info)
{
	int	fork[2];

	fork[0] = ((t_phi *)phi_info)->name;
	fork[1] = ((t_phi *)phi_info)->name + 1;
	if (fork[1] >= (((t_phi *)phi_info)->uni->n_phi))
		fork[1] = 0;
	while (1)
	{
		if (philosophers_rw_end(((t_phi *)phi_info), 'r') == 1)
			break ;
		philosophers_eat(phi_info, fork);
		if (philosophers_rw_end(((t_phi *)phi_info), 'r') == 1)
			break ;
		philosophers_sleep(phi_info);
		if (philosophers_rw_end(((t_phi *)phi_info), 'r') == 1)
			break ;
		philosophers_think(phi_info);
	}
	return (NULL);
}
