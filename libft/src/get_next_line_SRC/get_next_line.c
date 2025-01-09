/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:41:34 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 17:24:29 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#include "../../headers/get_next_line_H/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list_gnl	*store[200000];
	t_list_gnl			*error;
	char				*queue;

	if (fd < 0 || fd > 200000 || BUFFER_SIZE <= 0)
		return (NULL);
	queue = NULL;
	if (inventory(store, fd) == -1)
	{
		while (store[fd])
		{
			error = store[fd]->next;
			free(store[fd]->content);
			free(store[fd]);
			store[fd] = error;
		}
		store[fd] = NULL;
	}
	if (!store[fd])
		return (NULL);
	queue = fetch_queue(store[fd]);
	cutting_in(&store[fd]);
	return (queue);
}

int	inventory(t_list_gnl **store, int fd)
{
	int		bill;
	char	*product;

	bill = 0;
	while (!search_newline(store[fd]))
	{
		product = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!product)
			return (bill);
		bill = read(fd, product, BUFFER_SIZE);
		if (bill <= 0)
		{
			free(product);
			product = NULL;
			return (bill);
		}
		product[bill] = '\0';
		stock_replenishment(store, product, fd);
	}
	return (bill);
}

void	stock_replenishment(t_list_gnl **store, char *product, int fd)
{
	t_list_gnl	*new_product;
	t_list_gnl	*last_product;

	last_product = ft_lstlast_gnl(store[fd]);
	new_product = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (!new_product)
		return ;
	if (!last_product)
		store[fd] = new_product;
	else
		last_product->next = new_product;
	new_product->content = product;
	new_product->next = NULL;
}

char	*fetch_queue(t_list_gnl *store)
{
	int		queue_len;
	char	*next_queue;

	if (!store)
		return (NULL);
	queue_len = lstlen_till_newline(store);
	next_queue = (char *)malloc(sizeof(char) * (queue_len + 1));
	if (!next_queue)
		return (NULL);
	cpylst_to_str(store, next_queue);
	return (next_queue);
}

void	cutting_in(t_list_gnl **store)
{
	t_list_gnl	*last_product;
	t_list_gnl	*clean;
	int			i;
	int			j;
	char		*product;

	product = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (!product || !clean)
		return ;
	last_product = ft_lstlast_gnl(*store);
	i = 0;
	j = 0;
	while (last_product->content[i] && last_product->content[i] != '\n')
		i++;
	while (last_product->content[i] && last_product->content[++i])
		product[j++] = last_product->content[i];
	product[j] = '\0';
	clean->content = product;
	clean->next = NULL;
	free_store(store, clean, product);
}

//END
