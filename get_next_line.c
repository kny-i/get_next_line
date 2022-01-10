#include "get_next_line.h"
char 	read_fd(fd, tmp_save)
{
	char 	*buff;
	ssize_t	read_len;

	buff = char
}

char	*get_next_line(int fd)
{
	static char *tmp_save;
	char *next_line;

	if (fd < 0 || BUFFER SIZE <= 0) || INT_MAX < BUFFER_SIZE)
		return(NULL);
	tmp_save = read_fd(fd, tmp_save);
	if (!tmp_save)
		return(NULL);
	next_line = line_trim(tmp_save);
	tmp_save = creat_new_save(tmp_save);
	return(next_line);
}
int	main ()
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (s!)
		{
			printf("\nEOF or ERROR\n");
			break ;
		}
		printf("line[%d]%s: %s",s)
		i++;
		free(s)
	}
	close(fd);
	printf("\n");
	system("leaks a.out");
}
