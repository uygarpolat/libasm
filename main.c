#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *s1, const char *s2);

int main(void)
{

    // Testing ft_strlen
    assert(ft_strlen("hello, libasm!") == strlen("hello, libasm!"));
    assert(ft_strlen("") == strlen(""));
    printf("✅ ft_strlen tests passed!\n");

    // Testing ft_strcpy
	char *dst = malloc(sizeof(char) * 7);
	char *src = "Hello!";
	ft_strcpy(dst, src);
    assert(strcmp(dst, src) == 0);
	free(dst);
	dst = NULL;
	printf("✅ ft_strcpy tests passed!\n");

    // Testing ft_strcmp
    assert(ft_strcmp("abc", "abc") == 0);
    assert(ft_strcmp("abc", "abx") < 0);
    assert(ft_strcmp("aby", "abc") > 0);
    assert(ft_strcmp("", "") == 0);
    assert(ft_strcmp("", "a") < 0);
    assert(ft_strcmp("a", "") > 0);
	assert(ft_strcmp("123", "1230") < 0);
    assert(ft_strcmp("5678", "567") > 0);
    printf("✅ ft_strcmp tests passed!\n");

    return (0);
}
