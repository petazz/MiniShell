/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf_he.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:27 by pgonzal2          #+#    #+#             */
/*   Updated: 2023/10/24 17:53:21 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chex(unsigned int nbr, int *c)
{
	if (nbr >= 16)
	{
		ft_chex((nbr / 16), c);
		ft_chex((nbr % 16), c);
	}
	if (nbr <= 9)
	{
		ft_putchar((nbr % 10) + '0');
		*c = *c + 1;
	}
	else if (nbr < 16 && nbr > 9)
	{
		ft_putchar(nbr - 10 + 'A');
		*c = *c + 1;
	}
}

int	ft_putnbr_pf_he(unsigned int nbr)
{
	int	c;

	c = 0;
	ft_chex(nbr, &c);
	return (c);
}
