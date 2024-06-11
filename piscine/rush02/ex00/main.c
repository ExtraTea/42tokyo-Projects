/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:53:10 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 14:53:11 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include <libc.h>
__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

long	count_file_len(char *name)
{
	int		fd;
	int		result;
	long	len;
	char	buffer[1029];

	fd = open(name, O_RDONLY);
	len = 0;
	while (1)
	{
		result = read(fd, buffer, 1024);
		len += result;
		if (result == 0)
			break ;
	}
	close(fd);
	return (len);
}

int	print_dict_error(t_node *head)
{
	write(1, "Dict Error\n", 11);
	free_list(&head);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*head;
	char	*num;

	head = NULL;
	num = ft_check_arg(argc, argv);
	if (num == NULL)
		return (1);
	if (argc == 2)
	{
		head = read_n_insert("numbers.dict");
		if (write_pre_val(num, head) == 1 || head == NULL)
			return (print_dict_error(head));
		write_all(num, head);
	}
	else if (argc == 3)
	{
		head = read_n_insert(argv[1]);
		if (write_pre_val(num, head) == 1 || head == NULL)
			return (print_dict_error(head));
		write_all(num, head);
	}
	free_list(&head);
}
