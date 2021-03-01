#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);//we will get the values in order we inserted in vector

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it;
    }
}