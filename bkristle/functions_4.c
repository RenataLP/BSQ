/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:51:52 by bkristle          #+#    #+#             */
/*   Updated: 2019/02/20 22:51:53 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

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

int	pop_arr(arr **head)
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


