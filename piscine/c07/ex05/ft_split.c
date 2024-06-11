/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:00:42 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/18 14:00:44 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_c(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_str_num(char *str, char *charset, int initial)
{
	int	index;
	int	prev;
	int	count;

	if (str[0] == '\0')
		return (0);
	index = 1;
	prev = initial;
	if (initial == 0)
		count = 1;
	else
		count = 0;
	while (str[index] != 0)
	{
		if (prev && !is_c(str[index], charset))
				count++;
		prev = is_c(str[index++], charset);
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size == 0)
		return (src_len);
	index = 0;
	while (src[index] != '\0' && index < size -1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (src_len);
}

char	**ft_split(char *str, char *charset)
{
	char	**results;
	int		info[3];

	info[0] = 0;
	info[2] = count_str_num(str, charset, is_c(str[0], charset));
	results = (char **)malloc((info[2] + 1) * sizeof (char *));
	while (info[0] < info[2])
	{
		while (is_c(str[0], charset) == 1)
		{
			if (*str++ == '\0')
			{
				results[info[0]] = "0";
				break ;
			}
		}
		info[1] = 0;
		while (str[info[1]] != 0 && is_c(str[info[1]], charset) == 0)
			info[1]++;
		results[info[0]] = (char *)malloc((info[1] + 1) * sizeof (char));
		ft_strlcpy(results[info[0]++], str, info[1] + 1);
		str += info[1] + 1;
	}
	results[info[2]] = NULL;
	return (results);
}

// #include <stdio.h>
// #include <stdio.h>

// // ft_split関数とその依存関数のプロトタイプをここに含める

// void print_results(char **results) {
// 	if (!results) {
// 		printf("NULL\n");
// 		return;
// 	}
// 	for (int i = 0; results[i] != NULL; i++) {
// 		printf("Result[%d]: \"%s\"\n", i, results[i]);
// 	}
// }

// void free_results(char **results) {
// 	if (!results) {
// 		return;
// 	}
// 	for (int i = 0; results[i] != NULL; i++) {
// 		free(results[i]);
// 	}
// 	free(results);
// }

// void test_ft_split(char *str, char *charset) {
// 	printf("Testing split of \"%s\" by \"%s\":\n", str, charset);
// 	char **results = ft_split(str, charset);
// 	print_results(results);
// 	free_results(results);
// 	printf("-------------------------------------------------\n");
// }

// int main() {
// 	// 正常なケース
// 	test_ft_split("hello world", " ");
// 	test_ft_split("lorem ipsum dolor sit amet", "");

// 	// エッジケース: 空の文字列
// 	test_ft_split("", " ");

// 	// エッジケース: 区切り文字のみ
// 	test_ft_split("  ", " ");
// 	test_ft_split("dddd", "d");

// 	// 特殊ケース: 文字列の先頭と末尾に区切り文字がある
// 	test_ft_split(" hello world ", " ");

// 	// 複数の区切り文字
// 	test_ft_split("hello,world,this,is,a,test", ",,");

// 	// 区切り文字が文字列に含まれない
// 	test_ft_split("hello", ",");

// 	// 文字列が区切り文字のみで構成される
// 	test_ft_split(",,,,", ",");

// 	test_ft_split("IYSLT4kzaU0xFe4KVTqSyTOhVSY4CnaHUHBfhyXhoS78Z7", "nj");
// 	return 0;
// }