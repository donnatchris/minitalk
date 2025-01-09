/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_printf.c:+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <nifromon@student.42perpignan.+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/15 23:26:40 by nifromon  #+##+# */
/*   Updated: 2024/11/15 23:57:05 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../../headers/ft_printf_H/ft_printf.h"

void	print_format_pc(t_format *percent, va_list arg)
{
	(void) arg;
	ft_putchar_fd('%', FD);
	percent->printed += 1;
}

static int	ft_percent_len(const char *s)
{
	int	i;

	i = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (check_type(s[i]))
			return (i);
		i++;
	}
	return (0);
}

static void	dispatching(int type, t_format *format, va_list arg)
{
	t_dispatch	arr[9];

	arr[C] = &print_format_c;
	arr[S] = &print_format_s;
	arr[P] = &print_format_p;
	arr[D] = &print_format_d;
	arr[I] = &print_format_i;
	arr[U] = &print_format_u;
	arr[X_LOW] = &print_format_x_low;
	arr[X_UPP] = &print_format_x_upp;
	arr[PC] = &print_format_pc;
	arr[type](format, arg);
}

static int	parsing(const char *format, va_list arg)
{
	t_format	*type;
	int			printed;
	int			specifier;

	type = init_struct();
	if (format && type)
	{
		specifier = fetch_type(format);
		type->specifier = specifier;
	}
	dispatching(type->specifier, type, arg);
	printed = type->printed;
	free(type);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		printed;
	int		i;

	printed = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(check_spec(&format[i])))
				return (0);
			printed += parsing(&format[i], arg);
			i += ft_percent_len(&format[i]);
		}
		else
		{
			ft_putchar_fd(format[i], FD);
			printed++;
		}
		i++;
	}
	va_end(arg);
	return (printed);
}

//END