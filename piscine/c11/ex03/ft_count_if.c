/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:46:24 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 17:46:25 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < length)
	{
		if (f(tab[index]) != 0)
			count++;
		index++;
	}
	return (count);
}

/* #include <stdio.h>
#include <string.h>

int is_longer_than_three(char *str) {
    return (strlen(str) > 3);
}

int main() {
    char *words[] = {"hi", "hello", "world", "yes", "no", 0};
    int count = ft_count_if(words,5, is_longer_than_three);
    printf("Words longer than three characters: %d\n", count);
    return 0;
} */
