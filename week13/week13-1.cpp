#include <stdio.h>
int main()
{
    int a[50];
    a[0] = 0;
    a[1] = 1;
    printf("1 ");

    for(int i=2; i<20 ; i++){
        a[i]=a[i-1]+a[i-2];
        printf("%d ",a[i]);
    }

}
