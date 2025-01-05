/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 23:02:03 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_msg	*g_container = NULL;

int	main(void)
{
	signal(SIGINT, close_program);
	ft_printf("SERVER PID: %d\n", getpid());
	ft_printf("Press CTRL + C if you want to close the server.\n");
	allocate_container_memory();
	initialize_receiver();
	while (1)
	{
		if (g_container->signal_received == 1)
		{
			usleep(100);
			if (g_container->time == 1000000)
			{
				receiver_error("Transmission too long. Communication aborted.");
				g_container->signal_received = 0;
			}
			else
				g_container->time += 100;
		}
	}
	return (0);
}
