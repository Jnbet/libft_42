/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnabet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:26:00 by jnabet            #+#    #+#             */
/*   Updated: 2018/11/28 12:25:39 by jnabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_itoa_pos(int n)
{
	long int	m;
	int			len;
	char		*str;

	len = 0;
	m = n;
	if (n == 0)
		len = 1;
	while (m > 0)
	{
		m = m / 10;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	m = n;
	while (len != 0)
	{
		str[len - 1] = m % 10 + 48;
		m = m / 10;
		len--;
	}
	return (str);
}

static char		*ft_itoa_neg(int n)
{
	long int	m;
	int			len;
	char		*str;

	len = 0;
	m = n * -1;
	while (m > 0)
	{
		m = m / 10;
		len++;
	}
	len = len + 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	m = n * -1;
	str[0] = '-';
	while (len != 1)
	{
		str[len - 1] = m % 10 + 48;
		m = m / 10;
		len--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 0)
		res = ft_itoa_pos(n);
	if (n < 0)
		res = ft_itoa_neg(n);
	return (res);
}
