/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 22:07:50 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 16:14:56 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		is_backline(char c)
{
	if (c == '\n')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int		count(char *str)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if ((is_backline(str[i + 1]))
				&& (!(is_backline(str[i]))))
			size++;
		i++;
	}
	return (size);
}

void	write_res(char *str, char *src)
{
	int i;

	i = 0;
	while (!(is_backline(src[i])))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
}

void	malloc_res(char **res, char *str)
{
	int i;
	int j;
	int ind;

	i = 0;
	ind = 0;
	while (str[i] != '\0')
	{
		if (is_backline(str[i]))
			i++;
		else
		{
			j = 0;
			while (!(is_backline(str[i + j])))
				j++;
			res[ind] = (char *)malloc((j + 1) * sizeof(char));
			write_res(res[ind], str + i);
			i = i + j;
			ind++;
		}
	}
}

char	**ft_split_backline(char *str)
{
	char **res;

	if (!(res = (char **)malloc((count(str) + 1) * sizeof(char *))))
		return (0);
	res[count(str)] = 0;
	malloc_res(res, str);
	return (res);
}
