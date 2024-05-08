/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:50:23 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/04/26 17:28:43 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(char type, va_list element)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(element, int));
	else if (type == 's')
		count += ft_putstr_pf(va_arg(element, char *));
	else if (type == 'p')
		count += ft_p((unsigned long)va_arg(element, void *));
	else if (type == 'd')
		count += ft_putnbr_pf(va_arg(element, int));
	else if (type == 'i')
		count += ft_putnbr_pf(va_arg(element, int));
	else if (type == 'u')
		count += ft_putnbr_unsigned(va_arg(element, unsigned int));
	else if (type == 'x')
		count += ft_putnbr_x(va_arg(element, unsigned int));
	else if (type == 'X')
		count += ft_putnbr_he(va_arg(element, unsigned int));
	else if (type == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	element;
	int		i;
	int		count;

	va_start(element, format);
	i = 0;
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], element);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(element);
	return (count);
}
