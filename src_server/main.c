/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 21:46:39 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_msg	*container;

int	main(void)
{
	signal(SIGINT, close_program);
	ft_printf("SERVER PID: %d\n", getpid());
	ft_printf("Press CTRL + C if you want to close the server.\n");
	allocate_container_memory();
	initialize_receiver();
	while (1)
	{
		if (container->signal_received == 1)
		{
			usleep(100);
			if (container->time == 1000000)
			{
				receiver_error("Transmission too long. Communication aborted.");
				container->signal_received = 0;
			}
			else
				container->time += 100;
		}
	}
	return (0);
}
