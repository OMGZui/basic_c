#include <stdio.h>
#include <stdlib.h> // system()
#include <termios.h> // getch() kbhit()
#include <locale.h>
#include <unistd.h>
#include <fcntl.h>

int getch(void);
int kbhit(void); 

int main(void)
{
    int i, j;
    int x = 5;
    int y = 10;
    char input;
    int isFire = 0;

    int ny = 5;
    int isKilled = 0;

    while (1)
    {
        system("clear"); // 清屏函数

        // 输出靶子
        if (!isKilled){
            for (j=0;j<ny;j++){
                printf(" ");
            }
            printf("+\n");
        }

        // 输出飞机上面的空行
        if (isFire==0){
            for (i = 0; i < x; i++){printf("\n");}
        }else{
            // 输出飞机上面的激光竖线
            for(i=0;i<x;i++){
                for (j=0;j<y;j++){
                    printf(" ");
                }
                printf("  |\n");
            }
            isFire = 0;
        }
        
        // 输出飞机左边的空格 并画出飞机
        for (j = 0; j < y; j++){printf(" ");}
        printf("  *\n"); 
        for (j = 0; j < y; j++){printf(" ");}
        printf("*****\n");
        for (j = 0; j < y; j++){printf(" ");}
        printf(" * * \n");


        if (kbhit())
        {
            input = getch(); // 根据用户的不同输入来移动
            switch(input){
                case 'w': x--; break; // ↑
                case 's': x++; break; // ↓
                case 'a': y--; break; // ←
                case 'd': y++; break; // →
                case ' ': isFire = 1; break; // 空格控制发射子弹
                default : break;
            }
        }
        // 0.5秒
        usleep(500000);
    }
}

int getch(void)
{
    struct termios tm, tm_old;
    int fd = 0, ch;
    if (tcgetattr(fd, &tm) < 0)
        return -1;
    tm_old = tm;
    cfmakeraw(&tm);
    if (tcsetattr(fd, TCSANOW, &tm) < 0)
        return -1;
    ch = getchar();
    if (tcsetattr(fd, TCSANOW, &tm_old) < 0)
        return -1;
    return ch;
}

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}
