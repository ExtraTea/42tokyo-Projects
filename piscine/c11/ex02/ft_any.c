/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:43:38 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/27 17:43:39 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	index;

	index = 0;
	while (tab[index] != 0)
	{
		if (f(tab[index]) != 0)
			return (1);
		index++;
	}
	return (0);
}

/* #include <stdio.h>

int starts_with_a(char *str) {
    return (str[0] == 'a');
}

int main() {
    char *words[] = {"hello", "world", "apple", "banana", 0};
    if (ft_any(words, starts_with_a)) {
        printf("At least one word starts with 'a'\n");
    } else {
        printf("No words start with 'a'\n");
    }
    return 0;
} */
