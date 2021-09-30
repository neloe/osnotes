#include <unistd.h>
#include <stdio.h>
#include <pwd.h>

void prompt()
{
    uid_t uid=getuid();
    struct passwd * pw = getpwuid(uid);
    printf("%s\n", pw->pw_name);
}

int main()
{
    prompt();
    return 0;
}
