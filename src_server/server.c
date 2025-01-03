/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:20:21 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 19:29:57 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// Function to write a massage prefixed by "SERVER:" in blue color
// and followed by a newline character
void	say(char *str)
{
	ft_printf(BLUE "SERVER: " RESET "%s\n", str);
}

// Function to handle a signal
void	handler(int signum)
{
	if (signum == SIGUSR1)
		say("Signal received: SIGUSR1");
	else if (signum == SIGUSR2)
		say("Signal received: SIGUSR2");
}

// Function to confirm the reception of a signal
void	confirm(int signum)
{
	if (signum == SIGUSR1)
		say("Signal confirmed: SIGUSR1");
	else if (signum == SIGUSR2)
		say("Signal confirmed: SIGUSR2");
}

// Function to handle the reception of a signal
void	receive_ascii(int signum)
{
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR2)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c == 0)
			exit(0);
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

// Function 