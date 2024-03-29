/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2018/11/20 18:56:18 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr != 0 && len == 0)
	{
		if (nbr < 0)
			len++;
		while (nbr != 0)
		{
			nbr = nbr / 10;
			len++;
		}
	}
	else if (nbr == 0 && len == 0)
		len++;
	return (len);
}
