/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:18:19 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 19:23:14 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <garbage.h>

static int	garbage_collector_failure(t_list **gb,
				t_list **sv,
				void *data,
				t_destructor destructor)
{
	lst_destroy(*gb);
	lst_destroy(*sv);
	*gb = NULL;
	*sv = NULL;
	(*destructor)(data);
	return (-1);
}

static void	destroy_garbage(t_list *garbage, t_list *saved)
{
	lst_destroy(*garbage);
	*garbage = NULL;
	if ((*saved)->next == *saved)
	{
		free(*saved);
		*saved = NULL;
	}
}

int	garbage_collector(void *data, t_destructor destructor, int action)
{
	static t_list	*garbage = NULL;
	static t_list	*saved = NULL;
	t_pair			pair;

	pair = (t_pair){data, destructor};
	if (!garbage && !lst_init(&garbage))
		return (garbage_collector_failure(&garbage, &saved, data, destructor));
	if (!saved && !lst_init(&saved))
		return (garbage_collector_failure(&garbage, &saved, data, destructor));
	if (!action && data && destructor
		&& lst_push_front(garbage, &pair, sizeof(t_pair)))
		return (garbage_collector_failure(&garbage, &saved, data, destructor));
	if (action == 1)
		lst_merge(saved, garbage);
	else if (action == 2)
		lst_merge(garbage, saved);
	else if (action == 3)
		destroy_garbage(&garbage, &saved);
	return (0);
}
