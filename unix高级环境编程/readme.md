# unix高级环境编程

《Advanced Programming in the UNIX Environment》读书笔记

## 环境搭建

```bash
# 源码
wget http://www.apuebook.com/src.3e.tar.gz
tar zxvf src.3e.tar.gz
cd apue.3e && make
```

```c
#include "../apue.h"
#include <dirent.h>

// myls.c
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
```

```bash
# 方法一 一劳永逸
sudo cp apue.3e/include/apue.h /usr/include
sudo cp apue.3e/lib/libapue.a /usr/include
gcc myls.c -o myls -lapue
./myls .
./myls /usr
# 报错解决
csrutil disable
重启后再进行cp操作
```

```bash
# 方法二 本地调试
复制apue.3e目录中include/apue.h和lib/libapue.a到自己的目录下
cp apue.3e/include/apue.h .
cp apue.3e/lib/libapue.a .
# 其实make就可以看出编译方式，`-L`将目录添加到库搜索路径 `-lapue`搜索libapue.a
gcc myls.c -o myls -L ../ -lapue
./myls .
./myls /usr
```