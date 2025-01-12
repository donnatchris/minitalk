/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:37:15 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/12 09:56:21 by christophed      ###   ########.fr       */
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
			if (g_container->time >= 20000)
				error("timeout");
		}
	}
	return (0);
}
