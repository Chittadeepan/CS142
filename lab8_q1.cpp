#include<iostream>
using namespace std ;
class node{
public:
 //data
 int data;
 //ptr
 node*left;
 node*right;
 node*parent;
 //ctor
 node(int value){
   left=NULL;
   parent=NULL; 
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
                  current->left->parent=current;
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
            cout<<endl;
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
      void size(){
               cout<<"size :"<<count(root,0)<<endl;
         
          }    
            
        
          
      int count(node*current,int counter){
              int a,b;
        
		
         
              if(current==NULL){
                    return counter;           
              }
              else{
          
                    counter++;
                    a=count(current->left,counter);
              }
         
        
              b= count(current->right,a);  
      
              return b;
        
       
          }     
               
       void RangeSearch(int k,int l){
              find_range(root,k,l);
          }
       void find_range(node*current,int k,int l){
              if(current==NULL){
              
              
                     return ;
              }
            
            
            //move to left child
              find_range(current->left,k,l);
            //display
              if((current->data)>k && (current->data)<l){            
                     cout<<current->data<<",";
              }
            //move to right child 
              find_range(current->right,k,l);
	      
          }
       void height(){
                 cout<<"height of the tree :"<<height2(root,0)<<endl;
       
           }
      
       int height2(node*current,int counter){
        
		if(current==NULL){
		       return counter;
		}
		else{
		       int left=height2(current->left,counter+1);
		       int right=height2(current->right,counter+1);
		       if(left>=right){
			         return left;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
			 }
			 else{
			         return right;
			 }
		}
	
      }
 };
int main(){
      BiST b1;node*a,*c;int b,d;
      
      cout<<"Inserting numbers : "<<endl;
      b1.insert(5);
      b1.insert(3);
      b1.insert(8);
      b1.insert(7);
      b1.insert(2);
      b1.insert(4);
      b1.insert(9);
	b1.insert(1);
	b1.insert(6);
      b1.display();
      b1.size();
      cout<<"give 2 numbers.\n";
      cin>>b>>d;
      cout <<"Range of numbers between  "<<b<<" and "<<d<<" :\n";
      b1.RangeSearch(b,d);
      cout<<endl;
      b1.height();
}