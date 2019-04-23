/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:50:29 by bkristle          #+#    #+#             */
/*   Updated: 2019/02/20 22:50:32 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

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
	
int	write_first_line(char *arr, char *argv, int str_len_1, int str_num, char **arr2)
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


