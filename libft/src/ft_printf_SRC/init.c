/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   init.c  :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 23:00:21 by nifromon  #+##+# */
/*   Updated: 2024/11/15 23:24:52 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../../headers/ft_printf_H/ft_printf.h"

int	fetch_type(const char *format)
{
	int	i;

	i = 0;
	if (format[i] == '%')
		i++;
	while (!(check_type(format[i])) && format[i])
		i++;
	if (format[i] == 'c')
		return (C);
	else if (format[i] == 's')
		return (S);
	else if (format[i] == 'd')
		return (D);
	else if (format[i] == 'i')
		return (I);
	else if (format[i] == 'u')
		return (U);
	else if (format[i] == 'x')
		return (X_LOW);
	else if (format[i] == 'X')
		return (X_UPP);
	else if (format[i] == '%')
		return (PC);
	return (P);
}

t_format	*init_struct(void)
{
	t_format	*format;

	format = (t_format *)malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	format->hashtag = 0;
	format->zero = 0;
	format->hyphen = 0;
	format->blank = 0;
	format->plus = 0;
	format->width = 0;
	format->precision = 0;
	format->specifier = 0;
	format->printed = 0;
	return (format);
}

int	fill_type(const char *s, t_format *format)
{
	if (!format)
		return (-1);
	format->specifier = fetch_type(s);
	return (format->specifier);
}

//END