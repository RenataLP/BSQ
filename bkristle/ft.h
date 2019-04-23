/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:18:00 by pguitar           #+#    #+#             */
/*   Updated: 2019/02/20 22:45:38 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

# define BUF_SIZE 1

int g_a;
int g_fd;
int g_ret;
char g_buf[BUF_SIZE + 1];
int	g_x;
int	g_y;
int	g_result;

typedef struct new_arr 
{
	struct new_arr *next;
	int str_len;
} arr;

arr *g_head_ad;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
char	*ft_strcpy(char *dest, char *src);
void	*ft_swap(int *a, int *b);
void	push_len(arr **head, int str_len);
int		ft_min(int a, int b, int c);
int		**store_example_file(char **arr2, char ob, char fr, int str_len, int str_num);
int		str_len_function(char **arr2);
void	ft_build(char ful, char **arr2);
void	find_coordinates(int c, int i, int j);
int		find_largest_square(int **arr_int, int str_num, char ful, char **arr2);
void	osnova(char *arr, char **arr2, int n, int str_num);
int		size_symbols(char *arr, int i);
int		find_symbols(char *arr);
int		write_first_line(char *arr, char *argv, int str_len_1, int str_num, char **arr2);
char	*create_first_line(char **arr2, int str_len_1, char *argv, int str_num);
char	**write_arr(char **arr2, char *argv, int str_num);
char	**create_arr(int str_len, int str_num, char *argv);
int		pop_arr(arr **head);
void	open_error(int fd);
void	len_error(int str_len, int str_num, arr **head);
void	empty_error(arr **head);
void	initialize(int *str_len,int *str_num);
void	init_2(arr ***head);
char	ft_read(char *argv);
void	ft_input(void);
void	init(int *i, int *j, int *k);

#endif
