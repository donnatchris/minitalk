/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:23:34 by christophed       #+#    #+#             */
/*   Updated: 2025/01/07 14:52:05 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_msg	*g_container;

int	main(void)
{
	signal(SIGINT, close_program);
	g_container = (t_msg *) malloc(sizeof(t_msg));
	if (!g_container)
		error("allocation memory failed");
	g_container->len_str = (char *) malloc(sizeof(char) * 11);
	if (!g_container->len_str)
		error("memory allocation failed");
	ft_printf("SERVER PID: %d\n", getpid());
	ft_printf("Press CTRL + C if you want to close the server.\n");
	initialize_container();
	initialize_len();
	while (1)
		;
	return (0);
}
