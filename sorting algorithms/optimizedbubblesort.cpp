#include<iostream>
#include<limits.h>
#include<algorithm>
// #include<bits/stdc++.h>
using namespace std;

//if the array is already sorted it will take n time
//if the array is not sorted it will take n^2 time

void bubblesort(int array[],int size){
   
    for(int i=1;i<size;i++){
        int sort_checker=0;
        for(int j=0;j<size-1;j++){
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
                sort_checker++;
            }

        }
        if(sort_checker==0){
            break;
        }
    }
    }
int main(){
    int a[5]={1,2,9,7,6};
    int s=5;
    bubblesort(a,s);
    for(int i=0;i<5;i++){
        cout<<a[i];
    }
}

// sort(array,array+5);
//     for(int i=0;i<5;i++){
//         cout<<array[i];
//     }
// }