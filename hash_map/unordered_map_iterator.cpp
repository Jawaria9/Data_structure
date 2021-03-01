#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>

int main(){
    unordered_map<string,int>mymap;
    mymap["abc1"]=1;
    // mymap["abc2"]=2;
    // mymap["abc3"]=3;
    // mymap["abc4"]=4;
    // mymap["abc5"]=5;//we will get random values instead of in order we inserted 

    // unordered_map<string,int>::iterator it;
    // for(it=mymap.begin();it!=mymap.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    //here we can use auto
    //auto a=3;
    //auto b="javeria";
    unordered_map<string,int>::iterator it=mymap.find("abc1");
    //find function will return an iterator to the key
    //count function returns 0 or 1
    //erase function can either take key or iterator  
    //erase function can take begin() and end() this is for maps  and vectors not for unorder maps and it delete whiole map
    if(it==mymap.end()){
        cout<<"element not present"<<endl;
    }
    else{
        cout<<"element present";
    }
    mymap.erase(it);

    if(mymap.find("abc1")==mymap.end()){
        cout<<"element not present"<<endl;
    }
    else{
        cout<<"element present";
    }




}