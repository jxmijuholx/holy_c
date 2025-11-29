/** ft_memccpy.c - Jami Juhola **/
#include "libft.h"

void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    unsigned char *a;
	const unsigned char *b;
    unsigned    char c1;

    a = dst;
	b = src;
    c1 = (unsigned char)c;

    if(dst == NULL && src == NULL)
		return (NULL);

        while (n)
        {
        *a = *b;
        if(*a == c1)
            {
                return (a + 1 );
            }
        a++;
        b++;
        n--;
        }

        return (NULL);
}