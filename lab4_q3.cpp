#include <iostream>
#include "QueueLL.cpp"
using namespace std;
class stack{
	public:
	QueueLL q1;
	node*top;
	stack(){
  		top=NULL;
  		}
  		// no element 
	void isempty(){
  		if(top==NULL){
    		cout<<"Stack is empty."<<endl;
  			}
		}
		//push last element 
	void push(int data){
		q1.enqueue(data);
 		}
 		//CountItems 
	int size(){ 
		q1.size();
		}
	void pop(){
	    int arr[100];
	    //dequeue from front till NULL 
	    arr[0]=q1.dequeue();
	    arr[1]=q1.dequeue();
	    arr[2]=q1.dequeue();
	   //enqueue till Last-1 element 
	    q1.enqueue(arr[0]);
	    q1.enqueue(arr[1]);
		} 
	void display(){
  		q1.display();
  		}
	void tops(){
	    int arr[100];
	    //dequeue 1st element
	    arr[0]=q1.dequeue();
	    q1.top();
		}
  };
int main(){
	stack s1;
	s1.isempty();
	cout<<"Pushing elements:"<<endl;
	for(int i=0;i<3;i++){ 
		s1.push(i);
		s1.display();
	}
	s1.size();
	s1.pop();
	cout<<"Displaying elements after one pop:"<<endl;
	s1.display();
	s1.size();
	s1.tops();
	return 0;
}
	
