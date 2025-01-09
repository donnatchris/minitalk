/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/09 12:12:44 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	g_confirmed;

int	main(int ac, char **av)
{
	int	timer;

	if (ac != 3)
		error("2 arguments are required (one PID and a string).");
	g_confirmed = 0;
	signal(SIGUSR2, confirm);
	signal(SIGUSR1, confirm);
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
