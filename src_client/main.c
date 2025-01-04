/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:47:32 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 22:40:33 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int ac, char **av)
{
	int		server_pid;

	if (ac != 3)
		error("Invalid input, 2 arguments are required (one PID and a string).");
	server_pid = get_pid(av[1]);
	initialize_transmission(server_pid, av[2]);
	usleep(100);
	send_str(server_pid, av[2]);
	end_transmission(server_pid);
	return (0);
}
