/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 17:44:03 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_msg	*container;

int	main(void)
{
	signal(SIGINT, close_program);
	allocate_container_memory();
	initialize_receiver();
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		if (container->signal_received == 1)
		{
			usleep(10);
			if (container->time == 1000000)
			{
				receiver_error("Transmission too long. Communication aborted.");
				container->signal_received = 0;
			}
			else
				container->time += 10;
		}
    }
	return (0);
}
