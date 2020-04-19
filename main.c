#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *name = getenv("USER");
    if (NULL != name)
    {
        printf("%s\n", name);
    }
    return 0;
}
