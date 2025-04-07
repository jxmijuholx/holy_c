#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int	len;
	
	len = ft_strlen(s1) + 1;	
	cpy = (char *)malloc(len);
	if(!cpy)
		return (NULL);
	ft_memcpy(cpy, s1, len);
	
	return (cpy);
}	
