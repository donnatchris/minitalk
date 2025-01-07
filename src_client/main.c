/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:47:32 by christophed       #+#    #+#             */
/*   Updated: 2025/01/07 16:31:33 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	confirm(int signum)
{
	(void) signum;
}

int	main(int ac, char **av)
{
	if (ac != 3)
		error("2 arguments are required (one PID and a string).");
	signal(SIGUSR2, confirm);
	send_message(check_pid(av[1]), av[2]);
	error("Server did not confirm. Communication seems to have failed.");
	return (0);
}
