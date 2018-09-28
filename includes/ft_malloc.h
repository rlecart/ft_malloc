/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:20:42 by rlecart           #+#    #+#             */
/*   Updated: 2018/09/28 22:07:21 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

#include <libft.h>

# define SMALL					8
# define SMALL_MAX				(getpagesize() / 2)
# define TINY					32
# define TINY_MAX				(getpagesize())

typedef struct s_small			t_small;
typedef struct s_tiny			t_tiny;
typedef struct s_large			t_large;
typedef struct s_all_structs	t_all_structs;

struct							s_small
{
	char						content[SMALL];
	t_small						*prev;
	t_small						*next;
	t_small						*last;
};

struct							s_tiny
{
	char						content[TINY];
	t_tiny						*prev;
	t_tiny						*next;
	t_tiny						*last;
};

struct							s_large
{
	char						content[TINY];
	t_tiny						*prev;
	t_tiny						*next;
	t_tiny						*last;
};

struct							s_all_structs
{
	t_small						*small;
	t_tiny						*tiny;
	t_large						*large;
};

#endif
