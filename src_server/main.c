/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 19:44:28 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	main(void)
{
	int		pid;

	signal(SIGUSR1, receive_ascii);
	signal(SIGUSR2, receive_ascii);
	pid = getpid();
	say(ft_itoa(pid));
	while (1)
	{
		;
	}
	return (0);
}