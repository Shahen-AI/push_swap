/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:48:23 by htumanya          #+#    #+#             */
/*   Updated: 2021/02/01 19:48:49 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *obj;

	if (!(obj = malloc(sizeof(t_list))))
		return (NULL);
	obj->content = content;
	obj->next = NULL;
	return (obj);
}
