#include<iostream>
#include<queue>
using namespace std;

void ksorted(int *input,int size,int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
       pq.push(input[i]);
    }
    int start=0;
    for(int i=k;i<size;i++){
        input[start]=pq.top();
        pq.pop();
        start++;
        pq.push(input[i]);
    }
    while(!pq.empty()){
        input[start]=pq.top();
        pq.pop();
        start++;
    }
}
int main(){
    int arr[]={1,9,8,5,3};
    ksorted(arr,5,2);
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
}