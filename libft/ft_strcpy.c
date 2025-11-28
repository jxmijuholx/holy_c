/** ft_strcpy.c - Jami Juhola **/
#include "libft.h"

char *ft_strcpy(char * dst, const char * src){

    size_t  i;

    i = 0;
    while(src[i] != '\0' && i < ft_strlen(src))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}