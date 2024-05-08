/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:36:09 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/04/26 17:08:14 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_c(unsigned long nbr, int *c)
{
	if (nbr >= 16)
	{
		ft_c((nbr / 16), c);
		ft_c((nbr % 16), c);
	}
	if (nbr <= 9)
	{
		ft_putchar((nbr % 10) + '0');
		*c = *c + 1;
	}
	else if (nbr < 16 && nbr > 9)
	{
		ft_putchar(nbr - 10 + 'a');
		*c = *c + 1;
	}
}

int	ft_putnbr_pf_x(unsigned long nbr)
{
	int	c;

	c = 0;
	ft_c(nbr, &c);
	return (c);
}
