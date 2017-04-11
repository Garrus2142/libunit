#include <unistd.h>
#include <string.h>

void	ft_putstr(char const *s)
{
	if (s == NULL)
		return ;
	write(STDOUT_FILENO, s, strlen(s));
}
