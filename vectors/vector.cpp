
//vectors are used at the place of  array
//do not required size as it it double its size whenever required by itself
//vectors are declared using template
//dynamic means we will have to delete it at the end while static is deleted automatically by system
//dynamic memmory is allocated on heap while static is on stack
//push_back is the function to insert element in to vector
//we cannot insert  new value to the vector because otherwise size will not increase but we can replace value
//instead of square brackets at(index) is preferable in vectors to access element because for invalid index at() gives error
//inside the for loop ,square brackets can also be used if the loop terminates by using v.size() function
//size function return the total no. of elements while capacity returns the total capacity of vector 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    vector<int>v1(10,-2); //vector of capacity 10 and initializing it with the -2
    vector<int> v;//dynamic
    vector<int> *vp=new vector<int>();//static

    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    // v[1]=100;

    // v[3]=1000;
    // v[4]=2000;

    // v.push_back(40);
    // v.push_back(50);

    // cout<<v[0]<<'\n';
    // cout<<v[1]<<'\n';
    // cout<<v[2]<<'\n';
    // cout<<v[3]<<'\n';
    // cout<<v[4]<<'\n';
    // cout<<v[5]<<'\n';
    // cout<<v[6]<<'\n';

    // cout<<v.at(0)<<'\n';
    // cout<<v.at(6);

    // v.pop_back();
    // for(int i=0;i<v.size();i++){
    //    cout<<v[i]<<'\n';
    // }


//    for(int i=0;i<100;i++){
//        v.push_back(i+1);
//        cout<<"size:"<<v.size()<<'\n';
//        cout<<"capacity:"<<v.capacity()<<'\n';
//    }
//    for(int i=0;i<v.size();i++){
//        cout<<v.at(i)<<endl;
//    }
 

//      for(int i=0;i<v1.size();i++){
//        cout<<v1.at(i)<<endl;
//    }
   

   sort(v1.begin(),v1.end());

   

}