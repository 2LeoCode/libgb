/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:04:41 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 22:32:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <libft.h>

# ifndef SWAP_BUFFER_SIZE
#  define SWAP_BUFFER_SIZE 32
# endif

typedef unsigned long	t_size;
typedef int				(*t_cmpf)(void *, void *, t_size);

typedef struct s_pair
{
	void	*first;
	void	*second;	
}	t_pair;

typedef struct s_list
{
	t_pair			data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

t_list	*lst_new(void);
int		lst_init(t_list **empty_data);

int		lst_push_front(t_list *sentinel, void *data, t_size size);
int		lst_push_back(t_list *sentinel, void *data, t_size size);
void	lst_pop_front(t_list *sentinel);
void	lst_pop_back(t_list *sentinel);
void	lst_pop(t_list *element);

t_list	*lst_at(const t_list *sentinel, int index);
t_size	lst_size(const t_list *sentinel);

void	lst_merge(t_list *sentinel_a, t_list *sentinel_b);
void	lst_sort(t_list *sentinel, t_cmpf cmp_fun);

void	lst_clear(t_list *sentinel);
void	lst_destroy(t_list *sentinel);

#endif
