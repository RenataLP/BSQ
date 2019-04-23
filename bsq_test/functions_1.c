/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:48:31 by bkristle          #+#    #+#             */
/*   Updated: 2019/02/20 22:48:33 by bkristle         ###   ########.fr       */
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

int	ft_min(int a, int b, int c)
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

int	**store_example_file(char **arr2, char ob, char fr, int str_len, int str_num)
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

