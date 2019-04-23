/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:48:38 by bkristle          #+#    #+#             */
/*   Updated: 2019/02/20 22:48:43 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

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


