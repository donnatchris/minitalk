/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 22:37:21 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

char	*message;

int	main(void)
{
	int		pid;

	message = NULL;
	pid = getpid();
	ft_printf("SERVER PID: %d\n", pid);
	signal(SIGUSR1, initialize_reception);
	signal(SIGUSR2, initialize_reception);
	while (1)
	{
		;
	}
	return (0);
}