/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:05:56 by chdonnat          #+#    #+#             */
/*   Updated: 2025/01/07 16:45:17 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"
#include <signal.h>

// Function to close the program gracefully when receiving SIGINT
void	close_program(int signum)
{
	(void) signum;
	initialize_container();
	if (g_container)
	{
		if (g_container->len_str)
			free(g_container->len_str);	
		free(g_container);
	}
	exit (0);
}

// Function to check if a string is a number
int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

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
		g_container->pid = -100;
		g_container->len = 0;
		ft_bzero(g_container->len_str, 11);
	}
}

// Function to display an error message and reinitialize the receiver
void	error(char *str)
{
	ft_printf("\x1b[31mRECEPTION ERROR:\x1b[0m %s\n", str);
	if (ft_strncmp(str, "memory allocation failed", ft_strlen(str)))
	{
		initialize_container();
		if (g_container)
		{
			if (g_container->len_str)
				free(g_container->len_str);	
			free(g_container);
		}
		exit(0);
	}
	initialize_container();
	initialize_len();
}

// Function to initialize reception by waiting for msg_len
void	initialize_len(void)
{
    struct sigaction	act;
    sigset_t			set;

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

// Function to receive the msg_len
void    check_msg_len(int signum, siginfo_t *info, void *context)
{
    static char	    c = 0;
	static int	    i = 0;

	if (context == NULL)
		ft_printf("Pas de contexte\n");
	if (g_container->pid == -100)
	{
		g_container->pid = info->si_pid;
	}
    if (info->si_pid == g_container->pid)
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
    }
	confirm_bit_reception();
}

// Function to confirm the reception of each bit to the client
void	confirm_bit_reception(void)
{
	usleep(100);
	kill(g_container->pid, SIGUSR2);
}

// Function to store the msg_len and verify it before launching the msg reception
void    store_msg_len(char c)
{
    static int  i = 0;

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

// Function to initialize the reception of the msg and malloc the msg
// according to the msg_len received
void    initialize_msg(void)
{
    struct sigaction       act;
    sigset_t				set;

    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = receive_msg;
    act.sa_mask = set;
	g_container->msg = (char *) malloc(sizeof(char) * (g_container->len + 1));
	if (!g_container->msg)
		error("memory allocation failed");
	ft_printf("Receiver initialized. Waiting for msg...\n");
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		error("sigaction error");
    if (sigaction(SIGUSR2, &act, NULL) == -1)
		error("sigaction error");
}

// Function to receive the msg
void    receive_msg(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	
	if (context == NULL)
		ft_printf("Pas de contexte\n");
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
		confirm_bit_reception();
    }
}

// Function to store the msg in the string msg
void    store_msg(char c)
{
    static int  i = 0;
	
	ft_printf("%c\n", c);
    g_container->msg[i] = c;
	i++;
	if (i == g_container->len + 1)
	{
		i = 0;
		if (c != '\0')
			error("message did not reach the end");
		else
		{
			confirm_bit_reception();
			end_reception();
		}
	}
}

// Function to print the msg and reinitialize the receiver
void	end_reception(void)
{
	ft_printf("Message received from client %d:\n", g_container->pid);
	ft_printf("%s\n", g_container->msg);
	initialize_container();
	initialize_len();
}
