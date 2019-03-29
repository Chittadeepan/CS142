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
                      current->right->parent=current;
                    }
             // else move right and call insertH
                  else{
                       insertHelper(current->right,value);
                    }
                 }
          }
      void display(){
          cout<<"Displaying the numbers :\n";

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
      //find min of a tree in a recursive way

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
      // find max of a tree in a recursive way
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

             if(current->parent->left==current){
               current->parent->left=temp;
             }
             else if(current->parent->right==current){
               current->parent->right=temp;


             }


           }
//swapping data
       void value_replace(node*first, node*second){
              int data=first->data;
              first->data=second->data ;
              second->data=data ;
             }
          //delete node
       void delete_node(int value){
       //no elements
              if(search(value)==NULL){

                cout<<"The number "<<value<<" is not present in the tree."<<endl;
                return;
                }
              else{
                node*current=search(value);
                node*temp;
                 //middle node has left child
                if(current->left!=NULL){
                      
                      temp=find_max(current->left);
                      value_replace(current,temp);
                // if max of sub tree has left child,then rev link 
                      if(temp->left!=NULL){
                             temp->left->parent=temp->parent;
                      }
                             //if current-left has right child 
                      if(current->left->right!= NULL){
                             temp->parent->right=temp->left;
                      }
                      
                             
                      else{
                             temp->parent->left=temp->left;
                      }

 		         delete temp ;
 		         return;
                 }
                   //middle node has right child
                else if(current->right!=NULL){

                       
                       temp=find_min2(current->right);
                       value_replace(current,temp);
                // if min of sub tree has right child,then rev link 
                       if(temp->right!=NULL){
                             temp->right->parent=temp->parent;
                       }
                    //if current-right has left child            
                       if(current->right->left!= NULL){
                             temp->parent->left=temp->right;
                       }
                       
                                
                       else{
                       //if temp- data==current-data
                             if(temp->data!=current->data){
                                   temp->parent->right=temp->right;
                             }
                             else{
                                    temp->parent->left=temp->right;
                             }
                       }
                        delete temp ;
                        return;
                }

		       //only root in the tree

                 if((current==root)&&(current->left==NULL)&&(current->right==NULL)){


                    root=NULL ;
                    return;

                 }
                 //delete leaf node
                 else {
                      if(current->parent->left==current){

                         replace_at_parent(current, current->left);
                      }
                      else if(current->parent->right==current){
                         replace_at_parent(current,current->right);
                      }
                 }
             }

         }

        void deletenode(int value){
          cout<<"Deleting "<<value<<" from the tree :"<<endl;
          delete_node(value);
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

     
      cout<<"Finding the address  of minimum of the tree :"<<endl ;
      c=b1.find_min();
      cout<<c<<endl;
      

      b1.deletenode(8);
      b1.display();
      b1.deletenode(6);
      b1.display();
      b1.deletenode(7);
      b1.display();

      b1.deletenode(9);
      b1.display();
      b1.deletenode(2);
      b1.display();
      b1.deletenode(1);
      b1.display();
   
      b1.deletenode(3);
      b1.display();
     
      b1.deletenode(4);
      b1.display();

      b1.deletenode(5);
      

      b1.display();
      b1.deletenode(10);
      b1.display();
      
      return 0;
}
