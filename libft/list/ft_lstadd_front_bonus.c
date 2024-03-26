/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:01:47 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:25:06 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//create a singly linked list entry at the front
void	ft_lstadd_front(t_list **lst, t_list *newl)
{
	if (!lst || !newl)
		return ;
	newl->next = *lst;
	*lst = newl;
}
