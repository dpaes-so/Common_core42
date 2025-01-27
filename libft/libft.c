#include "libft.h"
int ft_isalpha(int c)
{
    if ((c >= 65 && c <=90) || (c >= 97 && c <= 122))
    {
        return 1;
    }
    return 0;
}
/*int main()
{
    char c = 'A';
    int h = ft_isalpha(c);
    printf("%d", h);
}*/

int ft_isdigit(int c)
{
    if ((c >= 48 && c <=57))
    {
        return 1;
    }
    return 0;
}
/*int main()
{
    char c = '/';
    int h = ft_isdigit(c);
    printf("%d", h);
}*/

int ft_isalnum(int c)
{
    if ((c >= 65 && c <=90) || (c >= 97 && c <= 122) || (c >= 48 && c <=57))
    {
        return 1;
    }
    return 0;
}
/*int main()
{
    char c = 'A';
    int h = ft_isalnum(c);
    printf("%d", h);
}*/

int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
    {
        return 1;
    }
    return 0;
}
/*int main()
{
    char c = 'a';
    int h = ft_isascii(c);
    printf("%d", h);
}*/

int ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
    {
        return 1;
    }
    return 0;
}
/*int main()
{
    char c = '\n';
    int h = ft_isprint(c);
    printf("%d", h);
}*/

int ft_toupper(int c)
{
    if (c >= 97 && c <= 122)
        return (c -= 32);
    return c;
}
/*int main()
{
    char c = 'a';
    int h = ft_toupper(c);
    printf("%d", h);
}*/

int ft_tolower(int c)
{
    if (c >= 65 && c <= 90)
        return (c + 32);
    return c;
}
/*int main()
{
    char c = 'a';
    int h = ft_tolwoer(c);
    printf("%d", h);
}*/

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
/*int main()
{
    char str[] = "hello";
    int h = ft_strlen(str);
    printf("%d", h);
}*/

size_t ft_strlcpy(char *dest, const char *src, size_t destsize)
{
    size_t i;
    size_t srclen;

    i = 0;
    if (!src)
        return (0);
    srclen = ft_strlen(src);
    if (destsize == 0)
        return(srclen);
    while(src[i] != '\0' && i < destsize - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(srclen);
}

char *ft_strchr(const char *str, int c)
{
    int i;
    char *s;
    i = 0;
    s = (char *)str;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
        {
            return(s + i);
        }
        i++;
    }
    if ((char ) c == '\0')
        return (s + i);
    return NULL;
}
/*int main()
{
    char str[] =  "";
    char c = 'e';
    char *result = ft_strchr(str,c);
    printf("%s", result);
}*/

char *ft_strrchr(const char *str, char c)
{
    int i;
    char *s;

    i = 0;
    s = (char *)str;
    while (s[i] != '\0')
        i++;
    while (i >= 0)
    {
        if (str[i] == (char)c)
            return(s+ i);
        i--;
    }
    return NULL;
}
/*int main()
{
    char str[] =  "ola o daniel e gay";
    char c = 'e';
    char *result = ft_strrchr(str,c);
    printf("%s", result);
}*/

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return (0);
    while((s1[i] != '\0' || s2[i] != '\0') && i < n - 1)
    {
        if (!(s1[i] == s2[i]))
            return (s1[i] - s2[i]);
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
/*int main()
{
    char s1[] = "1234568";
    char s2[] = "1234567";
    int n = 6;
    int h = ft_strncmp(s1, s2, n);
    printf("%d\n", h);
}*/

int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int i;
    unsigned int dl;
    unsigned int sl;

    i = 0;
    dl = 0;
    sl = 0;
    while (dest[dl] != '\0')
        dl++;
    while (src[sl] != '\0')
        sl++;
    if (size <= dl)
        return  sl + size;
    while(src[i] != '\0' && dl + i < (size - 1))
    {
        dest[i + dl] = src[i];
        i++;
    }
    dest[i + dl] = '\0';
    return (dl + sl);
}
/*int main()
{
    char src[] = "world";
    char dest[12] = "hello";
    printf("OLD: %s\n", dest);
    int h = ft_strlcat(dest,src,10);
    printf("NEW: %s\n", dest);
    printf("%d", h);
    return 0;
}*/

char *ft_strnstr(char *hay, char *needle, size_t n)
{
    size_t i;
    size_t j;

    i = 0;
    if (needle[0] == '\0')
            return hay;
    while (hay[i] != '\0' && i < n)
    {
        j = 0;
        while (needle[j] != '\0' && hay[i + j] == needle[j] && (i + j) < n)
        {
            j++;
        }
        if (needle[j] == '\0')
        {
            return (hay + i);
        }
        i++;
    }
    return (NULL);
}
/*int main()
{
    char hay[] =  "eu gosto die pipocas e de carne";
    char needle[] = "de";
    char *result = ft_strnstr(hay,needle, 30);
    printf("%s", result);
}*/

int ft_atoi(const char *str)
{
    int i;
    int result;
    int sinal;

    i = 0;
    result = 0;
    sinal = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
    {
        i++;
    }
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            sinal = -sinal;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sinal);
}
/*int main()
{
    char str[] = "    \n123a5";
    int h = ft_atoi(str);
    printf("%d", h);
}*/

void *ft_memset(void *str, int c, size_t size)
{
    size_t i;
    unsigned char *array;

    i = 0;
    array = (unsigned char *)str;
    while(i < size)
    {
        array[i] = (unsigned char)c;
        i++;
    }
    return (str);
}
/*int main()
{
    char str[10];
    char str2[10];
    ft_memset(str,50,10);
    printf("%s\n",str);
    //write(1,"banana",6);
    memset(str2,50,10);
    printf("%s\n",str2);
}*/

void ft_bzero(void *str, int n)
{
    int i;
    unsigned char *array;

    i = 0;
    array = (unsigned char *)str;
    while(i < n)
    {
        array[i] = 0;
        i++;
    }
}
/*int main()
{
    char str[10];
    char str2[10];
    ft_bzero(str,10);
    printf("%s\n",str);
    //write(1,"banana",6);
    bzero(str2,10);
    printf("%s\n",str2);
}*/

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *arrayd;
    unsigned char *arrays;

    i = 0;
    arrayd = (unsigned char *)dest;
    arrays = (unsigned char *)src;
  while(i < n)
  {
    arrayd[i] = arrays[i];
    i++;
  }
  return (dest);
}
/*int main()
{
    char str[10];
    char str2[10] = "banana";
    ft_memcpy(str,str2,5);
    printf("%s\n",str);
    write(1,"\n",1);
    memcpy(str,str2,5);
    printf("%s\n",str);
    write(1,"\n",1);
    printf("%s\n",str2);
}*/

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *s1;
    const unsigned char *s2;

    s1 = (unsigned char*)dest;
    s2 = (const unsigned char*)src;
    if (s2 < s1)
    {
        s1 += n;
        s2 += n;
        while(n--)
        {
            *(--s1) = *(--s2);
        }
    }
    else
    {
        i = 0;
        while(i < n)
        {
             s1[i] = s2[i];
             i++;
        }
    }
    return(dest);
}
/*int main()
{
    char str[] = "Hello, world";
    char str2[] = "Hello, world";
    ft_memmove(str2,str2 + 7,5);
    printf("%s\n",str2);
    write(1,"\n",1);
    memmove(str,str+ 7 ,5);
    printf("%s\n",str);
}*/

void *ft_memchr(const void *str, int c, size_t n)
{
    unsigned char *s1;
    size_t i;
    s1 = (unsigned char *)str;
    i = 0;
    while (i < n)
    {
        if (s1[i] == (unsigned char)c)
        {
            return(s1 + i);
        }
        i++;
    }
    return NULL;
}
/*int main()
{
    char str[] =  "ola o daniel e gay";
    char c = 'e';
    char *result = ft_memchr(str,c,12);
    char *result2 = memchr(str,c,12);
    printf("%s\n", result);
    printf("%s\n", result2);
}*/

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
    size_t i;
    unsigned char *s1;
    const unsigned char *s2;

    i = 0;
    s1 = (unsigned char*)str1;
    s2 = (const unsigned char*)str2;
    while(i < n)
    {
        if (!(s1[i] == s2[i]))
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}
/*int main()
{
    char s1[] = "bana";
    char s2[] = "";
    int n = 6;
    int h = ft_memcmp(s1, s2, n);
    printf("%d\n", h);
    write (1, "\n", 1);
    int h2 = memcmp(s1, s2, n);
    printf("%d\n",h2);
}*/

void *ft_calloc(size_t num, size_t size)
{
    void *buffer;
    
    if (num && size > (size_t)(-1) / num) 
        return NULL; // Overflow detected
    buffer = malloc(num * size);
    if (buffer == NULL)
        return NULL;
    if (num == 0 || size == 0)
        return buffer;
    ft_bzero(buffer,num * size);
    return buffer;
}
/*int	main(void)
{
	int nmemb = 7;

	int *myAlloc = (int *)ft_calloc(nmemb, sizeof(int));
	if (myAlloc == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	for (int ctd = 0; ctd < nmemb; ctd++)
	{
		printf("%d ", ctd);
		if (myAlloc[ctd] != 0)
		{
			printf("Error: Allocated memory is not initialized to zero.\n");
			return (1);
		}
	}
	free(myAlloc);
	return (0);
}*/

char	*ft_strdup(const char *s)
{  char *buffer;
    int i;

    i = 0;
    buffer = malloc(ft_strlen(s) + 1);
    if (buffer == NULL)
        return NULL;
   while (s[i] != '\0')
    {
        buffer[i] = s[i];
        i++;
    }
    buffer[i] = '\0';
    return (buffer);
}
/*int main()
{
    char src[] = "banana";
    char *dest = ft_strdup(src);
    printf("%s\n",dest);
}*/
  
char *ft_substr(char const *s, unsigned int start,size_t len)
{
    char *buffer;
    size_t i;
    size_t str_len;
    str_len = (size_t)ft_strlen(s);

    i = 0;
    if (start + len > str_len)
        len = str_len - start;
    if(start >= str_len)
        len = 0;
    buffer = malloc(sizeof(char) * (len + 1));
    if(buffer == NULL)
        return NULL;
    while(i < len && s[start + i] != '\0')
    {
        buffer[i] = s[start + i];
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}
/*int main(void)
{
    char str[] = "42 Network";
    char *substr;

    // Test case 1: Normal case, extracting "Netw"
    substr = ft_substr(str, 3, 4);
    printf("Original string: \"%s\"\n", str);
    printf("Substring (start: 3, len: 4): \"%s\"\n", substr);
    free(substr); // Remember to free the allocated memory

    // Test case 2: Extracting beyond the string length
    substr = ft_substr(str, 50, 4); // Should return an empty string
    printf("Substring (start: 50, len: 4): \"%s\"\n", substr);
    free(substr);

    // Test case 3: Extracting more than remaining characters (should get "Network")
    substr = ft_substr(str, 3, 20);
    printf("Substring (start: 3, len: 20): \"%s\"\n", substr);
    free(substr);

    // Test case 4: Extracting from the very start (should get "42")
    substr = ft_substr(str, 0, 2);
    printf("Substring (start: 0, len: 2): \"%s\"\n", substr);
    free(substr);

    // Test case 5: Extracting an empty string (start: 0, len: 0)
    substr = ft_substr(str, 0, 0);
    printf("Substring (start: 0, len: 0): \"%s\"\n", substr);
    free(substr);

    return 0;
}*/

char *ft_strjoin(char const *s1, char const *s2)
{
    char *buffer;
    int i;
    int j;

    i = 0;
    j = 0;
    buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!buffer)
        return NULL;
    while(i < ft_strlen(s1))
    {
        buffer[i] = s1[i];
        i++;
    }
    while(j < ft_strlen(s2))
    {
        buffer[i + j] = s2[j];
        j++;
    }
    buffer[i+j] = '\0';
    return buffer;
}
/*int	main(void)
{
	char *test;

	test = ft_strjoin("test ", "string");
	printf("%s\n", test);

	free(test);
}*/

int check_c(const char c, const char *set)
{
    int i;

    i = 0;
    while(set[i] != '\0')
    {
        if(c == set[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}
char *ft_strtrim(char const *s1, char const *set)
{
    int len;
    int i;
    int j;
    char *buffer;

    j = 0;
    i = 0;
    if(s1 == NULL)
        return NULL;
    len = ft_strlen(s1);
    while (s1[i] && check_c(s1[i],set))
        i++;
    while (len > i && check_c(s1[len - 1],set))
        len--;
    buffer = malloc(sizeof(char) * ((len - i) + 1));
    if (!buffer)
        return NULL;
    while((i + j) < len)
    {
        buffer[j] = s1[i+j];
        j++;
    }
    buffer[j] = '\0';
    return buffer;
}
/*int	main(void)
{
	char *test;

	test = ft_strtrim("1234567890", "1234567890");
	printf("%s\n", test);
	free(test);
}*/

int countsep(char const *s, char c)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (s[i] != '\0') 
    {
        if (s[i] != c && !in_word) // Start of a new word
        {
            count++;       // Increment word count
            in_word = 1;   // Now we're inside a word
        }
        else if (s[i] == c) // Hit a delimiter
        {
            in_word = 0;   // Now we're outside a word
        }
        i++;
    }
    return count; // Return number of words
}
char **splitcat(char const *s, char c,char **buffer)
{
    int i = 0;
    int j = 0;
    int buffi = 0;
    int in_word = 0;

    while (s[i] != '\0')
    {
        if (s[i] != c) 
        {
            buffer[buffi][j++] = s[i];
            in_word = 1; 
        }
        else if (in_word) 
        {
            buffer[buffi][j] = '\0'; 
            buffi++; 
            j = 0;
            in_word = 0; 
        }
        i++;
    }
    if (in_word)
        buffer[buffi][j] = '\0';
    return (buffer);
}
int ft_splitfind(char const *s, char c)
{
    int i;

    i = 0;
    while(s[i] != c && s[i] != '\0')
    {
        i++;
    }
    return (i);
}
void *freem(char **buffer, int n)
{
    int i;

    i = 0;
    while(i < n)
    {
        free(buffer[i]);
        i++;
    }
    free(buffer);
    return NULL;
}
char **ft_split(char const *s, char c)
{
    char **result;
    int i;
    int j;
    int stringnum;
    int maxlen;

    stringnum = countsep(s,c);
    i = 0;
    j = 0;
    maxlen = 0;
    result = malloc(sizeof(char *) * (stringnum + 1));
    result[stringnum] = 0;
    if (!result)
        return NULL;
    while(i < stringnum)
    {
        while(s[maxlen] == c)
            maxlen++;
        j = ft_splitfind(s + maxlen,c);
        result[i] =malloc(sizeof(char) * (j + 1));
        maxlen += j + 1;
        if(!result[i])
            return (freem(result,i));
        i++;
    }
    return (result = splitcat(s,c,result));
}
/*int main()
{
    const char *str = ",,,hello,,,world,42,,,";
    char delimiter = ',';
    char **result = ft_split(str, delimiter);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("Substring %d: %s\n", i, result[i]);
        }
         for (int i = 0; result[i] != NULL; i++) {
            free(result[i]); // Free each allocated substring
        }
        free(result); // Finally, free the array of pointers
    } else {
        printf("Memory allocation failed. (main)\n");
    }
    return 0;
}*/

int intsize(int num)
{
    int i;
    long int n;

    n = num;
    i = 0;
    if (n == 0)
        return (1);
    if (n < 0)
    {
        n = -n;
        i++;
    }
    while (n > 0)
    {
        n = n/10;
        i++;
    }
    return (i);
}
char *ft_itoa(int n)
{
    int size;
    char *result;
    long int num;

    num = n;
    size = intsize(n);
    result = malloc(sizeof(char) * (size + 1));
    if(!result)
        return NULL;
    if(num == 0)
        result[0] = '0';
    if (num < 0)
    {
        result[0] = '-';
        num = -num;
    }
    result[size--] = '\0';
    while(size >= 0 && num > 0)
    {
        result[size] = (num % 10) + '0';
        size--;
        num = num /10;
    }
    return (result);
}
/*int main ()
{
    int n = -123;
    char *buffer = ft_itoa(n);
    printf("%s\n",buffer);
    free(buffer);
}*/

char to_upper_even_indices(unsigned int index, char c) {
    if (index % 2 == 0 && c >= 'a' && c <= 'z') {
        return c - 32; // Convert to uppercase (ASCII trick)
    }
    return c; // Return the character as is for odd indices
}
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int size;
    int i;
    char *buffer;

    size = 0;
    i = 0;
    while (s[size] != '\0')
        size++;
    buffer = malloc(sizeof(char) * size + 1);
    if (!buffer)
        return NULL;
    while (s[i] != '\0')
    {
        buffer[i] = f(i,s[i]);
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}
/*int main()
{
    char *s = "Hello world";
    char *result = ft_strmapi(s,to_upper_even_indices);
    printf("%s\n", result);
    free(result);
}*/

void oneascii(unsigned int n, char *c)
{
    (*c) = (*c) + n;
}
void ft_striteri(char *s, void (*f)(unsigned int,char*))
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        f(i,&s[i]);
        i++;
    }
}
/*int main()
{
    char s[] = "ABC";
    ft_striteri(s,oneascii);
    printf("%s\n",s);
}*/

void ft_putchar_fd(char c, int fd)
{
    if (fd >= 0)
		write(fd, &c, 1);
}
/*int main()
{
    char c = 'a';
    ft_putchar_fd(c,0);
    printf("\n");
}*/

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        write(fd,&s[i],1);
        i++;
    }
}
/*int main()
{
    char *c = "banana";
    ft_putstr_fd(c,0);
    printf("\n");
}*/

void ft_putendl_fd(char *s, int fd)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        write(fd,&s[i],1);
        i++;
    }
    write(fd,"\n",1);
}
/*int main()
{
    char *c = "banana";
    ft_putstr_fd(c,0);
    printf("\n");
}*/

void ft_putnbr_fd(int n, int fd)
{
    int i;
    char result[10];

    i = 0;
    if (n == -2147483648)
    {
       write (fd,"-2147483648",11);
       return;
    }
    else if( n == 0)
        write (fd,"0",1);
    if (n < 0)
    {
        write(fd,"-",1);
        n = -n;
    }
    while(n > 0)
    {
        result[i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }
    while(i > 0)
        write(fd,&result[--i],1);  
}
/*int main()
{
    int n = 12345;
    ft_putnbr_fd(n,1);
    return 0;
}*/

//BONUS PART
