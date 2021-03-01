#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>

int main(){
    map<string,int>mymap;
    mymap["abc1"]=1;
    mymap["abc2"]=3;
    mymap["abc3"]=2;
    mymap["abc4"]=5;
    mymap["abc5"]=4;//we will get the values in order we inserted in keys

    map<string,int>::iterator it;
    for(it=mymap.begin();it!=mymap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}