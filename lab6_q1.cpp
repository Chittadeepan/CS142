#include<iostream>
using namespace std ;
class node{
public:
 //data
 int data;
 //ptr
 node*left;
 node*right;
 //ctor
 node(int value){
   left=NULL;
   right=NULL;
   data=value;
   }
};
  class BiST{
    public :
      node*root;
      BiST(){
          root=NULL;
        }
      void insert(int value){
             insertHelper(root,value);
        }
      void insertHelper(node*current,int value){
           
           //Base case if root is NULL
           
             if(root==NULL){
               root=new node(value);
               
             } 
             //else compare the curr data with value
             else if(value<(current->data)){
             //if value<curr-> data ,then
             //if left is null,insert there
                if(current->left==NULL){
                  current->left=new node(value);
                }
             // else move left and call insertH
                else{
                      insertHelper(current->left,value);
                }
             }
             else{
             //if right is NULL ,inset there
                  if(current->right==NULL){
                      current->right=new node(value);
                    }
             // else move right and call insertH
                  else{
                       insertHelper(current->right,value);
                    }
                 }
         }    
      void display(){
             display2(root);
         }
      void display2(node*current){
            //base condition
             if(current==NULL){
              
               return ;
            }
            //move to left child
             display2(current->left);
            //display 
             cout<<current->data<<"->";
            //move to right child 
             display2(current->right);
          }
       node*search(int value){
              return search2(root,value);
          }      
       node*search2(node*current,int value){
            //if reached end of tree or value found 
              if(current==NULL || current->data==value){
                  return current;
              }
              else if(value<current->data){
                  return search2(current->left,value);
              }
              else{
                  return search2(current->right,value);
              }
          }
          
            
          
          
        void delet(){};
          
        void height(){};      
};

int main(){
      BiST b1;node*a;int b;
      
      cout<<"Inserting numbers :";
      b1.insert(5);
      b1.insert(3);
      b1.insert(8);
      b1.insert(7);
      b1.insert(2);
      b1.display();
      a=b1.search(3);
      cout<<"\ngive the number to be searched\n";
      cin>>b;
      cout<<"The position of number "<<b<<" : "<<endl ;      
      cout<<a<<endl;
      
      return 0;
}
      
