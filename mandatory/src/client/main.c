/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/12 09:26:21 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

int	main(int ac, char **av)
{
	if (ac != 3)
		error("2 arguments are required (one PID and a string).");
	send_message(check_pid(av[1]), av[2]);
	return (0);
}
