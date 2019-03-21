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
      //find min 
      
      node*find_min(){
              find_min2(root);
        
          }  
          
      node*find_min2(node*current){
             if(current->left==NULL){
                  
                  return current;
             } 
             else{
               current=current->left;
               find_min2(current);
             }     
        
        
          }
          // find max
      node*find_max(node*current){
             if(current->right==NULL){
                  
                  return current;
             } 
             else{
               current=current->right;
               find_max(current);
             }     
        
        
          }
          
        //replace child node with parent node
      void replace_at_parent(node*current, node*temp){
           // if(current->parent->left==current){
              if(current->left!= NULL){
               current->parent->left=temp;
                             }
              else{
               current->parent->right=temp;
                 
               delete current ;
              }
            // else if((current->parent->right)==current){
            // if(current->left!= NULL){
             // (current->parent->right)=current->left;
              
            //}
            // else{
             // (current->parent->right)=current->right;
           // }
            
          }
//swapping data
       void value_replace(node*first, node*current){
                node*temp;
                temp->data=first->data;
                first->data=current->data ;
                current->data=temp->data ;
          }
          //delete node
       void deletenode(int value){
           if(search(value)==NULL){
                
                cout<<"The number "<<value<<" is not present in the tree."<<endl;
                }
           else{
                node*current=search(value);
                
                
                node*temp;
                
             
                      // replace_at_parent(current, current->right);
              //  }
                if(current->left!=NULL){
                  
                      temp=find_max(current);
                      
                      value_replace(current,temp);
                      if(current->left->right!= NULL){
 				     temp->parent->right=temp->left;
                     }
                     else{
                       
                         temp->parent->left=temp->left;
                      }
 			
 				     delete temp ;
                       }
			else if(current->right!=NULL){
			       temp=find_min2(current->right);
			       
 				  value_replace(current,temp);
 				  if(current->right->left!= NULL){
 				     temp->parent->left=temp->right;
 				     }
 				     else{
 				      temp->parent->right=temp->right; 
                       }
 				     delete temp ;
                       }
				
		       
		  
                         if((current==root)&&(current->left==NULL)&&(current->right==NULL)){
                       
                       
                       root=NULL ;
                 
                       //if(root->left!=NULL && root->right!= NULL)//{
                                //temp=find_min2(current->right);   
                             //   value_replace(current, temp);
                               // delete temp;
                      // }
                      // else{
        
                                //temp=find_min2(current->left);
                            //    replace_at_parent(current,temp);
                      // }
               // }
           }
                  else {
                    if(current->parent->left==current){
                      current->parent->left=current->left;
                    }
                   else if(current->parent->right==current){
                      current->parent->right=current->right ;
                    }
                  }
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
      
      
      cout<<"\nGive the number to be searched.\n";
      cin>>b;
      a=b1.search(b);
      cout<<"The position(an address of a pointer) of number "<<b<<" : "<<endl ;      
      cout<<a<<endl;
      cout<<"Fancy Insert :\n ";
      b1.FancyInsertHelper();
      cout<<"Finding the address  of minimum :"<<endl ;
      c=b1.find_min();
      cout<<c<<endl;
    // a=b1.search(8);
     //cout<<a;
    
     b1.deletenode(10);
      b1.display();
      
      return 0;
}
   
   
