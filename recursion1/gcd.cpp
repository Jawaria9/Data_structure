#include<iostream>
using namespace std;

int gcdfind(int m,int n){
    if(m==1  || n==1){
        return 1;
    }
    int gcd=gcdfind(m-1,n-1);
        for(int i=gcd;i<=m;i++){
            if(m%i==0  && n%i==0){
                if(i>gcd){
                    return i;
                }
                }
            }  
            return gcd; 
        }
    
int main(){
    cout<<gcdfind(30,45);
}