#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>

int main(){
    unordered_map<string,int>mymap;
    mymap["abc1"]=1;
    mymap["abc2"]=2;
    mymap["abc3"]=3;
    mymap["abc4"]=4;
    mymap["abc5"]=5;

    unordered_map<string,int>::iterator it;
    for(it=mymap.begin();it!=mymap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}