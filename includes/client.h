/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:46:37 by christophed       #+#    #+#             */
/*   Updated: 2025/01/03 20:05:48 by christophed      ###   ########.fr       */
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
int		get_pid(char *str);
void	error(char *str);
int		is_number(char *str);
void	send_ascii(int server_pid, char *str);
void	end_transmission(int server_pid);

#endif
