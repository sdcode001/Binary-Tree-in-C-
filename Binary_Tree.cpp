#include<bits/stdc++.h>
using namespace std;
//creating nodes of tree.
class Node{   //public calss.it can be usable without making friend.
public:
  int val;
  Node* left;
  Node* right;
};
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// this stack is used in iterative tree traversals.
class stack_array{
 int size=100;
 Node** data=NULL;
 int pointer=-1;
 friend class Binary_Tree;
public:
  stack_array(){
    data=new Node*[size];
  }
  ~stack_array(){delete []data;}

  void push(Node* x){
    if(pointer==size-1){}
    else{
      pointer++;
      data[pointer]=x;
    }
  }
  Node* pop(){
    Node* y;
    if(pointer==-1){}
    else{
      y=data[pointer];
      data[pointer]=NULL;
      pointer--;
      return y;}
  }
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// to use Queue data struvture in making of binary tree.
class Queue_array{
  Node** queue;
  int size=100;
  int in=-1;
  int out=-1;
  friend class Binary_Tree;
public:
  int length=0;    //number of element present in the queue.
  Queue_array(){     //size is the length of array.
    queue=new Node*[100];
    queue[0]=NULL;
  }
  ~Queue_array(){delete[]queue;}

  void cnQueue(Node* val){     //putting element into queue.
    if(in==size-1&&out==-1){cout<<"Queue overflow!!"<<endl;}
    else{
      if(in==size-1&&out!=-1){
        for(int i=out;i<in;i++){queue[i]=queue[i+1];}
        queue[in]=val;
        out--;}
      else{in++; queue[in]=val;}
      length++;
    }
  }

Node* dQueue(){    //delete element from Queue.
     Node* val;
    if(in==out){cout<<"Empty Queue!!"<<endl;}
    else{
      out++;
      val=queue[out];
      queue[out]=NULL;
      length--;
      return val;}
     }
  };
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Binary_Tree{

    Node* t=NULL;        //iterator
    Node* p=NULL;                     //pointing to root node of tree.
    int* arr=NULL;      //array of binary tree; for no node we assign array value=-1.
    int size=0;
    int total_nodes=0;
    Queue_array ptr;

public:
     Node* Root=NULL;
   Binary_Tree(int array[],int n){   //this array is filled in level-order method of tree.
     size=n;
    arr=new int[n+1];
    arr[0]=-1;
    for(int j=0;j<n;j++){arr[j+1]=array[j];}
    int x=0;
    for(int j=0;j<n;j++){if(arr[j]==-1){x++;}}
    total_nodes=size-x;
    int i=1;
    Root=new Node;
    Root->val=arr[1];
    Root->left=NULL;  Root->right=NULL;
    ptr.cnQueue(Root);
    for(int j=2;j<=n;j++){
      p=ptr.dQueue();
      if(arr[j]!=-1){
        t=new Node;
        t->val=arr[j];
        t->left=NULL; t->right=NULL;
        p->left=t;
        ptr.cnQueue(t);}
         j++;
      if(arr[j]!=-1){
        t=new Node;
        t->val=arr[j];
        t->left=NULL; t->right=NULL;
        p->right=t;
        ptr.cnQueue(t);}
       }
     }


    void preOrder_treversal(Node* ptr){   //here ptr is the starting node of tree.
      if(ptr!=NULL){
        cout<<ptr->val<<" ";
        preOrder_treversal(ptr->left);
        preOrder_treversal(ptr->right);}
     }

    void inorder_treversal(Node* ptr){
      if(ptr!=NULL){
      inorder_treversal(ptr->left);
      cout<<ptr->val<<" ";
      inorder_treversal(ptr->right);}
    }

    void levelorder_treversal(Node* ptr){
      Queue_array q;
      Node* m=NULL;
      q.cnQueue(ptr);
      for(int i=1;i<=size;i++){
          m=q.dQueue();
        if(m!=NULL){
          cout<<m->val<<" ";
          q.cnQueue(m->left);
          q.cnQueue(m->right);}}
     }

    void iterative_preorder_treversal(Node* ptr){
         Node* m=ptr;
         stack_array s;
         int c=0;
         while(true){
             if(c==total_nodes+1){break;}
             if(m!=NULL){
               cout<<m->val<<" ";
               s.push(m);
               m=m->left;
              c++;}
             else{
               m=s.pop();
               m=m->right;}}
        }

    void iterative_inorder_treversal(Node* ptr){
      stack_array s;
      Node* m=ptr;
      int c=0;
      while(true){
        if(m->left!=NULL){
          s.push(m);
          m=m->left;
          s.push(m);}
        else{
          cout<<m->val<<" ";
          c++;
          if(c==total_nodes){break;}
          if(m->right!=NULL){m=m->right;}
          else{
            m=s.pop();
            m=s.pop();
            cout<<m->val<<" ";
            m=m->right;}}}
        }

int count_nodes(Node* m){
  int x,y;
  if(m!=NULL){
    x=count_nodes(m->left);
    y=count_nodes(m->right);
    return x+y+1;
  }
  return 0;
}

int count_leafNodes(Node* m){
  int x,y;
  if(m!=NULL){
    x=count_leafNodes(m->left);
    y=count_leafNodes(m->right);
    if(x==0&&y==0){return x+y+1;}
    else{return x+y;}
  }
  return 0;
}

int count_twoDegreeNodes(Node* m){
  int x,y;
  if(m!=NULL){
    x=count_twoDegreeNodes(m->left);
    y=count_twoDegreeNodes(m->right);
    if(m->left!=NULL && m->right!=NULL){return x+y+1;}
    else{return x+y;}
  }
  return 0;
}

int count_oneDegreeNodes(Node* m){
  int x,y;
  if(m!=NULL){
    x=count_oneDegreeNodes(m->left);
    y=count_oneDegreeNodes(m->right);
    if((m->left==NULL&&m->right!=NULL)||(m->left!=NULL&&m->right==NULL)){return x+y+1;}
    else{return x+y;}
  }
  return 0;
}

int sum_Nodes(Node* m){
  int x,y;
  if(m!=NULL){
    x=sum_Nodes(m->left);
    y=sum_Nodes(m->right);
    return x+y+m->val;
  }
  return 0;
}
};
int main(){
  int list[7]={3,5,7,-1,9,-1,11};
  Binary_Tree b(list,7);
  //b.preOrder_treversal(b.Root);
  //b.inorder_treversal(b.Root);
  //b.levelorder_treversal(b.Root);
  //b.iterative_preorder_treversal(b.Root);
  //b.iterative_inorder_treversal(b.Root);
  cout<<b.sum_Nodes(b.Root);
  return 0;
}
