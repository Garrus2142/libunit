#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main ()
{
	char 	*line = NULL;
	size_t	linecap = 0;
	
	setbuf(stdout, NULL);
	while (getline(&line, &linecap, stdin) > 0)
	{
		if (strcmp(line, "exit\n") == 0)
			return (0);
		printf("in->out>%s", line);
	}
	free(line);
	return (0);
}
