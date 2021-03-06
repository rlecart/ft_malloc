/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:10:45 by rlecart           #+#    #+#             */
/*   Updated: 2017/12/20 05:15:03 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_max_val(int *tab, int size)
{
	int		i;
	int		ret;

	i = -1;
	ret = -1;
	while (++i < size)
		if (ret == -1 || (tab[i] > ret && tab[i] > 0))
			ret = tab[i];
	return (ret);
}
