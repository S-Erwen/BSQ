/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 21:24:35 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 19:32:36 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"
#define BUFF_SIZE 4096

char		*ft_read_map(int fd, long long size)
{
	int		ret;
	int		i;
	char	buf[1];
	char	*result;

	i = 0;
	result = (char *)malloc((size + 1) * sizeof(char));
	while ((ret = read(fd, buf, 1)) > 0)
		result[i++] = buf[0];
	result[i] = '\0';
	return (result);
}

long long	ft_get_file_size(int fd)
{
	char	buff[1];
	int		ret;
	int		len;

	len = 0;
	while ((ret = read(fd, buff, 1)))
		len++;
	return (len);
}

char		*ft_stdin_to_file(void)
{
	char	*str;
	char	*tmp_str;
	char	buff[BUFF_SIZE];
	int		ret;
	int		size;

	size = 0;
	if (!(tmp_str = malloc(sizeof(char) * 1)))
		exit(EXIT_FAILURE);
	tmp_str[0] = '\0';
	while ((ret = read(0, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		size += ret;
		free(str);
		if (!(str = malloc(sizeof(char) * (size + 1))))
			exit(EXIT_FAILURE);
		ft_strcpy_double(tmp_str, buff, str);
		free(tmp_str);
		if (!(tmp_str = malloc(sizeof(char) * (size + 1))))
			exit(EXIT_FAILURE);
		ft_strcpy(str, tmp_str);
	}
	free(tmp_str);
	return (str);
}

char		*ft_file_to_str(char *file, int fd)
{
	long long	file_size;
	char		*str;

	if (fd != 0)
	{
		if (!(fd = open(file, O_RDONLY)))
			exit(EXIT_FAILURE);
		file_size = ft_get_file_size(fd);
		if (close(fd) == -1)
			exit(EXIT_FAILURE);
		if (!(fd = open(file, O_RDONLY)))
			exit(EXIT_FAILURE);
		str = ft_read_map(fd, file_size);
		if (close(fd) == -1)
			exit(EXIT_FAILURE);
	}
	else
		str = ft_stdin_to_file();
	return (str);
}
