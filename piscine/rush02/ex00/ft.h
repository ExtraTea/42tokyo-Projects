/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:52:17 by dtakamat          #+#    #+#             */
/*   Updated: 2024/02/25 14:52:19 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <libgen.h>
# include <sys/stat.h>
# include <fcntl.h>

int				ft_strcmp(char *s1, char*s2);
char			*ft_strdup(char *src);
int				ft_strlen(char *str);
char			*ft_itoa(int num);
int				count_digit(int num);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_atoi(char *str);
char			**ft_split(char *str, char *charset);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
long			count_file_len(char *name);
char			*ft_check_arg(int argc, char **argv);
char			*ft_atoa(char *str, int start, int end);
void			strong_free(char *a, char *b, char **c);
int				ft_colon_not_one(char **entry);
void			ft_clean_value(char *value);
char			*read_file(char *dictname);
int				check_result2(char **result1);

typedef struct s_keyvalue{
	char	*key;
	char	*value;
}	t_keyvalue;

typedef struct s_node{
	t_keyvalue		kvp;
	struct s_node	*next;
}	t_node;

int				insert(t_node **head, char *key, char *value);
char			*search(t_node *head, char *key);
void			free_list(t_node **head);
t_node			*read_n_insert(char *dictname);
void			write_all(char *num, t_node *head);
void			write_rec(char *num, int len, t_node *head, int is_first);
char			*make_10_power(int len, char *result);
int				write_pre_val(char *num, t_node *head);
int				ft_error_value(char *entry);

#endif
