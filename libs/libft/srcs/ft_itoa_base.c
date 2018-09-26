/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:51:01 by pbernier          #+#    #+#             */
/*   Updated: 2018/04/08 22:39:49 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_len(int nb, int base)
{
	int		len;

	len = 0;
	if ((nb < 0 && base == 10))
		len++;
	while ((nb /= base) != 0)
		len++;
	return (++len);
}

char	*ft_itoa_base(int value, int base)
{
	int		len;
	int		tmp;
	char	*str;
	char	*b;

	if (!(b = ft_strdup("0123456789abcdef")))
		return (NULL);
	len = int_len(value, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memset(str, '0', len);
	str[len--] = '\0';
	while (value != 0)
	{
		tmp = (value % base);
		if (tmp < 0)
			tmp = -tmp;
		str[len--] = b[tmp];
		value = value / base;
		if (len == 0 && value == 0)
			str[len] = '-';
	}
	ft_strdel(&b);
	return (str);
}
