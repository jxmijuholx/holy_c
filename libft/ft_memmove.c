/** ft_memmove.c - Jami Juhola **/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	const unsigned char *s;
	
	d = (unsigned char*)dst;
	s = (const unsigned char *)src;
	if (d == s || len == 0)
		return (dst);

	if (d < s)
	{
		while(len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		while(len--)	
		{
			d[len] = s[len];
		}	
	}

	
	return (dst);
}
