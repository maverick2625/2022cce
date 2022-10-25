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

1. step01-1_在實習課中有「列出全部質數」的題目。為了思考清楚, 我們今天改從「判斷1個質數」開始寫起。使用for迴圈, 去試2...n-1的數(因為1和n本身,一定會整除)。用一個變數 int bad=0 表示迴圈之前沒有壞掉。如有整除, 就視為失敗、不再是質數。迴圈後,看bad的值, 就知道是不是經過嚴格檢查的質數。用CodeBlocks實作 week08-1.cpp 截圖上傳 week08-1.png
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int bad=0;
    for(int i=2;i<n;i++){
        if(n%i==0) bad=1;
    }
    if(bad==0) printf("%d 是質數" ,n);
    else printf("%d 不好,不是質數", n);
}


2. step01-2_實習課中的題目, 有一題是要判段 2...某個範圍裡, 有幾個質數。所以老師在瘋狂程設裡, 先用一個大迴圈, 印出全部的數,讓你了解2...a 的範圍的迴圈。接下來, 利用 week08-1.cpp 程式碼的核心, 來判斷 n 是不是質數。所以, 會有2個迴圈。用瘋狂程設-第07週實習課堂作業-列出質數, 用練習模式, 截圖上傳 week08-2.png。(然後, 再把程式碼 copy 到CodeBlocks, 存檔成 week08-2.cpp)
#include <stdio.h>
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		for(j=2;j<i;j++){
			if(i%j==0)
			{break;}
		}
		if (j==i)
		printf("%d ",i);
	}
}


3. 為了增加對迴圈的熟悉程度, 老師用加總的範例來講解, 輸入5個數字, 把它們加起來。迴圈前面 int sum=0; 迴圈中間修改 sum += n; 迴圈後面 把 sum 印出來。請用 CodeBocks實作 week08-3.cpp, 截圖上傳 week08-3.png
#include <stdio.h>
int main()
{
    printf ("請輸入5個數字(要加起來):");

    int n;
    int sum=0;
    for(int i=0; i<5; i++){
        scanf("%d",&n);
        sum +=n;
    }
    printf("總和是:%d",sum);
}


4. 上週實習課,同學大多可以寫出直角三角形, 但今天只剩下不到一半會寫。while迴圈也是。所以老師利用健身的故事說明, 教練幫你把手抬高, 沒辦法練出肌肉。但健身重覆的動作很累、很辛苦, 所以要有個夢想, 就像挖隧道一樣,兩個方向都挖, 比較快看到結果。作法是(1)善用迴圈「建立鷹架(樓層i)」, (2)再把星星搞定, (3) 再把空格搞定, (4) 再拆掉鷹架。請用 CodeBlocks實作 week08-4.cpp 一步步練習, 逐步貼到瘋狂程設(上週的練習), 最後截圖瘋狂程設 week08-4.png 上傳。
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    for (int i=1; i<=n; i++){
        for(int k=1;k<=n-i;k++) printf(" ");
        for(int k=1;k<=i;k++) printf("*");
        printf("\n");
        }
}


5. step02-2_大家對while迴圈印直角三角形,幾乎全部忘記了。老師引導大家,先簡化問題,如果for迴圈寫得出來, 就能翻譯成 while迴圈。關鍵問題是,怎麼只用2個for迴圈來寫出「有時候印空格、有時候印星星」的直角三角形。口訣是,正方形。先能用星星印出正方形,表示你的迴圈做好了。接下來if(判斷)來決定什麼時候改印空格, 就要再導一下 第i樓有n-i個空格, 所以 if(k=n-i)時,都印空格,便完成了。請在 CodeBlocks 寫 week08-5.cpp 將正方形完成後, 移到 瘋狂程設, 修改出關鍵的 if(判斷), 成功後瘋狂程設截圖上傳 week08-5.png

#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);

	for(int i=1; i<=n; i++){
		for(int k=1; k<=n; k++){
			if(k<=n-i) printf(" ");
			else	printf("*");
		}
		printf("\n");
	}


}


6. step03-1_今天大魔王,是要用2個while迴圈, 畫出有空格、有星星的右方直角三角形。它有點難, 尤其只是只能2個迴圈指令。所以老師今天是先用前面2個程式作業來引選, 有正方形, 配合 if(判斷)來決定誰印空格、誰印了星星後, 再將前一個程式, 逐一把 for迴圈的前面初始變數、中間判斷、後面收尾, 變成 while迴圈的樣子。翻譯完就成功了。請在 瘋狂程設 while2 那題練習模式翻譯好,執行通過, 截圖上傳 week08-6.png (程式碼再用CodeBlocks存檔成week08-6.cpp)
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);

	int i=1;
	while (i<=n){

		int k=1;
		while(k<=n){

			if(k<=n-i) printf(" ");
			else printf("*");
			k++;

		}
		printf("\n");
		i++;
	}


}


