/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicterror1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:47:11 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 16:47:12 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	write_val_rec(char *num, int len, t_node *head);
int	write_val_3digits(int num, t_node *head);
int	write_val_digit(char *digit, t_node *head, int num);
int	write_val_100s(int num, t_node *head);

int	write_pre_val(char *num, t_node *head)
{
	int	len;

	len = ft_strlen(num);
	if (write_val_rec(num, len, head) == 1)
		return (1);
	else
		return (0);
}

int	write_val_rec(char *num, int len, t_node *head)
{
	char	dest[4];
	char	powers[300];
	int		part_len;

	if (len % 3 == 0)
		part_len = 3;
	else
		part_len = len % 3;
	ft_strlcpy(dest, num, part_len + 1);
	if (write_val_3digits(ft_atoi(dest), head) == 1)
		return (1);
	len -= part_len;
	if (len > 0)
	{
		if (strncmp(num, "000", 3) != 0)
		{
			if (search(head, make_10_power(len, powers)) == NULL)
				return (1);
		}
		if (write_val_rec(num + part_len, len, head) == 1)
			return (1);
	}
	return (0);
}

int	write_val_3digits(int num, t_node *head)
{
	char	*digit;
	int		result;

	result = 0;
	digit = NULL;
	if (num == 0)
		return (0);
	if (num / 100 > 0)
		result += write_val_100s(num, head);
	num %= 100;
	if (num == 0)
		return (0);
	if (num > 20)
	{
		result += write_val_digit(digit, head, num - num % 10);
		if (num % 10 == 0)
			return (0);
		result += write_val_digit(digit, head, num % 10);
	}
	else
		result += write_val_digit(digit, head, num);
	if (result > 0)
		return (1);
	else
		return (0);
}

int	write_val_digit(char *digit, t_node *head, int num)
{
	char	*numtemp;

	numtemp = ft_itoa(num);
	digit = search(head, numtemp);
	free(numtemp);
	if (digit == NULL)
		return (1);
	return (0);
}

int	write_val_100s(int num, t_node *head)
{
	char	*digit;
	char	*numtemp;

	numtemp = ft_itoa(num / 100);
	digit = search(head, numtemp);
	free(numtemp);
	if (digit == NULL)
		return (1);
	digit = search(head, "100");
	if (digit == NULL)
		return (1);
	return (0);
}
