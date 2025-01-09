/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/09 11:28:53 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int ac, char **av)
{	
	if (ac != 3)
		error("2 arguments are required (one PID and a string).");
	signal(SIGUSR2, confirm);
	signal(SIGUSR1, confirm_message);
	send_message(check_pid(av[1]), av[2]);
	error("Server did not confirm. Communication seems to have failed.");
	return (0);
}
