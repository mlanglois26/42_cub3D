/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:58:36 by hrischma          #+#    #+#             */
/*   Updated: 2024/06/02 15:58:37 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr_u(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_puthex(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_puthex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

static int	is_valid_format(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_valid_format(format[i + 1]))
		{
			len += ft_format(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	int i, j;
	i = ft_printf("%s, %i", "test", 5);
	j = printf("%s, %i", "test", 5);
	if (i == j)
		printf("OK");
	else
		printf("NOK");
}*/
