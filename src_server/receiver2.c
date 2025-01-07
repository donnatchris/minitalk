/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:05:56 by chdonnat          #+#    #+#             */
/*   Updated: 2025/01/07 13:27:47 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"
#include <signal.h>

// Function to initialize the g_container variables
void	initialize_container(void)
{
	if (g_container)
	{
		if (g_container->msg)
		{
			free(g_container->msg);
			g_container->msg = NULL;
		}
		g_container->pid = 0;
		g_container->len = 0;

	}
}

// Function to display an error message and reinitialize the receiver
void	receiver_error(char *str)
{
	ft_printf("\x1b[31mRECEPTION ERROR:\x1b[0m %s\n", str);
	initialize_len();
}

// Function to initialize the receiver
// by initializing the container and the signals
void	initialize_len(void)
{
    struct sigaction	act;
    sigset_t			set;

	initialize_container();
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = check_msg_len;
    act.sa_mask = set;
	ft_printf("Receiver initialized. Waiting for msg_len...\n");
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		error("sigaction error");
    if (sigaction(SIGUSR2, &act, NULL) == -1)
		error("sigaction error");
}

void    check_msg_len(int signum, siginfo_t *info, void *context)
{
    static char	    c = 0;
	static int	    i = 0;

	if (g_container->pid == 0)
	{
		g_container->pid = info.si_pid;
	}
    if (info.si_pid == g_container->pid)
    {
        if (signum == SIGUSR2)
	        c |= 1 << i;
	    i++;
	    if (i == 8)
	    {
	    	store_msg_len(c);
	    	i = 0;
	    	c = 0;
	    }
        confirm_bit_reception(g_container->pid);
    }
}
void    store_msg_len(char c)
{
    static char msg_len[11] = "0000000000";
    static int  i = 0;

    msg_len[i] = c;
	i++;
	if (i == 10)
    {
        msg_len[11] = '/0';
        if (!is_number(msg_len))
            error("incorrect message len");
        else
		{
			g_container->len = ft_atoi(msg_len);
            initialize_msg();
		}
        ft_strcpy (msg_len, "0000000000");
        i = 0;
    }
}

void    initialize_msg(void)
{
    struct sigaction       act;
    sigset_t				set;

    sigemptyset(set);
    sigaddset(set, SIGUSR1);
    sigaddset(set, SIGUSR2);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = receive_msg;
    act.sa_mask = set;
	g_container->msg = (char *) malloc(sizeof(char) * (g_container->len + 1));
	if (!g_container->msg)
		error("allocation memory error");
	ft_printf("Receiver initialized. Waiting for msg...\n");
	sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}
void    receive_msg(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	
	if (info.si_pid == g_container->pid)
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
        confirm_bit_reception(g_container->pid);
    }
}

void    store_msg(char c)
{
    static int  i = 0;

	if (i == g_container->len)
	{
		if (c != '/0')
			error("message did not reach the end");
		else
			end_reception();
		i == 0;
	}
	else
	{
    	g_container->msg[i] = c;
		i++;
	}
}








// Function to receive a message bit by bit
// and send each complete caracter to the store_msg function
void	receive_msg(int signum)
{
	static char	c = 0;
	static int	i = 0;
	if (g_container->receive_initializer == 0)
	{
		c = 0;
		i = 0;
		g_container->receive_initializer = 1;
	}
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