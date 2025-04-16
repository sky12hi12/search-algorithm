#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000 // 配列のサイズ 

int main(void)
{
    int a[ARRAY_SIZE] = {}; 
    int left = 0; /* 探索範囲の左端のインデックス */
    int right = ARRAY_SIZE; /* 探索範囲の右端のインデックス */
    int mid; /* 探索範囲中央のインデックス */
    int value; /* 探したい値 */

    for (int i = 0; i < ARRAY_SIZE; i++){
        //a[i] = i + 1;
        if(i ==0){
            a[i] = rand() % 10;
        }else{
            a[i] = a[i-1] + rand() % 20 + 1;
        }
    }

    for(int i=0;i<ARRAY_SIZE;i++){
        printf("%d ", a[i]);
    }
    
    puts("探したい値は?");
    scanf("%d", &value);

    while(left <= right) {
        mid = (left + right) / 2; 
        if (a[mid] == value) {
            printf("%dは%d番目にあります。\n",value,mid+1);
            return 0;
        } else if (a[mid] < value) {
            left = mid + 1; //探索範囲を中央のインデックスの１つ右からにする
        } else {
            right = mid - 1; //探索範囲を中央のインデックスの1つ左までにする
        }
    }
    printf("見つかりません\n");
    return 0;
}