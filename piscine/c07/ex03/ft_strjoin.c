/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:43:52 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/15 14:48:16 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	srcindex;

	index = 0;
	while (dest[index] != '\0')
		index++;
	srcindex = 0;
	while (src[srcindex] != '\0')
	{
		dest[index] = src[srcindex];
		index++;
		srcindex++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		index;
	char	*result;

	if (size == 0)
	{
		result = (char *)malloc(1);
		result[0] = '\0';
		return (result);
	}
	len = 0;
	index = 0;
	while (index < size)
		len += ft_strlen(strs[index++]);
	result = (char *)malloc((len + ft_strlen(sep)
				* (size - 1) + 1) * sizeof (char));
	result[0] = '\0';
	ft_strcat(result, strs[0]);
	index = 1;
	while (index < size)
	{
		ft_strcat(result, sep);
		ft_strcat(result, strs[index++]);
	}
	return (result);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ここに ft_strlen, ft_strcat, ft_strjoin 関数の実装を含める

void test_ft_strjoin(char **strs, int size, char *sep, char *expected) {
    char *result = ft_strjoin(size, strs, sep);
    if (result != NULL) {
        printf("Result  : %s\n", result);
        printf("Expected: %s\n", expected);
        if (expected != NULL && strcmp(result, expected) == 0) {
            printf("Test passed.\n");
        } else {
            printf("Test failed.\n");
        }
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }
    printf("--------------\n");
}

int main() {
    // テストケース1: 通常のケース
    char *strs1[] = {};
    test_ft_strjoin(strs1, 0, " ", "Hello world in C");

    // // テストケース2: 空の区切り文字
    // test_ft_strjoin(strs1, 4, "", "HelloworldinC");

    // // テストケース3: サイズが0
    // test_ft_strjoin(strs1, 0, " ", "");

    // // テストケース4: 1つの要素のみ
    // char *strs2[] = {"OnlyOne"};
    // test_ft_strjoin(strs2, 1, ", ", "OnlyOne");

    // // テストケース5: 空の文字列を含む
    // char *strs3[] = {"", "has", "", "empty", ""};
    // test_ft_strjoin(strs3, 5, "-", "-has--empty-");

    // // テストケース6: 全て空の文字列
    // char *strs4[] = {"", "", ""};
    // test_ft_strjoin(strs4, 3, " ", "  ");

    return 0;
}
