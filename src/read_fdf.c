/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 04:00:04 by wyu               #+#    #+#             */
/*   Updated: 2022/08/05 15:01:45 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static
t_list	*lst_reverse(t_list *lst)
{
	t_list	*next;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	next = NULL;
	while (lst)
	{
		tmp = lst->next;
		lst->next = next;
		next = lst;
		lst = tmp;
	}
	return (next);
}

static
void	stack_vector(t_list **vectors, char **parse_line)
{
	int		i;
	char	*content;

	i = 0;
	while (parse_line[i])
	{
		content = (void *)ft_strdup(parse_line[i]);
		ft_lstadd_front(vectors, ft_lstnew((void *)content));
		i++;
	}
}

static
void	del_vectors(void *content)
{
	free(content);
}

int	read_fdf(int fd, t_map *map)
{
	char	**parse_line;
	t_list	*vectors;
	int		ret;

	vectors = NULL;
	while (1)
	{
		parse_line = get_parseline(fd);
		if (!parse_line)
			break ;
		if (map->width && widthcmp(map->width, parse_line))
			return (0);
		else if (!map->width)
			map->width = init_width(parse_line);
		stack_vector(&vectors, parse_line);
		clear_parseline(parse_line);
		map->height++;
	}
	vectors = lst_reverse(vectors);
	ret = get_map(map, vectors);
	ft_lstclear(&vectors, del_vectors);
	return (ret);
}
