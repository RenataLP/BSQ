/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:05:07 by bkristle          #+#    #+#             */
/*   Updated: 2019/02/20 22:45:40 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	push_len(arr **head, int str_len) // кладем новый элемент на стек
{
	arr *tmp; 

	tmp = malloc(sizeof(arr));
	if (tmp == NULL)
		return;
	tmp->next = *head;
	tmp->str_len = str_len;
	*head = tmp;
}

int ft_min(int a, int b, int c)
{
	if ((a <= b && b <= c) || (a <= c && c <= b))  
		return (a);
	else if ((b <= a && a <= c) || (b <= c && c <= a))
		return (b);
	else if ((c <= a && a <= b) || (c <= b && b <= a))
		return (c);
	else
		return (0);
}

int	change_symbols(char c, char fr, char ob)
{
	int a;

	if	(c == fr)
		a = 1;
	else if ( c == ob)
		a = 0;
	return (a);
}

int **store_example_file(char **arr2, char ob, char fr, int str_len, int str_num)
{
	int i;
	int j;
	int **arr_int;

	i = 0;
	arr_int = (int **)malloc(sizeof(int *) * str_num);
	while (i < str_num)
	{
		arr_int[i] = (int *)malloc(sizeof(int) * (str_len + 1));
		j = 0;
		while (j < str_len)
		{
			if ((arr2[i][j] != fr && arr2[i][j] != ob))
			{
				write(2, "map error\n", 10);
				exit (0);
			}
			arr_int[i][j] = change_symbols(arr2[i][j], fr, ob);
			j++;
		}
		arr_int[i][j] = -1;
		i++;
	}
	return (arr_int);
}

int	str_len_function(char **arr2)
{
	int j;

	j = 0;
	while (arr2[0][j] != '\n')
	{
		j++;
	}
	return (j);
}

void	ft_build(char ful, char **arr2)
{
	int i;
	int j;
	int n;
	int a;
	int b;

	i = 0;
	b = g_y + 1 - g_result;
	while (b <= g_y)
	{
		a = g_x + 1 - g_result;
		while (a <= g_x)
		{
			arr2[b][a] = ful;
			a++;
		}
		b++;
	}
	while (arr2[i][0] != '\0')
	{
		ft_putstr(arr2[i]);
		i++;
	}
}

void	find_coordinates(int c, int i, int j)
{
	if (c > g_result)
	{
		g_result = c;
		g_y = i;
		g_x = j - 1;
	}
}

int	find_largest_square(int **arr_int, int str_num, char ful, char **arr2)
{
	int i;
	int j;

	i = 0;
	g_result = 0;
	while(i < str_num)
	{
		j = 0;
		while(arr_int[i][j] != -1)
		{
			if ( i == 0 || j == 0 || arr_int[i][j] == 0)
				j++;
			else
			{
				arr_int[i][j] = arr_int[i][j] + ft_min(arr_int[i][j - 1],
						arr_int[i - 1][j], arr_int[i - 1][j - 1]);
				j++;
			}
			find_coordinates(arr_int[i][j - 1], i, j);
		}
		i++;
	}
	ft_build(ful, arr2);
	return(0);
}

void	osnova(char *arr, char **arr2, int n, int str_num)
{
	int ful;
	int ob;
	int fr;

	fr = arr[n];
	ob = arr[n + 1];
	ful = arr[n + 2];
	find_largest_square(store_example_file(arr2, ob, fr,
				str_len_function(arr2), str_num), str_num, ful, arr2);
}

int	size_symbols(char *arr, int i)
{
	int j;
	char *sz_sym;

	j = 0;
	sz_sym = (char *)malloc(sizeof(char) * i);
	while (j < i)
	{
		sz_sym[j] = arr[j];
		j++;
	}
	sz_sym[j] = '\0';
	j = ft_atoi(sz_sym);
	free(sz_sym);
	return (j);
}

int	find_symbols(char *arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i - 1);
}
	
int		write_first_line(char *arr, char *argv, int str_len_1, int str_num, char **arr2)
{
	int i;
	int n;

	i = 0;
	g_fd = open(argv, O_RDONLY);
	while ((g_ret = read(g_fd, g_buf, BUF_SIZE)))
	{
		if (g_buf[g_ret - 1] == '\n')
		{
			arr[i] = '\0';
			break;
		}
		arr[i] = g_buf[g_ret - 1];
		i++;
	}
	n = find_symbols(arr)- 2;
	if (size_symbols(arr, n) != str_num)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	osnova(arr, arr2, n, str_num);
	return (0);
}

char	*create_first_line(char **arr2, int str_len_1, char *argv, int str_num)
{
	char *arr;

	arr = (char *)malloc(sizeof(char) * str_len_1);
	write_first_line(arr, argv, str_len_1, str_num, arr2);
	return arr;
}

void	init(int *i, int *j, int *k)
{
	*k = 0;
	*i = 0;
	*j = 0;
}

char	**write_arr(char **arr2, char *argv, int str_num)
{
	int i;
	int j;
	int k;

	init(&i, &j, &k);
	g_fd = open(argv, O_RDONLY);
   	open_error(g_fd);	
	while ((g_ret = read(g_fd, g_buf, BUF_SIZE)))
	{
		if (g_buf[g_ret - 1] == '\n' && k == 0)
			k++;
		else if (g_buf[g_ret - 1] == '\n')
		{
			arr2[i][j] = '\n';
			i++;
			j = 0;
		}
		else if (k == 1)
		{
			arr2[i][j] = g_buf[g_ret - 1];
			j++;
		}
	}
	arr2[i][0] = '\0';
	return (arr2);
}

char	**create_arr(int str_len, int str_num, char *argv)
{	
	char **arr2;
	int i;

	i = 0;
	arr2 = (char **)malloc(sizeof(char *)*str_num);
	while (i < str_num - 1)
	{
		arr2[i] = (char *)malloc(sizeof(char) * str_len);
		i++;
	}
	arr2[i] = (char *)malloc(sizeof(char) * 1);
	arr2 = write_arr(arr2, argv, str_num);
	return (arr2);	
}

int pop_arr(arr **head)
{
	arr *out;
	int str_len;
	while ((*head) != NULL)
	{
		out = *head;
		*head = (*head)->next;
		str_len = out->str_len;
		free(out);
	}
	return str_len;
}

void	open_error(int fd)
{
	if (fd == -1)
	{
		write(2, "open() error", 13);
		exit (0);
	}
}

void	len_error(int str_len, int str_num, arr **head)
{
	if ((str_num > 1) && ((str_len + 1) != (*head)->str_len))
	{
		write(2, "map error\n", 10);
		exit (0);
	}
}

void	empty_error(arr **head)
{
	if (*head == NULL)
	{
		write(2, "map error\n", 10);
		exit (0);
	}
}

void	initialize(int *str_len,int *str_num)
{
	*str_len = 0;
	*str_num = 0;
}

void	init_2(arr ***head)
{
	g_head_ad = NULL;
	*head = &g_head_ad; 	
}

char	ft_read(char *argv)
{
	int str_len;
	int str_num;
	arr **head;

	initialize(&str_len, &str_num);
	init_2(&head);
	g_fd = open(argv, O_RDONLY);
	open_error(g_fd);
	while ((g_ret = read(g_fd, g_buf, BUF_SIZE)))
	{
		g_a = str_num;
		if (g_buf[g_ret - 1] == '\n')
		{
			len_error(str_len, str_num++, head);
			push_len(head, str_len + 1);
			str_len = 0;
		}
		if (g_a == str_num)
			str_len++;
	}
	empty_error(head);
	create_first_line(create_arr((*head)->str_len, str_num, argv), 
			pop_arr(head), argv, str_num - 1);
	close(g_fd);
	return (0);
}
	
void	ft_input(void) // если параметров нет, то работает как функция "cat"
{
	g_fd = 0;
	while ((g_ret = read(g_fd, g_buf, BUF_SIZE)))
	{
		g_buf[g_ret] = '\0';
		ft_putstr(g_buf);
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	argc = argc + 0;
	if (argc == 1)
	{
		ft_input();
	}
	while (i < argc)
	{
		ft_read(argv[i]);
		i++;
	}
	return (0);
}
