#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> children;
    treenode(){

    }
    treenode(T data){
      this->data=data;
    }
    ~treenode(){//this is recursive distructor
    //delete key ord everytime calls the distructor
      for(int i=0;i<children.size();i++){
        delete children[i];
      }
    }

};
void printtree(treenode<int>*root){
    if(root==NULL)
      return;
    cout<<root->data<<": ";

        
    for(int i=0;i<root->children.size();i++){
      cout<<root->children[i]->data<<" ";
    }

        cout<<endl;
    
    for(int i=0;i<root->children.size();i++){
    printtree(root->children[i]);

    }
  }

treenode<int>* inputdata(){
  int data ,childs;
  cout<<"enter the data"<<endl;
  cin>>data;
  treenode<int>*root=new treenode<int>(data);
  cout<<"enter the number of childrens"<<endl;
  cin>>childs;
  for(int i=0;i<childs;i++){

    treenode<int>*children=inputdata();
    root->children.push_back(children);

  }
  return root;

}
treenode<int>* takeinput_iteratively(){
  int rootdata;
  int childdata,n;
  queue<treenode<int>*> q;
  cout<<"enter the root data"<<endl;
  cin>>rootdata;
  treenode<int>*rootnode=new treenode<int>(rootdata);
  q.push(rootnode);

  while(!q.empty()){
    treenode<int>*frontnode=q.front();
    q.pop();
    cout<<"enter the no of childrens of "<<frontnode<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
      cout<<"enter the data of "<<i<<" child of "<<frontnode;
      cin>>childdata;
      treenode<int>*childrennode=new treenode<int>(childdata);
      q.push(childrennode);
      frontnode->children.push_back(childrennode);
    }
  }
}
void printtreeiteratively(treenode<int>*root){
  queue<treenode<int>*> q;
  q.push(root);
  while(!q.empty()){
    treenode<int>*front=q.front();
    q.pop();
    cout<<front->data<<":";
    for(int i=0;i<front->children.size();i++){
      cout<<front->children[i]->data;
      q.push(front->children[i]);
    }
    cout<<endl;

  }
}
int countnodesiteratively(treenode<int>*root){
  queue<treenode<int>*> q;
  q.push(root);
  int count=0;

  while(!q.empty()){
    treenode<int>*front=q.front();
    q.pop();
    count++;
    for(int i=0;i<front->children.size();i++){
      q.push(front->children[i]);
    }
  }
  return count;

}
int countnodesrecursively(treenode<int>*root){
  int count=1;
  if(root==NULL){//edge case
    return 0;
  }
  for(int i=0;i<root->children.size();i++){
  count=count+countnodesrecursively(root->children[i]);
  }
  return count;



}
int heightoftreerecursively(treenode<int>*root){
  if(root==NULL){
    return 0;
  }
  int mx=0;
  for(int i=0;i<root->children.size();i++){
    //int newmx=heightoftreerecursively(root->children[i]);
    //if(newmx>mx)
    //mx=newmx
    mx=max(mx,heightoftreerecursively(root->children[i]));
  }
  return mx+1;

}
void printallnodeatdepthk(treenode<int>*root,int k){
  if(root==NULL){
    return;
  }
  if(k==0){
    cout<<root->data;
    return;
  }
  for(int i=0;i<root->children.size();i++){
  printallnodeatdepthk(root->children[i],k-1);
  }


}
void printallnodeatdepthk_secondapproach(treenode<int>*root,int k,int level){
  if(root==NULL){
    return;
  }
  if(k==level){
    cout<<root->data;
    return;
  }
  for(int i=0;i<root->children.size();i++){
  printallnodeatdepthk_secondapproach(root->children[i],k,level+1);
  }
}
int countnoofleafnodes(treenode<int>*root){
  int ans=0;
  if(root==NULL){//edge case
    return 0;
  }
  if(root->children.size()==0){//base case
    return 1;
  }
  for(int i=0;i<root->children.size();i++){
    ans+=countnoofleafnodes(root->children[i]);
  }
  return ans;
}
void countnoofleafnodes_secondapproach(treenode<int>*root,int &ans){
  if(root==NULL){//edge case
    return;
  }
  if(root->children.size()==0){//base case
    ans++;
    return;
  }
  for(int i=0;i<root->children.size();i++){
    countnoofleafnodes_secondapproach(root->children[i],ans);
  }
}
void print_postordertraversal(treenode<int>*root){
  if(root==NULL){
    return;
  }
  for(int i=0;i<root->children.size();i++){
    print_postordertraversal(root->children[i]);
  }
  cout<<root->data;

}
void print_preordertraversal(treenode<int>*root){
  if(root==NULL){
    return;
  }
  cout<<root->data;
  for(int i=0;i<root->children.size();i++){
    print_postordertraversal(root->children[i]);
  }
}
void deletetree(treenode<int>*root){
  if(root==NULL){
    return;
  }
  for(int i=0;i<root->children.size();i++){
    deletetree(root->children[i]);
  }
  delete root;

}







int main(){
    // treenode<int>*root=new treenode<int>(1);
    // treenode<int>*n1=new treenode<int>(1);
    // treenode<int>*n2=new treenode<int>(1);
    // treenode<int>*n3;

    // root->children.push_back(n1);
    // root->children.push_back(n2);
    // n2->children.push_back(n3);


    treenode<int>*root=inputdata();
   // printtree(root);
    //cout<<countnodesiteratively(root);
    //cout<<countnodesrecursively(root);
    //cout<<heightoftreerecursively(root);
    //printallnodeatdepthk_secondapproach(root,1,0);
    
    // int ans=0;
    // countnoofleafnodes_secondapproach(root,ans);
    // cout<<ans;




}