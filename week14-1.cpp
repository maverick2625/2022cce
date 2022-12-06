#include <stdio.h>
int sum(int a, int b);///先宣告 declare

int main()
{///在用之前，先宣告declare or 定義 define
    int ans = (2 ,3); ///呼叫
    printf("ans: %d\n",ans);

}

int sum(int a, int b) ///定義 define
{
    return a + b;
}
