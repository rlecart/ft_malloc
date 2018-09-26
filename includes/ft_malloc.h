/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:20:42 by rlecart           #+#    #+#             */
/*   Updated: 2018/09/26 23:37:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

#include <libft.h>

# define SMALL					8
# define SMALL_MAX				(getpagesize() / 2)
# define TINY					32
# define TINY_MAX				(getpagesize())

typedef struct s_all_structs	t_all_structs;

struct							s_all_structs
{
	char						*small;
	char						*tiny;
	char						*large;
};

#endif
