/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:47:32 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 18:24:55 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int ac, char **av)
{
	if (ac != 3)
		error("Invalid input, 2 arguments are required (one PID and a string).");
	send_message(check_pid(av[1]), av[2]);
	pause();
	return (0);
}
