/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:03 by ilaasri           #+#    #+#             */
/*   Updated: 2024/10/26 19:54:04 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**all_dir_sorted(char *dir_name)
{
	DIR				*dir;
	char			**ret;
	int				retlen;
	struct dirent	*po;
	int				i;

	i = 0;
	retlen = get_len_of_dir(dir_name);
	if (retlen <= 0)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (retlen + 1));
	if (!ret)
		panic("malloc failed!\n");
	dir = opendir(dir_name);
	while (i < retlen)
	{
		po = readdir(dir);
		ret[i] = ft_strdup(po->d_name);
		if (!ret[i])
			panic("malloc failed!\n");
		i++;
	}
	ret[i] = NULL;
	closedir(dir);
	just_sort(ret);
	return (ret);
}

int	skip_dot(char *s, int i)
{
	while (s[i] && ft_isalpha(s[i]) == 0)
		i++;
	return (i);
}

int	need_a_sort(char *a, char *b)
{
	int	i;
	int	j;

	i = skip_dot(a, 0);
	j = skip_dot(b, 0);
	while (a[i])
	{
		if (ft_tolower(a[i]) > ft_tolower(b[j]))
			return (-1);
		if (ft_tolower(a[i]) < ft_tolower(b[j]))
			return (0);
		i++;
	}
	return (0);
}

int	is_it_sorted(char **dir)
{
	int	i;

	i = 0;
	while (dir[i])
	{
		if (dir[i + 1] == NULL)
			break ;
		if (need_a_sort(dir[i], dir[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

void	just_sort(char **dir)
{
	int	i;

	i = 0;
	while (is_it_sorted(dir))
	{
		while (dir[i])
		{
			if (dir[i + 1] == NULL)
				break ;
			if (need_a_sort(dir[i], dir[i + 1]))
				ft_swap_str(&dir[i], &dir[i + 1]);
			i++;
		}
		i = 0;
	}
}
