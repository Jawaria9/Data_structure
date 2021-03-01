#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

string remove_duplicates(string str){
    stack<char> s;
    string ans=" ";
    for(int i=0;i<str.size();i++){
        if(s.empty() || str[i]!=s.top()){
            s.push(str[i]);
        }
        else{
            s.pop();
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
         s.pop();
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()==0){
        return 0;
    }
    else{
    return ans;
    }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                __________________________________________________________________
_


int main(){
    string s="mittsissisims";
    cout<<remove_duplicates(s);
}
