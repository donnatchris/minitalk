/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/10 00:38:04 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

t_client	*g_client;

int	main(int ac, char **av)
{
	int	timer;

	if (ac != 3)
		error("2 arguments are required (one PID and a string).");
	g_client = NULL;
	g_client = (t_client *) malloc(sizeof(t_client));
	if (!g_client)
		error("allocation memory failed");
	g_client->confirmed = 0;
	g_client->pid = -100;
	initialize_confirmation();
	send_message(check_pid(av[1]), av[2]);
	timer = 0;
	while (timer <= 10000)
	{
		usleep(100);
		timer++;
	}
	error("Server did not confirm. Communication seems to have failed.");
	return (0);
}
