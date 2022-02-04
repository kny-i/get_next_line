#include "get_next_line.h"

static char	*creat_new_save(char *tmp_save)
{
	char	*str;
	size_t	i;

	i = 0;
	while (tmp_save[i] != '\0' && tmp_save[i] != '\n')
		i++;
	if (tmp_save[i] == '\0')
	{
		free (tmp_save);
		return (NULL);
	}
	str = ft_substr(tmp_save, i + 1, ft_strlen(tmp_save));
	free(tmp_save);
	return (str);
}

static char	*line_trim(char *tmp_save)
{
	char	*str;
	size_t	i;

	if (tmp_save[0] == '\0')
		return (NULL);
	i = 0;
	while (tmp_save[i] != '\0' && tmp_save[i] != '\n')
		i++;
	str = ft_substr(tmp_save, 0, i + 1);
	return (str);
}

static char	*read_fd(int fd, char *tmp_save)
{
	char	*buff;
	ssize_t	read_len;

	buff = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (buff == NULL)
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
		tmp_save = ft_strjoin(tmp_save, buff);
	}
	free(buff);
	return (tmp_save);
}

char	*get_next_line(int fd)
{
	static char	*tmp_save;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || INT_MAX < BUFFER_SIZE)
		return (NULL);
	tmp_save = read_fd(fd, tmp_save);
	if (!tmp_save)
		return (NULL);
	next_line = line_trim(tmp_save);
	tmp_save = creat_new_save(tmp_save);
	return (next_line);
}
