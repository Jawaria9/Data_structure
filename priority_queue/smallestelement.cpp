#include<iostream>
#include<queue>
using namespace std;

void ksmallestelement(int *input,int size,int k){
    priority_queue<int>pq;//max priority queue
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    for(int j=k;j<size;j++){
        if(input[j]<pq.top()){
            pq.pop();
            pq.push(input[j]);
        }
    }
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }

}
int main(){
    int arr[]={1,9,8,5,3};
    ksmallestelement(arr,5,2);

}