/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/04 14:44:11 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_msg	*container;

int	main(void)
{
	signal(SIGINT, close_program);
	allocate_container_memory();
	initialize_receiver();
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		;
	}
	return (0);
}
