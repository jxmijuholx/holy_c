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

void test_ft_strlen(void)
{
	printf("Testing ft_strlen: \n");
	
	char *test = "Testi lause";
	printf("Test string is called: %s and the length is: %zd (expected 11)\n", test, ft_strlen(test));
	printf("\n");
}

void test_ft_memset(void)
{
	printf("Testing ft_memset here: \n");
	
	char b[20];
	printf("String before memset: %s\n", b);
	ft_memset(b, 'J', 10);
	printf("String after memset: %s\n", b);
	printf("\n\n");
}

void test_ft_bzero(void)
{
    char buffer[10] = "123456789";

    printf("Testing ft_bzero:\n");
    printf("Before: ");
    for (int i = 0; i < 10; i++)
        printf("%c ", buffer[i]);
    printf("\n");

    ft_bzero(buffer, 5);

    printf("After : ");
    for (int i = 0; i < 10; i++)
    {
        if (buffer[i] == 0)
            printf("0 ");
        else
            printf("%c ", buffer[i]);
    }
    printf("\n\n");
}

void test_ft_memcpy(void)
{
 printf("Testing ft_memcpy:\n");

    char src[20] = "Hello, world!";
    char dst[20];

    ft_bzero(dst, sizeof(dst));

    ft_memcpy(dst, src, 13);

    printf("Source:      \"%s\"\n", src);
    printf("Destination: \"%s\"\n", dst);
    printf("Source successfully copied to destination!\n");
    char test[10] = "abcdef";
    ft_memcpy(test, "XXXXX", 0);
    printf("Zero-byte copy (no change expected): %s\n", test);

    printf("\n");
}

void test_ft_memmove(void)
{
	printf("Testing ft_memmove:\n");

    char src1[30] = "abcdef123456";
    char src2[30] = "abcdef123456";

    ft_memmove(src1 + 2, src1, 10);
    memmove(src2 + 2, src2, 10);

    printf("Custom  : %s\n", src1);
    printf("Standard: %s\n", src2);

    if (memcmp(src1, src2, 30) == 0)
        printf("✅ ft_memmove passed!\n\n");
    else
        printf("❌ ft_memmove failed!\n\n");
}

void test_ft_strlcpy(void)
{
printf("Testing ft_strlcpy:\n\n");

    char src[] = "Hello, Libft!";
    char dst[20];
    char dst_small[5];

    printf("Source string: \"%s\"\n", src);
    printf("Source length: %zu\n\n", strlen(src));

    // Test 1: Destination buffer is big enough
    printf("Test 1: Copying with large buffer (dstsize = 20)\n");
    size_t ret1 = ft_strlcpy(dst, src, sizeof(dst));
    printf("Resulting dst: \"%s\"\n", dst);
    printf("Return value (length of src): %zu\n", ret1);
    printf("What happened: Full string copied, including null terminator.\n\n");

    // Test 2: Destination buffer is small (truncation)
    printf("Test 2: Copying with small buffer (dstsize = 5)\n");
    size_t ret2 = ft_strlcpy(dst_small, src, sizeof(dst_small));
    printf("Resulting dst: \"%s\"\n", dst_small);
    printf("Return value (length of src): %zu\n", ret2);
    printf("What happened: Only first 4 characters were copied. Last byte reserved for '\\0'.\n\n");

    // Test 3: Destination size is 0
    printf("Test 3: Copying with dstsize = 0 (nothing should be copied)\n");
    size_t ret3 = ft_strlcpy(dst, src, 0);
    printf("Return value (length of src): %zu\n", ret3);
    printf("What happened: No bytes copied. Function just returned the length of the source string.\n\n");

    printf("\n\n");
}


int main(void)
{
	printf("====== LIBFT TESTS ======\n\n");

	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	return 0;
}

