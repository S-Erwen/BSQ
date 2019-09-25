/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 23:28:59 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 16:44:53 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		give_col(char **matrix)
{
	int i;

	i = 1;
	while (matrix[i] != 0)
		i++;
	return (i - 1);
}

int		give_row(char **matrix)
{
	int j;

	j = 0;
	while (matrix[1][j])
		j++;
	return (j);
}

void	ft_strcpy(char *src, char *dest)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_strcpy_double(char *src_start, char *src_end, char *dest)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (src_start[j])
		dest[i++] = src_start[j++];
	j = 0;
	while (src_end[j])
		dest[i++] = src_end[j++];
	dest[i] = '\0';
}
