// Forward declaration of isBadVersion API.
#include <stdio.h>

#define TOTAL_VERSION 5
#define BAD_VERSION   2

#define bool  char
#define true  1
#define false 0

bool isBadVersion(int version)
{
    if (version >= BAD_VERSION)
        return true;
    else
        return false;
}

int firstBadVersion(int n) {
    int big = n;
    int small = 1;
    int try_version;
    if (isBadVersion(1))
        return 1;
    do {
        try_version = small+(big-small)/2;
        //printf("try_version=%d\tsmall=%d\tbig=%d\n", try_version, small, big);
        if (isBadVersion(try_version))
            big = try_version;
        else
            small = try_version;
    } while(big != small+1);
    return big;
}

int main()
{
    printf("bad version=%d\n", firstBadVersion(TOTAL_VERSION));
    return 0;
}