#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *s1, const char *s2);

int main(void) {

	printf("Testing ft_strlen: \n");
    const char *str = "hello, libasm!";
    size_t len = ft_strlen(str);
    printf("Length of \"%s\" is %zu\n", str, len);

	printf("Testing ft_strcpy: \n");
	char *dst = malloc(sizeof(char) * 7);
	char *src = "Hello!";
	ft_strcpy(dst, src);
	printf("dst is %s\n", dst);
	free(dst);
	dst = NULL;

	printf("Testing ft_strcmp: \n");

	// Assert tests for ft_strcmp
    assert(ft_strcmp("abc", "abc") == 0);
    assert(ft_strcmp("abc", "abd") < 0);
    assert(ft_strcmp("abd", "abc") > 0);
    assert(ft_strcmp("", "") == 0);
    assert(ft_strcmp("", "a") < 0);
    assert(ft_strcmp("a", "") > 0);
	assert(ft_strcmp("abc", "abcd") < 0);

    printf("All ft_strcmp tests passed!\n");

    return 0;
}
