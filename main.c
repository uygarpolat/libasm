/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:44:37 by upolat            #+#    #+#             */
/*   Updated: 2025/04/05 20:38:45 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
        for (size_t i = 0; i < 10; i++)
            assert(buf1[i] == 'A');
    
        char buf2[20] = "Hello, World!";
        ft_memset(buf2, 'X', 0);
        assert(strcmp(buf2, "Hello, World!") == 0);
    
        char buf3[20];
        ft_memset(buf3, 'Z', sizeof(buf3));
        for (size_t i = 0; i < sizeof(buf3); i++)
            assert(buf3[i] == 'Z');
    
        printf("✅ ft_memset tests passed!\n");
    }

    {
        // Testing ft_bzero:
        char buf1[20];
        memset(buf1, 'A', sizeof(buf1));
        ft_bzero(buf1, sizeof(buf1));
        for (size_t i = 0; i < sizeof(buf1); i++)
            assert(buf1[i] == 0);
    
        char buf2[20] = "Hello, world!";
        ft_bzero(buf2 + 5, 3);
        assert(buf2[5] == 0);
        assert(buf2[6] == 0);
        assert(buf2[7] == 0);
        assert(strncmp(buf2, "Hello", 5) == 0);
    
        char buf3[20] = "Testing";
        ft_bzero(buf3, 0);
        assert(strcmp(buf3, "Testing") == 0);
    
        printf("✅ ft_bzero tests passed!\n");
    }

    {
        // Testing ft_strchr
        char *result;
    
        result = ft_strchr("hello", 'e');
        assert(result != NULL);
        assert(*result == 'e');
        assert(result == "hello" + 1);
    
        result = ft_strchr("banana", 'a');
        assert(result != NULL);
        assert(*result == 'a');
        assert(result == "banana" + 1);
    
        result = ft_strchr("hello", 'z');
        assert(result == NULL);
    
        result = ft_strchr("test", '\0');
        assert(result != NULL);
        assert(*result == '\0');
    
        result = ft_strchr("", '\0');
        assert(result != NULL);
        assert(*result == '\0');
    
        result = ft_strchr("", 'a');
        assert(result == NULL);
    
        printf("✅ ft_strchr tests passed!\n");
    }    

    return (0);
}
