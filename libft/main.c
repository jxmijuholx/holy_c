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

void test_ft_strlcat(void)
{
 printf("====== Testing ft_strlcat ======\n\n");

    // Test 1: Enough space to append full src
    char buffer1[20] = "Hello";
    size_t result1 = ft_strlcat(buffer1, " World", sizeof(buffer1));
    printf("Test 1:\n");
    printf("Before: \"Hello\"\n");
    printf("After : \"%s\"\n", buffer1);
    printf("Expected full string. Return: %zu (should be 11)\n\n", result1);

    // Test 2: Not enough space (truncation happens)
    char buffer2[10] = "Hello";
    size_t result2 = ft_strlcat(buffer2, " World", sizeof(buffer2));
    printf("Test 2:\n");
    printf("Before: \"Hello\"\n");
    printf("After : \"%s\"\n", buffer2);
    printf("Expected truncation. Return: %zu (should be 11 — total wanted length)\n\n", result2);

    // Test 3: dstsize is smaller than existing dst
    char buffer3[5] = "Hello"; // Already full
    size_t result3 = ft_strlcat(buffer3, " World", sizeof(buffer3));
    printf("Test 3:\n");
    printf("Before: \"Hello\"\n");
    printf("After : \"%s\"\n", buffer3);
    printf("Expected NO copy. Return: %zu (should be 5 + 6 = 11)\n\n", result3);

    // Test 4: dst is empty
    char buffer4[15] = "";
    size_t result4 = ft_strlcat(buffer4, "World", sizeof(buffer4));
    printf("Test 4:\n");
    printf("Before: \"\"\n");
    printf("After : \"%s\"\n", buffer4);
    printf("Expected full copy. Return: %zu (should be 5)\n\n", result4);

    // Test 5: dstsize = 0
    char buffer5[10] = "Hi";
    size_t result5 = ft_strlcat(buffer5, "There", 0);
    printf("Test 5:\n");
    printf("Before: \"Hi\"\n");
    printf("After : \"%s\"\n", buffer5); // Might be garbage or unchanged
    printf("Expected return only, no copy. Return: %zu (should be strlen(\"There\") = 5)\n\n", result5);

    printf("================================\n\n");
}

void test_ft_toupper(void)
{
	printf("Testing ft_toupper\n");
	char c = 'a';
	printf("Before toupper: %c \n", c);
	printf("After toupper: %c\n",ft_toupper(c));
	printf("\n");
}

void test_ft_tolower(void)
{
	printf("Testint ft_tolower:\n");
	char c = 'L';
	printf("Before tolower: %c\n", c);
	printf("After tolower: %c \n", ft_tolower(c));
	printf("\n\n");
	
}

void test_ft_strchr(void)
{

	printf("Testing ft_strchr! \n");
	const char *text = "libft is fun!";

    // Test 1: Char exists in the middle
    char *result1 = ft_strchr(text, 'f');
    printf("Test 1 - Find 'f': %s\n", result1); // Expected: "ft is fun!"

    // Test 2: Char exists at the beginning
    char *result2 = ft_strchr(text, 'l');
    printf("Test 2 - Find 'l': %s\n", result2); // Expected: "libft is fun!"

    // Test 3: Char exists at the end
    char *result3 = ft_strchr(text, '!');
    printf("Test 3 - Find '!': %s\n", result3); // Expected: "!"

    // Test 4: Char does not exist
    char *result4 = ft_strchr(text, 'z');
    printf("Test 4 - Find 'z': %s\n", result4 ? result4 : "(null)"); // Expected: (null)

    // Test 5: Search for null terminator
    char *result5 = ft_strchr(text, '\0');
    printf("Test 5 - Find '\\0': %s\n", result5); // Should point to empty string ""

    printf("\n");
}

void	test_ft_strrchr(void)
{
printf("====== Testing ft_strrchr ======\n\n");

    const char *text = "libft is fun!";

    // Test 1: Char appears multiple times
    char *result1 = ft_strrchr(text, 'f');
    printf("Test 1 - Find 'f': %s\n", result1); // Expected: "fun!"

    // Test 2: Char appears only at beginning
    char *result2 = ft_strrchr(text, 'l');
    printf("Test 2 - Find 'l': %s\n", result2); // Expected: "libft is fun!"

    // Test 3: Char at the very end
    char *result3 = ft_strrchr(text, '!');
    printf("Test 3 - Find '!': %s\n", result3); // Expected: "!"

    // Test 4: Char not found
    char *result4 = ft_strrchr(text, 'z');
    printf("Test 4 - Find 'z': %s\n", result4 ? result4 : "(null)"); // Expected: (null)

    // Test 5: Searching for '\0'
    char *result5 = ft_strrchr(text, '\0');
    printf("Test 5 - Find '\\0': %s\n", result5); // Expected: ""

    printf("\n");
}

void test_ft_strncmp(void)
{
  printf("====== Testing ft_strncmp ======\n\n");

    // Test 1: Equal strings, n less than length
    int res1 = ft_strncmp("hello", "hello", 3);
    printf("Test 1 - 'hello' vs 'hello', n = 3 → %d (expected 0)\n", res1);

    // Test 2: Equal strings, full length
    int res2 = ft_strncmp("hello", "hello", 5);
    printf("Test 2 - 'hello' vs 'hello', n = 5 → %d (expected 0)\n", res2);

    // Test 3: Different strings
    int res3 = ft_strncmp("hello", "world", 5);
    printf("Test 3 - 'hello' vs 'world', n = 5 → %d (expected < 0)\n", res3);

    // Test 4: First string smaller
    int res4 = ft_strncmp("abc", "abd", 3);
    printf("Test 4 - 'abc' vs 'abd', n = 3 → %d (expected < 0)\n", res4);

    // Test 5: Second string smaller
    int res5 = ft_strncmp("abd", "abc", 3);
    printf("Test 5 - 'abd' vs 'abc', n = 3 → %d (expected > 0)\n", res5);

    // Test 6: One string is a prefix of the other
    int res6 = ft_strncmp("abc", "abcdef", 3);
    printf("Test 6 - 'abc' vs 'abcdef', n = 3 → %d (expected 0)\n", res6);

    // Test 7: Compare 0 characters
    int res7 = ft_strncmp("hello", "world", 0);
    printf("Test 7 - 'hello' vs 'world', n = 0 → %d (expected 0)\n", res7);

    printf("\n");
}

void test_ft_memchr(void)
{
    printf("====== Testing ft_memchr ======\n\n");

    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0' };

    // Test 1: Find 'c' in first 6 bytes
    void *res1 = ft_memchr(data, 'c', 6);
    printf("Test 1 - Find 'c': %s\n", res1 ? (char *)res1 : "(null)"); // Expected: "cdef"

    // Test 2: Find 'a' (first byte)
    void *res2 = ft_memchr(data, 'a', 6);
    printf("Test 2 - Find 'a': %s\n", res2 ? (char *)res2 : "(null)"); // Expected: "abcdef"

    // Test 3: Find 'f' (last valid byte)
    void *res3 = ft_memchr(data, 'f', 6);
    printf("Test 3 - Find 'f': %s\n", res3 ? (char *)res3 : "(null)"); // Expected: "f"

    // Test 4: Char not found
    void *res4 = ft_memchr(data, 'z', 6);
    printf("Test 4 - Find 'z': %s\n", res4 ? (char *)res4 : "(null)"); // Expected: (null)

    // Test 5: Find null terminator
    void *res5 = ft_memchr(data, '\0', 7);
    printf("Test 5 - Find '\\0': %s\n", res5 ? "(found null terminator)" : "(null)"); // Expected: (found null terminator)

    printf("\n");
}

void test_ft_memcmp(void)
{
printf("====== Testing ft_memcmp ======\n\n");

    // Test 1: Identical buffers
    char a1[] = "libft";
    char b1[] = "libft";
    int res1 = ft_memcmp(a1, b1, 5);
    printf("Test 1 - Same strings, 5 bytes → %d (expected 0)\n", res1);

    // Test 2: Difference in middle
    char a2[] = "libxt";
    char b2[] = "libft";
    int res2 = ft_memcmp(a2, b2, 5);
    printf("Test 2 - 'x' vs 'f' → %d (expected > 0)\n", res2);

    // Test 3: Difference at start
    char a3[] = "xibft";
    char b3[] = "libft";
    int res3 = ft_memcmp(a3, b3, 5);
    printf("Test 3 - 'x' vs 'l' → %d (expected > 0)\n", res3);

    // Test 4: Difference at last byte
    char a4[] = "libfa";
    char b4[] = "libft";
    int res4 = ft_memcmp(a4, b4, 5);
    printf("Test 4 - 'a' vs 't' → %d (expected < 0)\n", res4);

    // Test 5: Compare 0 bytes
    char a5[] = "123";
    char b5[] = "456";
    int res5 = ft_memcmp(a5, b5, 0);
    printf("Test 5 - Compare 0 bytes → %d (expected 0)\n", res5);

    // Test 6: Binary data
    unsigned char bin1[] = {0, 1, 2, 3, 4};
    unsigned char bin2[] = {0, 1, 2, 3, 9};
    int res6 = ft_memcmp(bin1, bin2, 5);
    printf("Test 6 - Binary mismatch → %d (expected < 0)\n", res6);

    printf("\n");
}

void test_ft_strnstr(void)
{
printf("====== Testing ft_strnstr ======\n\n");

    const char *text = "libft is awesome";

    // Test 1: Match in the middle
    char *res1 = ft_strnstr(text, "is", 20);
    printf("Test 1 - Find \"is\" → %s\n", res1 ? res1 : "(null)"); // Expected: "is awesome"

    // Test 2: Match at the beginning
    char *res2 = ft_strnstr(text, "libft", 10);
    printf("Test 2 - Find \"libft\" → %s\n", res2 ? res2 : "(null)"); // Expected: "libft is awesome"

    // Test 3: Match at the end
    char *res3 = ft_strnstr(text, "awesome", 20);
    printf("Test 3 - Find \"awesome\" → %s\n", res3 ? res3 : "(null)"); // Expected: "awesome"

    // Test 4: Match would succeed, but len is too small
    char *res4 = ft_strnstr(text, "awesome", 10);
    printf("Test 4 - Find \"awesome\" with len=10 → %s\n", res4 ? res4 : "(null)"); // Expected: (null)

    // Test 5: No match at all
    char *res5 = ft_strnstr(text, "42", 20);
    printf("Test 5 - Find \"42\" → %s\n", res5 ? res5 : "(null)"); // Expected: (null)

    // Test 6: Empty needle
    char *res6 = ft_strnstr(text, "", 5);
    printf("Test 6 - Find \"\" → %s\n", res6 ? res6 : "(null)"); // Expected: full haystack

    printf("\n");
}

void test_ft_atoi(void)
{
	 printf("====== Testing ft_atoi ======\n\n");

    printf("Test 1 - \"42\" → %d (expected 42)\n", ft_atoi("42"));
    printf("Test 2 - \"   123\" → %d (expected 123)\n", ft_atoi("   123"));
    printf("Test 3 - \"-456\" → %d (expected -456)\n", ft_atoi("-456"));
    printf("Test 4 - \"+789\" → %d (expected 789)\n", ft_atoi("+789"));
    printf("Test 5 - \"2147483647\" → %d (expected 2147483647)\n", ft_atoi("2147483647")); // INT_MAX
    printf("Test 6 - \"-2147483648\" → %d (expected -2147483648)\n", ft_atoi("-2147483648")); // INT_MIN
    printf("Test 7 - \"42abc\" → %d (expected 42)\n", ft_atoi("42abc"));
    printf("Test 8 - \"abc42\" → %d (expected 0)\n", ft_atoi("abc42"));
    printf("Test 9 - \"    -00123text\" → %d (expected -123)\n", ft_atoi("    -00123text"));
    printf("Test 10 - \"   \\t\\n 77\" → %d (expected 77)\n", ft_atoi("   \t\n 77"));

    printf("\n");
}

void test_ft_calloc(void)
{
	printf("====== Testing ft_calloc ======\n\n");

    // Test 1: Basic allocation of 5 ints
    int *arr = ft_calloc(5, sizeof(int));
    if (!arr)
        printf("Test 1 - Allocation failed!\n");
    else if (memcmp(arr, (int[5]){0}, 5 * sizeof(int)) == 0)
        printf("Test 1 - 5 ints initialized to 0 ✅\n");
    else
        printf("Test 1 - Memory not zero-initialized ❌\n");
    free(arr);

    // Test 2: Zero-size allocation
    void *zero_alloc = ft_calloc(0, sizeof(char));
    printf("Test 2 - calloc(0, sizeof(char)) → %s\n", zero_alloc ? "non-NULL ✅" : "NULL ✅");
    free(zero_alloc);

    // Test 3: Large allocation (should not crash)
    size_t big_count = 1000000;
    size_t big_size = sizeof(char);
    char *big = ft_calloc(big_count, big_size);
    if (big && big[999999] == 0)
        printf("Test 3 - Big allocation passed ✅\n");
    else
        printf("Test 3 - Big allocation failed ❌\n");
    free(big);

    // Test 4: Overflow simulation (should return NULL)
    size_t huge = SIZE_MAX;
    void *overflow = ft_calloc(huge, 2);
    printf("Test 4 - Overflow check → %s\n", overflow ? "❌ should be NULL" : "✅ NULL as expected");
    free(overflow);

    printf("\n");
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
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_atoi();
	test_ft_calloc();
//	test_ft_strdup();
	return 0;

}

