/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:37:15 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 11:04:10 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

t_msg	*g_container;

int	main(void)
{
	signal(SIGINT, close_program);
	g_container = (t_msg *) malloc(sizeof(t_msg));
	if (!g_container)
		error("allocation memory failed");
	g_container->len_str = (char *) malloc(sizeof(char) * 11);
	if (!g_container->len_str)
		error("memory allocation failed");
	ft_printf("SERVER PID: %d\n", getpid());
	ft_printf("Press CTRL + C if you want to close the server.\n");
	initialize_container();
	initialize_len();
	while (1)
	{
		if (g_container->chrono_on)
		{
			usleep(100);
			g_container->time++;
			if (g_container->time >= 40000)
				error("timeout");
		}
	}
	if (g_container->msg)
		free(g_container->msg);
	return (0);
}
