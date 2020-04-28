#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int         ft_strlen(char *str);
char        *ft_strcpy(char *dst, char *src);
int         ft_strcmp(char *s1, char *s2);
ssize_t     ft_write(int fd, const void *buf, size_t count);
ssize_t     ft_read(int fd, void *buf, size_t count);
char        *ft_strdup(const char *s);

int         main(void)
{
    char    *s1 = malloc(sizeof(char) * 10);
    char    *s2 = malloc(sizeof(char) * 10);
    char    *s3 = malloc(sizeof(char) * 10);
    char    *s4 = malloc(sizeof(char) * 10);
    char    *s5 = 0;
    char    *buf1 = malloc(sizeof(char) * 250);
    char    *buf2 = malloc(sizeof(char) * 250);
    s2 = "hallodoei";
    s3 = "dc";
    s4 = "xe";

    ///////////////////FT_STRLEN/////////////////////
    printf("\nstrlen = %ld\n", strlen("blablabla"));
    printf("ft_strlen = %d\n", ft_strlen("blablabla"));
    printf("strlen = %ld\n", strlen(s1));
    printf("ft_strlen = %d\n", ft_strlen(s1));
    printf("ft_strlen = %d\n\n", ft_strlen(0));
    
    ///////////////////FT_STRCPY//////////////////////////
    printf("strcpy = %s\n", strcpy(s1, s2));
    printf("ft_strcpy = %s\n", ft_strcpy(s1, s2));
    printf("strcpy = %s\n", strcpy(s1, "Hello world!!!"));
    printf("ft_strcpy = %s\n", ft_strcpy(s1, "Hello world!!!"));
    printf("ft_strcpy = %s\n", ft_strcpy(s1, 0));
    printf("ft_strcpy = %s\n\n", ft_strcpy(0, s1));

    ////////////////////FT_STRCMP/////////////////////////
    printf("strcmp = %d\n", strcmp(s3, s4));
    printf("ft_strcmp = %d\n", ft_strcmp(s3, s4));
    printf("strcmp = %d\n", strcmp(s1, "Hello world"));
    printf("ft_strcmp = %d\n", ft_strcmp(s1, "Hello world"));
    s1 = 0;
    free(s1);
    s1 = malloc(sizeof(char) * 10); 
    printf("strcmp = %d\n", strcmp(s1, s3));
    printf("ft_strcmp = %d\n", ft_strcmp(s1, s3));
    printf("ft_strcmp = %d\n", ft_strcmp(0, s3));
    printf("strcmp = %d\n", strcmp(s3, s1));
    printf("ft_strcmp = %d\n", ft_strcmp(s3, s1));
    printf("ft_strcmp = %d\n", ft_strcmp(s3, 0));
    printf("ft_strcmp = %d\n\n", ft_strcmp(0, 0));

    ////////////////////FT_WRITE/////////////////////////
    ft_write(1, "write = ", 8);
    int a = write(1, "Hello world!\n", 13);
    ft_write(1, "ft_write = ", 11);
    int b = ft_write(1, "Hello world!\n", 13);
    printf("return write = %d\nreturn ft_write = %d\n", a, b);
    a = write(99, "Hello world!\n", 13);
    b = ft_write(99, "Hello world!\n", 13);
    printf("return write = %d\nreturn ft_write = %d\n", a, b);
    a = write(1, 0, 9);
    b = ft_write(1, 0, 9);
    printf("return write = %d\nreturn ft_write = %d\n", a, b);
    a = write(1, s5, 1);
    b = ft_write(1, s5, 1);
    printf("return write = %d\nreturn ft_write = %d\n\n", a, b);

    ////////////////////FT_READ/////////////////////////
    int fd = open("ft_read.s", O_RDONLY);
    a = read(fd, buf1, 250);
    close(fd);
    fd = open("ft_read.s", O_RDONLY);
    b = ft_read(fd, buf2, 250);
    printf("return read = %d\nreturn ft_read = %d\n", a, b);
    printf("strcmp(buffer_read, buffer_ft_read) = %d\n", ft_strcmp(buf1, buf2));
    a = read(333, buf1, 250);
    b = ft_read(333, buf2, 250);
    printf("return read = %d\nreturn ft_read = %d\n", a, b);
    printf("strcmp(buffer_read, buffer_ft_read) = %d\n", ft_strcmp(buf1, buf2));
    close(fd);
    fd = open("ft_read.s", O_RDONLY);
    buf1 = 0;
    buf2 = 0;
    a = read(fd, buf1, 250);
    b = ft_read(fd, buf2, 250);
    printf("return read = %d\nreturn ft_read = %d\n\n", a, b);

    ////////////////////FT_STRDUP/////////////////////////
    printf("strdup = %s\n", strdup("Hello world!"));
    printf("ft_strdup = %s\n", ft_strdup("Hello world!"));
    printf("strdup = %s\n", strdup(""));
    printf("ft_strdup = %s\n", ft_strdup(""));
    s1 = 0;
    printf("ft_strdup = %s\n", ft_strdup(s1));
    printf("ft_strdup = %s\n\n", ft_strdup(0));


    return (0);
}