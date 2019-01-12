#include <iostream>
using namespace std;
class node{
  public:
  //data
  int data;
  //ptr to next node
  node*next;
  //ctor that makes ptr to NULL
  node(){
    next=NULL;
  }
  
};
class linkedlist{
public:
//head +circles linked with each other

//head->node type ptr
node*head;
node*tail;
//ctor
linkedlist(){
head= NULL ;
tail=NULL;
}
//circles linked with each other 
//rules to link circles 
//insert
void insert(int data){
//if 1st node is added
node*temp=new node;
//insert data in the node
temp->data=data;
//1st node only
if (head==NULL){
  head=temp;
}
//any other node only
else{
  tail->next=temp;
}
tail=temp;
}
//display
void display(){
  node*current=head;
  while(current!=NULL){
    cout<<current->data<<"->" ;   
    current=current->next;
    }
    cout<<"NULL"<<endl;
    }
    void insertAt(int pos,int data){
      //reach the place before the pos
    
   //create a node
      node*temp=new node;
        
        node*current =head;
      int counter=0;
	while(current->next!=NULL){
		counter++;current=current->next;
	}
        if(pos>counter+1){
		cout<<"linked list does not contain as many elements.\n";
		}
	current=head;
	if(pos!=1) { 
        for(int i=1;i<pos-1;i++){
        current =current->next ;
          }
        
        //move ptrs
        temp->next=current->next;
        current->next=temp;
        }
       else{
         temp->next=head;
         head=temp;
       } 
      temp->data=data;
      
    }
void del(){
  //store tail in temp
  node*temp=tail;
  //before tail pts NULL 
  node*current =head ;
  while (current->next!=tail){
    current=current->next;
    }
    current->next= NULL ;
    //update tail;
    tail=current ;
    //delete temp
    delete temp;
    
   
 }
void delAt(int );
int countitems();
	 
};
void linkedlist::delAt(int pos){
	//reach the place before the pos
    	
  	node*temp=head;
        node*current =head;
	if(pos!=1) { 
        for(int i=1;i<pos;i++){
        current =current->next ;
          
	}
	//reach the 2 places before the pos
	 
        for(int i=1;i<pos-1;i++){
        temp =temp->next ;
          }
	//move ptrs
        temp->next=current->next;
        current->next=temp;
        }
       else{
         head=head->next;
         
       } 
}
int linkedlist::countitems(){
	int counter=0;
	//store head in current
	node*current =head;
	//counting number of elements
	while(current->next!=NULL){
		counter++;current=current->next;
	}
	cout<<"it contains "<< counter<<" number of elements."<<endl;
	return counter;
}
int main(){
	linkedlist l1;
 	
	l1.insert(1);
 	l1.insert(2);
	l1.insert(3);
  	l1.display();
  	
	l1.del();
  	l1.display();
  	
	l1.del();
  	l1.display();
  	
	l1.insertAt(1,8);
  	l1.display();
  	
	l1.insertAt(2,5);
  	l1.display();
  	
	l1.insertAt(4,9);
  	l1.countitems();
	
	l1.delAt(2);
	l1.display();
	
	l1.delAt(1);
	l1.display();
return 0;
  
}

 
