/** the header file for my glorious C library - Jami Juhola **/

#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
void *ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
size_t  ft_strlcat(char * restrict dst, const char * restrict src, size_t dst_size);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
int ft_atoi(const char *str);
void *ft_calloc(size_t count, size_t size);
char *ft_strdup(const char *s1);
char *ft_substr(char const *s, unsigned int start,size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strcpy(char * dst, const char * src);
char *ft_strncpy(char * dst, const char * src, size_t len);
char *ft_strcat(char *restrict s1, const char *restrict s2);
char *ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
char *ft_strstr(const char *haystack, const char *needle);
void *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void * ft_memalloc(size_t size);

/*
TODO:

pt 2:
ft_memalloc TODO

ft_memdel

ft_strnew

ft_strdel

ft_strclr

ft_striter

ft_striteri

ft_strmap

ft_strmapi

ft_strequ

ft_strnequ

ft_strtrim

ft_strsplit

ft_itoa

printing functions:

ft_putchar

ft_putstr

ft_putendl

ft_putnbr

ft_putchar_fd

ft_putstr_fd

ft_putendl_fd

ft_putnbr_fd

BONUS:
typedef t_list (struct)

ft_lstnew

ft_lstdelone

ft_lstdel

ft_lstadd

ft_lstiter

ft_lstmap
*/

#endif
