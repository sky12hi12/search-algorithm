#include <iostream>
using namespace std;

#define ARRAY_SIZE 1000
#define BUCKET_SIZE 1000
#define DELTA 3

int database[ARRAY_SIZE] = {};
int hashtable[BUCKET_SIZE];

//データの作成
void make_data(){
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(i == 0){
            database[i] = rand() % 50 + 1;
        }else{
            database[i] = database[i - 1] + rand() % 100;
        }
    }

    for(int i = 0; i < ARRAY_SIZE; i++){
        cout << database[i] << " ";
    }
}

//binary search
int binary_search(int value, int left, int right){
    int l,r;
    l = left; /* 探索範囲の左端のインデックス */
    r = right; /* 探索範囲の右端のインデックス */
    int mid; /* 探索範囲中央のインデックス */
    int trials = 0;
   
    while(l <= r) {
        mid = (l + r) / 2;
        trials++;
        if (database[mid] == value) {
            cout << "Binary Search: " << value << " is at " << mid  << "(number of trials: " << trials << ")" << endl; //探索回数
            return 0;
        } else if (database[mid] < value) {
            l = mid + 1; //探索範囲を中央のインデックスの１つ右からにする
        } else {
            r = mid - 1; //探索範囲を中央のインデックスの1つ左までにする
        }
    }
    cout << "Not found." << endl;
    return -1;
}

//ハッシュテーブルの作成
void make_hashtable(){
    for(int i = 0; i < BUCKET_SIZE; i++){
        hashtable[i] = -1;
    }

    for(int i = 0;i < ARRAY_SIZE;i++){
        int index = database[i] % BUCKET_SIZE;
        while(hashtable[index] != -1){
            index += DELTA;
            if(index >= BUCKET_SIZE){
                index -= BUCKET_SIZE;
            }
        }
        hashtable[index] = database[i];  
    }
}

//hash search
void hash_search(int value){
    int mod = value % BUCKET_SIZE;
    int trials = 0;
    while(1){
        trials ++;
        if(hashtable[mod] == value){
            cout << "Hash Search: " << value << " is at " << mod << "(number of trials: " << trials << ")" << endl; //探索回数
            break;
        }else{
            mod += DELTA;
            if(mod >= BUCKET_SIZE){
                mod -= BUCKET_SIZE;
            }
        }
        
        if(trials == BUCKET_SIZE * 10){
            cout << "Not found." << endl;
            break;
        }
    }
}

int main(){
    int value;
    make_data();
    make_hashtable();
    printf("\n");
    cout << "Search value?: ";
    cin >> value;
    binary_search(value, 0, ARRAY_SIZE);
    hash_search(value);

    return 0;
}