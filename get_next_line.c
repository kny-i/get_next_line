#include "get_next_line.h"

static char	*creat_new_save(char *tmp_save)
{
	char	*str;
	size_t	i;

	i = 0;
	printf("creat_new_save:%s\n", tmp_save);
	while (tmp_save[i] && tmp_save[i] != '\n')
		i++;
	str = ft_substr(tmp_save, i + 1, ft_strlen(tmp_save));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	free(tmp_save);
	return (str);
}

static char	*line_trim(char *tmp_save)
{
	char	*str;
	size_t	i;

	i = 0;
	printf("line_trim:%s\n", tmp_save);
	while (tmp_save[i] && tmp_save[i] != '\n')
		i++;
	str = ft_substr(tmp_save, 0, i + 1);
	return (str);
}

static char	*read_fd(int fd, char *tmp_save)
{
	char	*buff;
	ssize_t	read_len;

	buff = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_len = 1;
	while (!ft_strchr(tmp_save, '\n') && read_len != 0)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_len] = '\0';
		printf("%s\n",buff);
		tmp_save = ft_strjoin(tmp_save, buff);
		printf("read_fd:%s\n", tmp_save);
	}
	free(buff);
	return (tmp_save);
}

char	*get_next_line(int fd)
{
	static char	*tmp_save;
	char		*next_line;

	if (fd < 0 != 0 || INT_MAX < BUFFER_SIZE)
		return (NULL);
	tmp_save = read_fd(fd, tmp_save);
	printf("get_next_line:%s\n", tmp_save);
	if (!tmp_save)
		return (NULL);
	next_line = line_trim(tmp_save);
	tmp_save = creat_new_save(tmp_save);
	return (next_line);
}
