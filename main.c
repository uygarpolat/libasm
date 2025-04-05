#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
int     ft_atoi(char *nptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memset(void* s, int c, size_t n);

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

	{
		// Testing ft_strdup:
		char *original = "Hello, Libasm!";
		char *dup = ft_strdup(original);
		
		assert(dup != NULL);
		assert(strcmp(original, dup) == 0);
		assert(dup != original);
		free(dup);
		dup = NULL;

		original = "";
		dup = ft_strdup(original);
		assert(dup != NULL);
		assert(strcmp(original, dup) == 0);
		free(dup);
		dup = NULL;

		printf("✅ ft_strdup tests passed!\n");
	}

    {
        // Testing ft_atoi:
        assert(ft_atoi("42") == atoi("42"));
        assert(ft_atoi("                    93") == atoi("                    93"));
        assert(ft_atoi("   -17") == atoi("   -17"));
        assert(ft_atoi("   +0234      ") == atoi("   +0234      "));
        assert(ft_atoi("4193 with words") == atoi("4193 with words"));
        assert(ft_atoi("words and 987") == atoi("words and 987"));
        assert(ft_atoi("") == atoi(""));
        printf("✅ ft_atoi tests passed!\n");
    }

	{
		// Testing ft_memcpy:
		char src[50] = "Hello, memory!";
		char dest[50] = {0};
		ft_memcpy(dest, src, strlen(src) + 1);
		assert(strcmp(dest, src) == 0);
	
		char original[20] = "unchanged";
		char temp[20];
		strcpy(temp, original);
		ft_memcpy(temp, "modified", 0);
		assert(strcmp(temp, original) == 0);
	
		char src2[] = "abcdef";
		char dest2[10] = {0};
		ft_memcpy(dest2, src2, 5);
		dest2[5] = '\0';
		assert(strcmp(dest2, "abcde") == 0);
	
		printf("✅ ft_memcpy tests passed!\n");
	}

    {
        // Testing ft_memset:
        char buf1[20];
        ft_memset(buf1, 'A', 10);
        for (size_t i = 0; i < 10; i++) {
            assert(buf1[i] == 'A');
        }
    
        char buf2[20] = "Hello, World!";
        ft_memset(buf2, 'X', 0);
        assert(strcmp(buf2, "Hello, World!") == 0);
    
        char buf3[20];
        ft_memset(buf3, 'Z', sizeof(buf3));
        for (size_t i = 0; i < sizeof(buf3); i++) {
            assert(buf3[i] == 'Z');
        }
    
        printf("✅ ft_memset tests passed!\n");
    }    

    return (0);
}
