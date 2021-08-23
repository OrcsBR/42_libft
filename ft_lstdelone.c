/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peduardo < peduardo@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 14:30:44 by peduardo          #+#    #+#             */
/*   Updated: 2021/08/22 15:30:35 by peduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst_el, void (*del)(void*))
{
	if (!lst_el || !del)
		return ;
	del(lst_el->content);
	free(lst_el); //why not lst_el->content? It says The memory of ’next’ must not be freed.
	lst_el = NULL; //why???
}
