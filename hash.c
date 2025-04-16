#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000
#define BUCKET_SIZE 1000
#define DELTA 3

int main(){
    int data[ARRAY_SIZE] = {};
    int table[BUCKET_SIZE];
    int value;
    int index;

    //データの作成
    for(int i = 0;i < ARRAY_SIZE;i++){
        data[i] = rand() % 2000 + 1; 
        /*if(i == 0){
            data[i] = rand() % 10;
        }else{
            data[i] = data[i-1] + rand() % 50 + 1;
        }*/
    }

    for(int i = 0;i < BUCKET_SIZE;i++){
        table[i] = -1;
    }

    //ハッシュテーブルの作成
    for(int i = 0;i < ARRAY_SIZE;i++){
        index = data[i] % BUCKET_SIZE;
        while(table[index] != -1){
            index += DELTA;
            if(index >= BUCKET_SIZE){
                index -= BUCKET_SIZE;
            }
        }
        table[index] = data[i];  
    }
    
    for(int i = 0;i < BUCKET_SIZE;i++){
        printf("%d ", table[i]);
    }

    //探す
    printf("探したい値は？");
    scanf("%d", &value);
    int mod = value % BUCKET_SIZE;
    int round = 0;
    while(1){
        round ++;
        if(table[mod] == value){
            printf("%dは%d番目にあります\n", value, mod + 1);
            break;
        }else{
            mod += DELTA;
            if(mod >= BUCKET_SIZE){
                mod -= BUCKET_SIZE;
            }
        }
        
        if(round == BUCKET_SIZE * 10){
            printf("見つかりません\n");
            break;
        }
    }

}