/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2018/11/20 18:56:18 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_power(int nbr, int power)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (i < power)
	{
		result = result * nbr;
		i++;
	}
	return (result);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		div;
	int		i;
	int		len;
	int		sign;

	sign = 1;
	div = 0;
	i = 0;
	len = ft_nbrlen(n);
	if (n < 0)
	{
		write(fd, "-", 1);
		sign = -1;
		len--;
	}
	div = (ft_power(10, len - 1));
	while (div > 0)
	{
		c = (n / div) * sign + '0';
		write(fd, &c, 1);
		n = n % div;
		div = div / 10;
		i++;
	}
}
