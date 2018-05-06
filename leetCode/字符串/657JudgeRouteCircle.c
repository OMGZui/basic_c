#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Initially, there is a Robot at position (0, 0). Given a sequence of its moves,
// judge if this robot makes a circle, which means it moves back to the original place.

// The move sequence is represented by a string. And each move is represent by a character.
// The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true
// or false representing whether the robot makes a circle.

// Example 1:
//     Input: "UD"
//     Output: true
// Example 2:
//     Input: "LL"
//     Output: false

bool judgeCircle(char *);

int main()
{
    char *moves = "UD";
    if (judgeCircle(moves))
    {
        puts("ok");
    }
    else
    {
        puts("no ok");
    }
}

bool judgeCircle(char *moves)
{
    int x = 0, y = 0;
    int i = 0;

    int length = strlen(moves);
    for (i = 0; i < length; i++)
    {
        switch (*(moves + i))
        {
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        case 'R':
            x++;
            break;
        case 'L':
            x--;
            break;
        default:
            return false;
        }
        printf("%c\n", *(moves + i));
        printf("x=%d\n", x);
        printf("y=%d\n", y);
    }
    return x == 0 && y == 0;
}
