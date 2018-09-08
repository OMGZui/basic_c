#include "../apue.h"
#include <dirent.h>

int main(int argc, char const *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
    {
        err_quit("使用：ls 目录名字");
    }

    if ((dp = opendir(argv[1])) == NULL)
    {
        err_sys("不能打开 %s", argv[1]);
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}
