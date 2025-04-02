/** ft_memcpy.c - Jami Juhola **/
#include "libft.h"

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *a;
	const unsigned char *b;

	a = dst;
	b = src;

	if(dst == NULL && src == NULL)
		return (NULL);
	while (n)
	{
	*a = *b;
	a++;
	b++;
	n--;															
	}

	return (dst);
}
