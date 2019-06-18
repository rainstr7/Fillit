/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2018/11/20 18:56:18 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_power(int nbr, int power)
{
	int result;
	int i;

	result = 1;
	i = 0;
	while (i < power)
	{
		result = result * nbr;
		i++;
	}
	return (result);
}

static int	ft_sign(int nbr)
{
	if (nbr > 0)
		return (1);
	else if (nbr < 0)
		return (-1);
	else
		return (0);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		div;
	int		i;
	int		len;

	div = 0;
	i = 0;
	len = ft_nbrlen(n);
	if (!(result = (char *)malloc(len + 1)))
		return ((void *)0);
	if (n < 0)
	{
		result[i++] = '-';
		len--;
	}
	div = (ft_power(10, len - 1));
	while (div > 0)
	{
		result[i++] = (n / div) * ft_sign(n) + 48;
		n = n % div;
		div = div / 10;
	}
	result[i] = '\0';
	return (result);
}
