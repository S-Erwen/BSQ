/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 14:45:10 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 21:59:24 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		min(int a, int b, int c)
{
	int m;

	if (a > 0 && b > 0 && c > 0)
	{
		m = a;
		if (m > b)
			m = b;
		if (m > c)
			m = c;
		return (m);
	}
	return (0);
}

int		solve(int **map, int row, int col)
{
	int **tmp;
	int result;
	int i;
	int j;

	tmp = map;
	result = 1;
	i = 2;
	while (i <= row)
	{
		j = 1;
		while (j < col)
		{
			if (map[i][j] != 0)
				tmp[i][j] = 1 + min(tmp[i][j - 1],
						tmp[i - 1][j], tmp[i - 1][j - 1]);
			if (tmp[i][j] > result)
				result = tmp[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

int		get_col(int **map, int result, int row, int col)
{
	int i;
	int j;

	i = 1;
	while (i <= row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == result)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int		get_row(int **map, int result, int row, int col)
{
	int i;
	int j;

	i = 1;
	while (i <= row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == result)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}
