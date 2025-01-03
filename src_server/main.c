/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 20:09:02 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("SERVER PID: %d\n", pid);
	signal(SIGUSR1, receive_ascii);
	signal(SIGUSR2, receive_ascii);
	while (1)
	{
		;
	}
	return (0);
}