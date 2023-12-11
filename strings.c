#include "shell.h"
/**
 * _strlen - Returns the length of a string.
 * @s: string.
 *
 * Return: j.
 */
int _strlen(char *s)
{
int i = 0;
int j = 0;

while (s[i] != '\0')
{
    j++;
    i++;
}
return (j);
}

/**
  *_strdup - returns a pointer to a newly alloctaed
  *space in memory which contains a copy of the string
  *passed.
  *@str: pointer to string being duplicated.
  *
  *Return: NULL if str is NULL.
  *pointer to duplicated string on success.
  *NULL if memory was insufficient.
  */

char *_strdup(char *str)
{
	char *nstr;
	unsigned int len, i;

	/* check is str is null */
	if (str == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	nstr = malloc(sizeof(char) * (len + 1));
	/*check if malloc was successful*/
	if (nstr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		nstr[i] = str[i];
	}
	nstr[len] = '\0';
	return (nstr);
}
/**
 *_strcmp - compares two strings.
 *@s1: pointer to first string.
 *@s2: pointer to second string.
 *
 *Return: value less than 0 if string is less than the other.
 *value greater than 0 if string is greater than the other.
 *0 if strings are equal.
 */

int _strcmp(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        }
return (s1[i] - s2[i]);
}
/**
 * _strspn - a function that gets the
 *           length of a prexif substring
 *
 * @s: pointer to string input
 * @accept: substring prefix to look for
 *
 * Return: the number of bytes in the initial segment
*/

int _strspn(char *s, char *accept)
{
    int i, j, d;

    for (i = 0; s[i] != '\0'; i++)
    {
        d = 0;
        for (j = 0; accept[j] != '\0'; j++)  
        {
            if (s[i] == accept[j])
            {
                d = 1;
                break;
            }
        }
        if (!d)
        {
            break;
        }
    }
    return (i);
}
