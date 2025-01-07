/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:47:32 by christophed       #+#    #+#             */
/*   Updated: 2025/01/07 10:00:16 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int ac, char **av)
{
	if (ac != 3)
		error("2 arguments are required (one PID and a string).");
	send_message(check_pid(av[1]), av[2]);
	usleep(1200000);
	error("Server did not confirm. Communication seems to have failed.");
	return (0);
}
