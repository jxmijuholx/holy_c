#include <stdio.h>
#include "libft.h"

void test_ft_isalpha(void)
{
    printf("Testing ft_isalpha:\n");
    printf("ft_isalpha('A') = %d (expected 1)\n", ft_isalpha('A'));
    printf("ft_isalpha('z') = %d (expected 1)\n", ft_isalpha('z'));
    printf("ft_isalpha('1') = %d (expected 0)\n", ft_isalpha('1'));
    printf("\n");
}

void test_ft_isdigit(void)
{
    printf("Testing ft_isdigit:\n");

    printf("ft_isdigit('0') = %d (expected 1)\n", ft_isdigit('0'));
    printf("ft_isdigit('5') = %d (expected 1)\n", ft_isdigit('5'));
    printf("ft_isdigit('9') = %d (expected 1)\n", ft_isdigit('9'));
    printf("ft_isdigit('a') = %d (expected 0)\n", ft_isdigit('a'));
    printf("ft_isdigit(' ') = %d (expected 0)\n", ft_isdigit(' ') );
    printf("ft_isdigit('\\n') = %d (expected 0)\n", ft_isdigit('\n'));
    printf("ft_isdigit(48) = %d (expected 1)\n", ft_isdigit(48));   // ASCII '0'
    printf("ft_isdigit(57) = %d (expected 1)\n", ft_isdigit(57));   // ASCII '9'
    printf("ft_isdigit(47) = %d (expected 0)\n", ft_isdigit(47));   // ASCII before '0'
    printf("ft_isdigit(58) = %d (expected 0)\n", ft_isdigit(58));   // ASCII after '9'

    printf("\n");
}

void test_ft_isalnum(void)
{
	printf("Testing ft_isalnum:\n");
	printf("ft_isalnum('A') = %d (expected 1)\n", ft_isalnum('A'));
	printf("ft_isalnum('1') = %d (expected(1)\n", ft_isalnum('1'));
	printf("ft_isalnum(48) = %d expected(1)\n", ft_isalnum(48));
	printf("ft_isalnum(47) = %d expected(0)\n", ft_isalnum(47));
	printf("\n");
}

void test_ft_isascii(void)
{
	printf("Testing ft_isascii:\n");
	printf("ft_isascii('@') = %d (expected 1)\n", ft_isascii('@'));
	printf("ft_isascii(216) = %d (expected 0)\n", ft_isascii(216));
	printf("\n");

}

void test_ft_isprint(void)
{
 printf("Testing ft_isprint:\n");

    printf("ft_isprint('A') = %d (expected 1)\n", ft_isprint('A'));
    printf("ft_isprint('~') = %d (expected 1)\n", ft_isprint('~'));
    printf("ft_isprint(' ') = %d (expected 1)\n", ft_isprint(' '));  // Will fail with current logic
    printf("ft_isprint('\\n') = %d (expected 0)\n", ft_isprint('\n'));
    printf("ft_isprint(31) = %d (expected 0)\n", ft_isprint(31));    // Just before space
    printf("ft_isprint(127) = %d (expected 0)\n", ft_isprint(127));  // DEL char

    printf("\n");;
}

int main(void)
{
	printf("====== LIBFT TESTS ======\n\n");

	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();

	return 0;
}

