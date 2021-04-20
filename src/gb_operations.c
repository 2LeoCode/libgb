/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:24:12 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 19:28:20 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <garbage.h>

int	gb_add(void *data, t_destructor destructor)
{
	return (garbage_collector(data, destructor, 0));
}

int	gb_save(void)
{
	return (garbage_collector(NULL, NULL, 1));
}

int	gb_load(void)
{
	return (garbage_collector(NULL, NULL, 2));
}

void	gb_clear(void)
{
	garbage_collector(NULL, NULL, 3);
}
