/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:53:16 by bkristle          #+#    #+#             */
/*   Updated: 2019/02/20 22:53:18 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

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
