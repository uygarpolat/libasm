#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

int main(void)
{
    {
        // Testing ft_strlen
        assert(ft_strlen("hello, libasm!") == strlen("hello, libasm!"));
        assert(ft_strlen("") == strlen(""));
        printf("✅ ft_strlen tests passed!\n");
    }

    {
        // Testing ft_strcpy
        char *dst = malloc(sizeof(char) * 7);
        char *src = "Hello!";
        ft_strcpy(dst, src);
        assert(strcmp(dst, src) == 0);
        free(dst);
        dst = NULL;
        printf("✅ ft_strcpy tests passed!\n");
    }

    {
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
    }

    {
        // Testing ft_write
        int pipefd[2];
        char buf[100];
        int ret;

        pipe(pipefd);

        char *msg = "hello";
        ret = ft_write(pipefd[1], msg, 5);
        assert(ret == 5);

        ret = read(pipefd[0], buf, 5);
        assert(ret == 5);
        buf[5] = '\0';
        assert(strcmp(buf, msg) == 0);

        // Testing the error condition by writing to an invald file descriptor
        errno = 0;
        ret = ft_write(-1, msg, 5);
        assert(ret == -1);
        assert(errno != 0);

        close(pipefd[0]);
        close(pipefd[1]);

        printf("✅ ft_write tests passed!\n");
    }

    {
        // Testing ft_read:
        int pipefd[2];
        char buf[100];
        ssize_t ret;

        pipe(pipefd);

        const char *msg = "data";
        ret = write(pipefd[1], msg, strlen(msg));
        assert(ret == (ssize_t)strlen(msg));

        memset(buf, 0, sizeof(buf));
        ret = ft_read(pipefd[0], buf, sizeof(buf) - 1);
        assert(ret == (ssize_t)strlen(msg));
        buf[ret] = '\0';
        assert(strcmp(buf, msg) == 0);

        // Testing the error condition by reading from an invalid file descriptor
        errno = 0;
        ret = ft_read(-1, buf, 10);
        assert(ret == -1);
        assert(errno != 0);

        close(pipefd[0]);
        close(pipefd[1]);

        printf("✅ ft_read tests passed!\n");
    }

    return (0);
}
