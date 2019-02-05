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
class QueueLL{
public:
//head +circles linked with each other

//head->node type ptr
node*head;
node*tail;
//ctor
QueueLL(){
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
    

void enqueue(int data){
  //last element 
   insert(data);
 }
void isempty(){
//no element 
  if(head==NULL){
    cout<<"Queue is empty."<<endl;
  }
  
}
void delAt(int );
int size();

void dequeue(){
  delAt(1);
 
 } 
 void top(){
    //front element 
   cout<<"Top ="<<head->data<<endl;
 }
};
void QueueLL::delAt(int pos){
       
       //del head
         head=head->next;
         
        
}
int QueueLL::size(){
	int counter=0;
	//store head in current
	node*current =head;
	//counting number of elements
	while(current->next!=NULL){
		counter++;current=current->next;
	}
	cout<<"it contains "<< counter+1<<" number of elements."<<endl;
	return counter;
}

int main(){
  QueueLL q1;
  q1.isempty();
  cout<<"enqueing elements"<<endl;
  q1.enqueue(1);
  q1.display();

  q1.enqueue(2);
  q1.display();
  q1.top();
  q1.size();
  q1.dequeue();
  q1.display();
  q1.size();
  q1.top();
}
