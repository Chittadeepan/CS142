#include <iostream>
#include "StackLL.cpp"
using namespace std;
class queue{
	public:
	StackLL s1;
	StackLL s2;
	node*top;
	queue(){
  		top=NULL;
  		}	
  		//no element 
	void isempty(){
  		if(top==NULL){
    		cout<<"Queue is empty."<<endl;
  			}
		}
	void enqueue(int data){
		s1.push(data);//pushing last element 
 		}
	int size(){ 
	//CountItems 
		s1.size();
		}
	void dequeue(){
	int arr[100];
	 //popping elements and storing them in stack 2
	   arr[0]= s1.pop();
	   
	  s2.push(arr[0]);
	   arr[1]= s1.pop();
	   s2.push(arr[1]);
	   
	   arr[2]=s1.pop();
	   s2.push(arr[2]); 
	  //pop last element 
		arr[3]=s2.pop();

		//pop elements and store in stack1
		arr[4]=s2.pop();
		s1.push(arr[4]);
		
		arr[5]=s2.pop();
		s1.push(arr[5]);
		} 
	
	void display(){
  		s1.display();
  		}
 
	void tops(){
	   int arr[100];
	 //popping elements and storing them in stack 2
	   arr[0]= s1.pop();

	   s2.push(arr[0]);
	   arr[1]= s1.pop();
	   s2.push(arr[1]);
	   s2.tops();
		}
  };
int main(){
	queue q1;
	q1.isempty();
	cout<<"Enqueing elements:"<<endl;
	for(int i=0;i<3;i++){ 
		q1.enqueue(i);
		q1.display();
	}
	q1.size();
	q1.dequeue();
	cout<<"Displaying elements after one dequeue:"<<endl;
	q1.display();
	
	q1.size();
	q1.tops();
	return 0;
}
	
