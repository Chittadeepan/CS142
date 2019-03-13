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
             //if value>current->data
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
          cout<<"Displying the numbers :\n";
          
	    cout<<"PRE ORDER TRAVERSAL : "<<endl;
            displayPreorder(root);
            
	    cout<<"\nIN ORDER TRAVERSAL : "<<endl;
            displayInorder(root);
            
	    cout<<"\nPOST ORDER TRAVERSAL : "<<endl;
            displayPostorder(root);
          }
      //inorder traversal
      void displayInorder(node*current){
            //base condition
            if(current==NULL){
              
              return ;
            }
            
            
            //move to left child
            displayInorder(current->left);
            //display
            cout<<current->data<<"->";
            //move to right child 
            displayInorder(current->right);
	      
          }
      void displayPreorder(node*current){
            //base condition
            if(current==NULL){
              
              return ;
            }
            //display
            cout<<current->data<<"->";
            
            //move to left child
            displayPreorder(current->left);
            
            //move to right child 
            displayPreorder(current->right);
	      
          }
      void displayPostorder(node*current){
            //base condition
            if(current==NULL){
              
              return ;
            }
           
            
            //move to left child
            displayPostorder(current->left);
            
            //move to right child 
            displayPostorder(current->right);

            //display
            cout<<current->data<<"->";
	      
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
       
      void FancyInsert(node*root,int space){
       
       //base case
               if(root==NULL){
                   return ;
               }
      
      //increase distance between levels
               space=space+10;
      //process right child first 
               FancyInsert(root->right,space);
      //print current node after space
      //cout<<endl;
     	    for(int i=10;i<space;i++){
      	       cout<<" ";
               }
               cout<<root->data<<endl;
        //process left child
               FancyInsert(root->left,space);
      
          }
      void FancyInsertHelper(){
        //base case with space 0
               FancyInsert(root,0);
          }     
};

int main(){
      BiST b1;node*a;int b;
      
      cout<<"Inserting numbers : "<<endl;
      b1.insert(5);
      b1.insert(3);
      b1.insert(8);
      b1.insert(7);
      b1.insert(2);
      b1.display();
      
      
      cout<<"\nGive the number to be searched.\n";
      cin>>b;
      a=b1.search(b);
      cout<<"The position(an address of a pointer) of number "<<b<<" : "<<endl ;      
      cout<<a<<endl;
      cout<<"Fancy Insert :\n ";
      b1.FancyInsertHelper();

      return 0;
}
      
