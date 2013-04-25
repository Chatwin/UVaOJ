#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *ch = "A   3  HIL JM O   2TUVWXY5";
char *num = "1SE Z  8 ";

bool is_pal( char *s)
{
    int len = strlen(s);
    for( int i = 0; i < len; i ++)
        if( s[i] != s[len - i - 1])
            return false;
    return true;
}

bool is_mirror( char *s)
{
    int len = strlen(s);
    for( int i = 0; i < len; i ++)
    {
        if ( isalpha(s[i]) && s[len - i - 1] != ch[s[i] - 'A']) return false;
        else if ( isdigit(s[i]) && s[len - i - 1] != num[s[i] - '1']) return false;
    }
    return true;
}

int main()
{
    char str[1024];
    while( scanf( "%s", str) != EOF)
    {
        bool flag1 = is_pal( str);
        bool flag2 = is_mirror( str);
        if( flag1 && flag2)
            printf( "%s -- is a mirrored palindrome.\n\n", str);
        if( flag1 && !flag2)
            printf( "%s -- is a regular palindrome.\n\n", str);
        if( flag2 && !flag1)
            printf( "%s -- is a mirrored string.\n\n", str);
        if( !flag1 && !flag2)
            printf( "%s -- is not a palindrome.\n\n", str);
    }
    return 0;
}
