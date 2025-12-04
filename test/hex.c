/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:25:53 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/04 12:44:44 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_verif_base(char *base, int len)
{
	int	i;
	int	j;

	if (len < 2)
		return (1);
	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (1);
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_atoi(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			*sign *= -1;
		}
		i++;
	}
	return (&str[i]);
}

int	ft_in_base(char *str, char *base)
{
	int	j;

	j = 0;
	while (base[j] != '\0')
	{
		if (*str == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nbr;
	int	len;
	int	i;

	sign = 1;
	len = ft_str_len(base);
	if (ft_verif_base(base, len) == 1)
		return (0);
	str = ft_atoi(str, &sign);
	i = 0;
	nbr = 0;
	while (ft_in_base(&str[i], base) >= 0)
	{
		nbr *= len;
		nbr += ft_in_base(&str[i], base);
		i++;
	}
	return (nbr * sign);
}

#include <stdio.h>


int	main(void)
{
	char hex[] = "0xFFFFFF";

	char table[] = "0123456789ABCDEF";

	printf("%d\n", ft_atoi_base(&hex[2], table));

	return (0);

	




	
}
