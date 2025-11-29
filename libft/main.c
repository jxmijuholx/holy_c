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

void test_ft_strdup(void)
{
printf("====== Testing ft_strdup ======\n\n");

    // Test 1: Basic string
    char *orig1 = "libft";
    char *dup1 = ft_strdup(orig1);
    if (dup1 && strcmp(dup1, orig1) == 0)
        printf("Test 1 - Basic copy: ✅ \"%s\"\n", dup1);
    else
        printf("Test 1 - Basic copy: ❌\n");
    free(dup1);

    // Test 2: Empty string
    char *dup2 = ft_strdup("");
    if (dup2 && strcmp(dup2, "") == 0)
        printf("Test 2 - Empty string: ✅ \"%s\"\n", dup2);
    else
        printf("Test 2 - Empty string: ❌\n");
    free(dup2);

    // Test 3: Long string
    char *orig3 = "The quick brown fox jumps over the lazy dog";
    char *dup3 = ft_strdup(orig3);
    if (dup3 && strcmp(dup3, orig3) == 0)
        printf("Test 3 - Long string: ✅ \"%s\"\n", dup3);
    else
        printf("Test 3 - Long string: ❌\n");
    free(dup3);

    // Test 4: Memory address check
    char *orig4 = "memory";
    char *dup4 = ft_strdup(orig4);
    if (dup4 && dup4 != orig4)
        printf("Test 4 - Separate memory block: ✅ (ptr = %p, orig = %p)\n", (void *)dup4, (void *)orig4);
    else
        printf("Test 4 - Separate memory block: ❌\n");
    free(dup4);

    printf("\n");
}

void test_ft_substr(void)
{

 printf("====== Testing ft_substr ======\n\n");

    // Test 1: Normal substring
    char *str1 = "libft is life";
    char *sub1 = ft_substr(str1, 6, 2);
    printf("Test 1 - substr(\"%s\", 6, 2) → \"%s\" (expected \"is\")\n", str1, sub1);
    free(sub1);

    // Test 2: Start at 0
    char *sub2 = ft_substr(str1, 0, 5);
    printf("Test 2 - substr(\"%s\", 0, 5) → \"%s\" (expected \"libft\")\n", str1, sub2);
    free(sub2);

    // Test 3: Length longer than remaining
    char *sub3 = ft_substr(str1, 6, 50);
    printf("Test 3 - substr(\"%s\", 6, 50) → \"%s\" (expected \"is life\")\n", str1, sub3);
    free(sub3);

    // Test 4: Start beyond string length
    char *sub4 = ft_substr(str1, 100, 10);
    printf("Test 4 - substr(\"%s\", 100, 10) → \"%s\" (expected \"\")\n", str1, sub4);
    free(sub4);

    // Test 5: NULL string
    char *sub5 = ft_substr(NULL, 0, 5);
    printf("Test 5 - substr(NULL, 0, 5) → %s (expected NULL)\n", sub5 ? sub5 : "NULL");

    printf("\n");
}

void test_ft_strjoin(void)
{
 printf("====== Testing ft_strjoin ======\n\n");

    char *res1 = ft_strjoin("libft", "_rocks");
    printf("Test 1 - \"libft\" + \"_rocks\" → %s\n", res1);
    free(res1);

    char *res2 = ft_strjoin("", "emptyleft");
    printf("Test 2 - \"\" + \"emptyleft\" → %s\n", res2);
    free(res2);

    char *res3 = ft_strjoin("emptyright", "");
    printf("Test 3 - \"emptyright\" + \"\" → %s\n", res3);
    free(res3);

    char *res4 = ft_strjoin("", "");
    printf("Test 4 - \"\" + \"\" → \"%s\"\n", res4);
    free(res4);
}


void test_ft_strcpy(void)
{
    char dst1[10];
    char dst2[10];
    char dst3[10];
    char dst4[10];

    // Test 1: Normal copy
    printf("Test 1: Normal copy\n");
    ft_strcpy(dst1, "jami");
    printf("Result: %s\n\n", dst1);

    // Test 2: Empty string
    printf("Test 2: Empty string\n");
    ft_strcpy(dst2, "");
    printf("Result: \"%s\"\n\n", dst2);

    // Test 3: Longer string
    printf("Test 3: Longer string\n");
    ft_strcpy(dst3, "Hello42");
    printf("Result: %s\n\n", dst3);

    // Test 4: Check return value
    printf("Test 4: Check return value\n");
    char *ret = ft_strcpy(dst4, "abc");
    printf("Return pointer correct: %s\n\n", ret == dst4 ? "YES" : "NO");
}

void test_ft_strncpy(void)
{
    char dst1[10];
    char dst2[10];
    char dst3[10];
    char dst4[10];

    printf("---- Test 1: src shorter than n ----\n");
    ft_strncpy(dst1, "abc", 6);
    printf("ft_strncpy: \"%s\"\n", dst1);

    strncpy(dst2, "abc", 6);
    printf("strncpy   : \"%s\"\n\n", dst2);

    printf("---- Test 2: src exactly n ----\n");
    ft_strncpy(dst1, "123456", 6);
    printf("ft_strncpy: \"%s\" (may not print full buffer)\n", dst1);

    strncpy(dst2, "123456", 6);
    printf("strncpy   : \"%s\" (same behavior)\n\n", dst2);

    printf("---- Test 3: src longer than n ----\n");
    ft_strncpy(dst3, "abcdefghij", 5);
    dst3[5] = '\0'; // print safely
    printf("ft_strncpy: \"%s\"\n", dst3);

    strncpy(dst4, "abcdefghij", 5);
    dst4[5] = '\0';
    printf("strncpy   : \"%s\"\n\n", dst4);

    printf("---- Test 4: n = 0 ----\n");
    ft_strncpy(dst1, "hello", 0); // should do nothing
    strncpy(dst2, "hello", 0);    // same effect
    printf("ft_strncpy and strncpy didn't crash (n=0)\n\n");

    printf("---- Test 5: return value ----\n");
    char *ret = ft_strncpy(dst1, "xyz", 4);
    printf("Return pointer correct: %s\n", ret == dst1 ? "YES" : "NO");
}

void test_ft_strcat(void)
{
    char dst1[50];
    char dst2[50];
    char dst3[50];

    printf("---- Test 1: Basic concatenation ----\n");
    strcpy(dst1, "Hello ");
    strcpy(dst2, "Hello ");
    ft_strcat(dst1, "World");
    strcat(dst2, "World");
    printf("ft_strcat: \"%s\"\n", dst1);
    printf("strcat   : \"%s\"\n\n", dst2);

    printf("---- Test 2: Concatenate empty string ----\n");
    strcpy(dst1, "Test");
    strcpy(dst2, "Test");
    ft_strcat(dst1, "");
    strcat(dst2, "");
    printf("ft_strcat: \"%s\"\n", dst1);
    printf("strcat   : \"%s\"\n\n", dst2);

    printf("---- Test 3: dest initially empty ----\n");
    strcpy(dst1, "");
    strcpy(dst2, "");
    ft_strcat(dst1, "ABC");
    strcat(dst2, "ABC");
    printf("ft_strcat: \"%s\"\n", dst1);
    printf("strcat   : \"%s\"\n\n", dst2);

    printf("---- Test 4: src longer string ----\n");
    strcpy(dst1, "X");
    strcpy(dst2, "X");
    ft_strcat(dst1, "xxxxxxxxxxxxxxx");
    strcat(dst2, "xxxxxxxxxxxxxxx");
    printf("ft_strcat: \"%s\"\n", dst1);
    printf("strcat   : \"%s\"\n\n", dst2);

    printf("---- Test 5: Return value test ----\n");
    strcpy(dst3, "Hi ");
    char *ret = ft_strcat(dst3, "there");
    printf("Return pointer correct: %s\n", ret == dst3 ? "YES" : "NO");
}

void test_ft_strncat(void)
{
    char dst1[50];
    char dst2[50];
    char dst3[50];

    printf("---- Test 1: Basic n ----\n");
    strcpy(dst1, "Hello ");
    strcpy(dst2, "Hello ");
    ft_strncat(dst1, "World", 3);
    strncat(dst2, "World", 3);
    printf("ft_strncat: \"%s\"\n", dst1);
    printf("strncat   : \"%s\"\n\n", dst2);

    printf("---- Test 2: n larger than src ----\n");
    strcpy(dst1, "Hi ");
    strcpy(dst2, "Hi ");
    ft_strncat(dst1, "there", 20);
    strncat(dst2, "there", 20);
    printf("ft_strncat: \"%s\"\n", dst1);
    printf("strncat   : \"%s\"\n\n", dst2);

    printf("---- Test 3: n = 0 ----\n");
    strcpy(dst1, "Test");
    strcpy(dst2, "Test");
    ft_strncat(dst1, "XYZ", 0);
    strncat(dst2, "XYZ", 0);
    printf("ft_strncat: \"%s\"\n", dst1);
    printf("strncat   : \"%s\"\n\n", dst2);

    printf("---- Test 4: Empty src ----\n");
    strcpy(dst1, "Base");
    strcpy(dst2, "Base");
    ft_strncat(dst1, "", 5);
    strncat(dst2, "", 5);
    printf("ft_strncat: \"%s\"\n", dst1);
    printf("strncat   : \"%s\"\n\n", dst2);

    printf("---- Test 5: dest initially empty ----\n");
    strcpy(dst1, "");
    strcpy(dst2, "");
    ft_strncat(dst1, "ABC", 2);
    strncat(dst2, "ABC", 2);
    printf("ft_strncat: \"%s\"\n", dst1);
    printf("strncat   : \"%s\"\n\n", dst2);

    printf("---- Test 6: Return value ----\n");
    strcpy(dst3, "Yo ");
    char *ret = ft_strncat(dst3, "man", 2);
    printf("Return pointer correct: %s\n", ret == dst3 ? "YES" : "NO");
}

void    test_ft_strstr(void)
{
    const char  *hay1 = "hello world";
    const char  *hay2 = "foo bar baz";
    const char  *hay3 = "abcabcabc";
    const char  *hay4 = "short";
    const char  *hay5 = "";
    const char  *hay6 = "just testing";
    char        *res_ft;
    char        *res_lib;

    printf("====== TESTS FOR ft_strstr ======\n\n");

    printf("---- Test 1: Needle in the middle ----\n");
    res_ft = ft_strstr(hay1, "world");
    res_lib = strstr(hay1, "world");
    printf("haystack : \"%s\"\n", hay1);
    printf("needle   : \"%s\"\n", "world");
    printf("ft_strstr: %s\n", res_ft ? res_ft : "NULL");
    printf("strstr   : %s\n\n", res_lib ? res_lib : "NULL");

    printf("---- Test 2: Needle at start ----\n");
    res_ft = ft_strstr(hay2, "foo");
    res_lib = strstr(hay2, "foo");
    printf("haystack : \"%s\"\n", hay2);
    printf("needle   : \"%s\"\n", "foo");
    printf("ft_strstr: %s\n", res_ft ? res_ft : "NULL");
    printf("strstr   : %s\n\n", res_lib ? res_lib : "NULL");

    printf("---- Test 3: Multiple occurrences, should return first ----\n");
    res_ft = ft_strstr(hay3, "abc");
    res_lib = strstr(hay3, "abc");
    printf("haystack : \"%s\"\n", hay3);
    printf("needle   : \"%s\"\n", "abc");
    printf("ft_strstr: %s\n", res_ft ? res_ft : "NULL");
    printf("strstr   : %s\n\n", res_lib ? res_lib : "NULL");

    printf("---- Test 4: Needle not found ----\n");
    res_ft = ft_strstr(hay2, "xyz");
    res_lib = strstr(hay2, "xyz");
    printf("haystack : \"%s\"\n", hay2);
    printf("needle   : \"%s\"\n", "xyz");
    printf("ft_strstr: %s\n", res_ft ? res_ft : "NULL");
    printf("strstr   : %s\n\n", res_lib ? res_lib : "NULL");

    printf("---- Test 5: Empty needle ----\n");
    res_ft = ft_strstr(hay6, "");
    res_lib = strstr(hay6, "");
    printf("haystack : \"%s\"\n", hay6);
    printf("needle   : \"%s\"\n", "");
    printf("ft_strstr: %s\n", res_ft ? res_ft : "NULL");
    printf("strstr   : %s\n", res_lib ? res_lib : "NULL");
    printf("ft_strstr returns haystack: %s\n\n", res_ft == hay6 ? "YES" : "NO");

    printf("---- Test 6: Empty haystack ----\n");
    res_ft = ft_strstr(hay5, "a");
    res_lib = strstr(hay5, "a");
    printf("haystack : \"%s\"\n", hay5);
    printf("needle   : \"%s\"\n", "a");
    printf("ft_strstr: %s\n", res_ft ? res_ft : "NULL");
    printf("strstr   : %s\n\n", res_lib ? res_lib : "NULL");

    printf("---- Test 7: Needle longer than haystack ----\n");
    res_ft = ft_strstr(hay4, "longerneedle");
    res_lib = strstr(hay4, "longerneedle");
    printf("haystack : \"%s\"\n", hay4);
    printf("needle   : \"%s\"\n", "longerneedle");
    printf("ft_strstr: %s\n", res_ft ? res_ft : "NULL");
    printf("strstr   : %s\n\n", res_lib ? res_lib : "NULL");
}

void test_ft_memccpy(void)
{
    char dst1[50];
    char dst2[50];
    char src1[] = "hello world";
    char src2[] = "abcdefg";
    char src3[] = "123456789";

    void *ret_ft;
    void *ret_lib;

    printf("====== TESTS FOR ft_memccpy ======\n\n");

    printf("---- Test 1: Copy until 'o' ----\n");
    memset(dst1, 'X', sizeof(dst1));
    memset(dst2, 'X', sizeof(dst2));
    ret_ft  = ft_memccpy(dst1, src1, 'o', 20);
    ret_lib = memccpy(dst2, src1, 'o', 20);
    printf("ft_memccpy: \"%s\"\n", dst1);
    printf("memccpy   : \"%s\"\n", dst2);
    printf("return ptr is NULL? ft: %s | memccpy: %s\n\n",
        ret_ft ? "NO" : "YES", ret_lib ? "NO" : "YES");

    printf("---- Test 2: c not found ----\n");
    memset(dst1, 'X', sizeof(dst1));
    memset(dst2, 'X', sizeof(dst2));
    ret_ft  = ft_memccpy(dst1, src2, 'z', 7);
    ret_lib = memccpy(dst2, src2, 'z', 7);
    printf("ft_memccpy dst: \"%s\"\n", dst1);
    printf("memccpy    dst: \"%s\"\n", dst2);
    printf("return ptr: ft: %s | memccpy: %s\n\n",
        ret_ft ? "NOT NULL" : "NULL",
        ret_lib ? "NOT NULL" : "NULL");

    printf("---- Test 3: Copy binary data ----\n");
    unsigned char bin_src[] = {1, 2, 3, 4, 5, 6, 7};
    unsigned char bin_dst1[10] = {0};
    unsigned char bin_dst2[10] = {0};
    ret_ft  = ft_memccpy(bin_dst1, bin_src, 4, 7);
    ret_lib = memccpy(bin_dst2, bin_src, 4, 7);
    printf("ft stops at 4? %s\n",
        ret_ft ? "YES" : "NO");
    printf("memccpy stops at 4? %s\n\n",
        ret_lib ? "YES" : "NO");

    printf("---- Test 4: n = 0 ----\n");
    memset(dst1, 'A', 10);
    memset(dst2, 'A', 10);
    ret_ft  = ft_memccpy(dst1, src3, '5', 0);
    ret_lib = memccpy(dst2, src3, '5', 0);
    printf("ft dst unchanged: %s\n", dst1);
    printf("lib dst unchanged: %s\n", dst2);
    printf("returns NULL: ft: %s | lib: %s\n\n",
        ret_ft ? "NO" : "YES",
        ret_lib ? "NO" : "YES");

    printf("---- Test 5: Return pointer correctness ----\n");
    memset(dst1, 'Z', sizeof(dst1));
    ret_ft = ft_memccpy(dst1, "abcde", 'c', 5);
    printf("Return points to index 3? %s\n",
        (ret_ft == (void *)(dst1 + 3)) ? "YES" : "NO");
}

void test_ft_memalloc(void){

}

int main(void)
{
	printf("====== LIBFT TESTS ======\n\n");

    /*
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
	test_ft_strdup();
	test_ft_substr();	
	test_ft_strjoin();
    test_ft_strcpy();
    test_ft_strncpy();
    test_ft_strcat();
    test_ft_strncat();
    test_ft_strstr();
    test_ft_memccpy();
    */
   test_ft_memalloc();
   return 0;

}

