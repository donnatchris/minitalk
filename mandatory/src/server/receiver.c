/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:37:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/21 11:06:16 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

// Function to receive the msg_len
void	check_msg_len(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;

	(void) context;
	if (g_container->pid == -100)
		g_container->pid = info->si_pid;
	if (info->si_pid == g_container->pid)
	{
		if (signum == SIGUSR2)
			c |= 1 << i;
		i++;
		if (i == 8)
		{
			store_msg_len(c);
			c = 0;
			i = 0;
		}
	}
}

// Function to store the msg_len
// and verify it before launching the msg reception
void	store_msg_len(char c)
{
	static int	i = 0;

	g_container->len_str[i] = c;
	i++;
	if (i == 10)
	{
		if (!is_number(g_container->len_str))
			error("incorrect message len");
		else
		{
			g_container->len = ft_atoi(g_container->len_str);
			initialize_msg();
		}
		i = 0;
	}
}

// Function to receive the msg
void	receive_msg(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;

	(void) context;
	if (info->si_pid == g_container->pid)
	{
		if (signum == SIGUSR2)
			c |= 1 << i;
		i++;
		if (i == 8)
		{
			store_msg(c);
			i = 0;
			c = 0;
		}
	}
}

// Function to store the msg in the string msg
void	store_msg(char c)
{
	static int	i = 0;

	if (g_container->store_msg == 0)
	{
		g_container->store_msg = 1;
		i = 0;
	}
	g_container->msg[i] = c;
	i++;
	if (i == g_container->len + 1)
	{
		i = 0;
		if (c != '\0')
			error("message did not reach the end");
		else
			end_reception();
	}
}

// Function to print the msg and reinitialize the receiver
void	end_reception(void)
{
	ft_printf("Message received from client %d:\n", g_container->pid);
	ft_printf("\033[0;32m%s\033[0m\n", g_container->msg);
	if (g_container->msg)
		free(g_container->msg);
	initialize_container();
	initialize_len();
}
