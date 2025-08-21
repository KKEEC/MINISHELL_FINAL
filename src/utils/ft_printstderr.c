#include <unistd.h>

void	ft_printstderr(const char *str)
{
	size_t	len;

	if (!str)
		return ;
	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
}
