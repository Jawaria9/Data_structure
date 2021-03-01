#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>

vector<int> removing_duplicates(int *arr,int n){
    unordered_map<int,bool>mymap;
    vector<int>v;
    for(int i=0;i<n;i++){
        if(mymap.count(arr[i])==0){
            mymap[arr[i]]=true;
            v.push_back(arr[i]);
        }
    }
    return v;
}
int main(){
    int array[]={1,5,2,4,4,3,3,6,7,1,1,2};
    vector<int>output;
    output=removing_duplicates(array,12);
    for(int i=0;i<output.size();i++){
        cout<<output[i];
    }


}