/*
#include "get_next_line.h"

int	main ()
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	printf("%d\n",fd);
	while (1)
	{
		i ++;
		line = get_next_line(fd);
		if (!line)
		{
			printf("\nEOF or ERROR\n");
			break ;
		}
		printf("line[%d]: %s", i , line);
		free(line);
	}
	close(fd);
	printf("\n");
*/
/*	system("leaks a.out");*//*

}
*/
