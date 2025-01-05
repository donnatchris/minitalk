/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:57:35 by christophed       #+#    #+#             */
/*   Updated: 2025/01/05 16:14:07 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../libft/includes/libft.h"

// Functions
// client.c
// various functions
void	error(char *str);
int		is_number(char *str);
int		check_pid(char *str);
void	confirmation(int signum);
// transmitter.c
// functions to send messages by using 2 signals
void	send_message(int server_pid, char *str);
void	send_ping(int server_pid);
void	send_char(int server_pid, char c);
void	send_str(int server_pid, char *str);
void	send_pid(int server_pid, int client_pid);

#endif
