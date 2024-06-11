/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:30:35 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/15 18:31:55 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_error(char *base);
int		char2int_base(char c, char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_putnbr_vardig(long int nbr, long int digit, char *base, int depth);
char	*ft_putnbr_vardig_minus(long nbr, long digit, char *base, int depth);

char	*ft_convert_base(char *nbr, char *base_from, char*base_to)
{
	int			num;
	long int	len;
	long int	ex_nbr;

	num = ft_atoi_base(nbr, base_from);
	if (is_error(base_to) || is_error(base_from))
		return (NULL);
	len = 0;
	while (base_to[len] != '\0')
		len++;
	ex_nbr = (long int)num;
	if (ex_nbr < 0)
	{
		ex_nbr *= -1;
		return (ft_putnbr_vardig_minus(ex_nbr, len, base_to, 1));
	}
	else
	{
		return (ft_putnbr_vardig(ex_nbr, len, base_to, 1));
	}
}
