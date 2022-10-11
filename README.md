# 2022cce
2層迴圈, 以常利用「畫星星」來考大家對迴圈的熟練程度。網路上可以找到有網友問「用星星畫倒過來的三角形」,所以利用「左手i、右手j」的口訣, 來思考迴圈執行的樣子, 先把 i:5 i:4 i:3 i:2 i:1 印出來, 使用倒過來的迴圈。裡面的 j迴圈, 則是用基礎型, 便可畫出你想要的星星形狀。請用 CodeBlocks 實作 week06-1.cpp 執行時有附上鷹架, 截圖上傳成 week06-1.png
```cpp
#include <stdio.h>
int main()
{
    for(int i=5; i>0; i--){
        for(int j=0; j<i; j++){
            printf("*");
        }
        printf("i:%d星星\n" ,i);
    }
}

```

有了「左手i 當鷹架, 右手j 一直做」的口訣, 我們寫程式的另外一題畫星星, 畫出等腰三角形。這個比較難一點, 因為星星的數量是 1 3 5 7 9, 而且空格的數量也很奇怪, 是 4 3 2 1 0, 所以先利用左手i 建出鷹架, 看到很多樓層。接下來, 試著印出空格有幾個? 星星有幾個? 最後改用 for(int k=0; k<space; k++) 的迴圈, 來畫出空格, 利用 for(int k=0; k<star; k++) 的迴圈, 來畫出星星, 收尾時印跳行, 完成任務。請用 CodeBlocks 實作 week06-2.cpp 截圖上傳成 week06-2.png
```cpp
#include <stdio.h>
int main()
{
    for(int i=1; i<=5; i++){
        int space=5-i, star=2*i-1;
        for(int k=0; k<space; k++) printf(" ");
        for(int k=0; k<star; k++) printf("*");
        printf("\n");
    }
}

```
step02-1_解釋完畫星星後, 老師想教小學的約分。最直覺的方法, 就是暴力去試,把全部的數字都試看看能不能整除、能不能約分。用 1個for迴圈 for(int i=1; i<=a; i++) 去試全部的數, 這個數 i 如果可以兩個都整除 if(a%i==0 && b%i==0) 就可以找到答案了 ans = i; 請用 CodeBlocks實作 week06-3.cpp 截圖上傳成 week06-3.png
```cpp
#include <stdio.h>
int main()
{
    printf("請輸入2個整數,要約分: ");
    int a,b;
    scanf("%d %d", &a, &b);

    int ans;
    for(int i=1; i<=a; i++){
        if(a%i==0 && b%i==0){
            ans=i;
        }
    }

    printf("ans: %d 可約分", ans);
}

```
step02-2_「輾轉相除法」可以找最大公因數。不過大家應該都忘光了。108課綱的國中生也不用學輾轉相除法, 因為有點難理解, 其他國家的國中生也不教這個內容。但是這真的是很巧妙的方法,可以快速約分哦 口訣老大a、老二b、老三c=a%b 如果是0 則老二b是答案。老二變老大、老三變老二, 繼續做,就成功了。請用 CodeBlocks 實作 week06-4.cpp 裡面有把老大、老二、老三的數值印出來, 速度可以比暴力法快幾億倍。截圖上傳成 week06-4.png
```cpp
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d", &a ,&b);
    while(1){
        c=a%b;
        printf("老大:%d 老二:%d 老三:%d\n",a ,b ,c);
        if( c==0 )break;
        a=b;
        b=c;
    }
    printf("答案b: %d ", b);
}

```
