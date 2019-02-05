#include <iostream>
#include "linkedlist3.cpp"
using namespace std;

class StackLL{
public:
node*top;
linkedlist l1;
StackLL(){
  top=NULL;
  }
  //pushes on top
  void push(int data){
  //void insertAt(pos,value) 
  l1.insert(data);
  // top=current head;
  top=l1.head;
  }
  //pops the top
  void pop(){
  // void deleteAt(int pos)
  l1.del();
  // top=current head;
  top=l1.head;
  }
  bool isempty(){
  if(top==NULL){
  cout<<"Stack is empty."<<endl;
  return true;
  }
  else{
     return false;
      }
  }
  
  int size() {
  	int counter=0;
	//store head in current
	node*current =top;
	//counting number of elements
	while(current->next!=NULL){
		counter++;current=current->next;
	}
	cout<<"it contains "<< counter+1<<" number of elements."<<endl;
	return counter;

  }
 
   void tops(){
     node*current =top;
     while(current->next!=NULL){
		current=current->next;
	}
   cout<<"Top ="<<current->data<<endl;
 }
  
  void display(){
  l1.display();
  }
  };
	int main(){
  
  StackLL s1;
  s1.isempty();
  cout<<"pushing elements:"<<endl ;
   for(int i=0 ; i <5; i++){
   s1.push(i);
   
   s1.display();
   }
   s1.size();
   s1.pop();
 
   s1.display();
   s1.size();
   s1.tops();
   return 0;
   
  }
  
