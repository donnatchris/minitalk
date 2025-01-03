/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:47:32 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 19:17:46 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int ac, char **av)
{
	int		server_pid;

	if (ac != 3)
		error("Invalid input, 2 arguments are required (one PID and a string).");
	server_pid = get_pid(av[1]);
	send_ascii(server_pid, av[2]);
	return (0);
}
