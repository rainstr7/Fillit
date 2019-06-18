/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaggio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:53:42 by cmaggio           #+#    #+#             */
/*   Updated: 2019/02/05 20:09:34 by cmaggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c, int *sign, int *in_num)
{
	if (*in_num == 0)
	{
		if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\r' || c == '\f')
			return (1);
		else if (c == '-')
		{
			*sign = -1;
			*in_num = 1;
			return (1);
		}
		else if (c == '+')
		{
			*in_num = 1;
			return (1);
		}
		else if (c >= '0' && c <= '9')
		{
			*in_num = 1;
			return (0);
		}
	}
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int		i;
	int		in_num;
	long	result;
	int		sign;

	i = 0;
	in_num = 0;
	result = 0;
	sign = 1;
	while (nptr[i] != '\0')
	{
		if (is_space(nptr[i], &sign, &in_num))
			i++;
		else if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			result = (result * 10) + (nptr[i++] - 48);
		}
		else
			break ;
	}
	return (result * sign);
}
