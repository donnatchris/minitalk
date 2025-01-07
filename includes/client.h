/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:57:35 by christophed       #+#    #+#             */
/*   Updated: 2025/01/07 14:56:47 by chdonnat         ###   ########.fr       */
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
void	send_char(int server_pid, char c);
void	send_str(int server_pid, char *str);
void	send_len(int server_pid, int len);

#endif
