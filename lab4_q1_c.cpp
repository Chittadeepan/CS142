#include<iostream>
using namespace std;

class stackarr{
	public:
	int push(int value,int top,int arr[100],int pos){
		if(pos>top){
			//pushing elements greater than size of arr
		cout<<"stack doesn't contain that many elements\n";
		return NULL ;
		}
		//pushing elements
		else{
		arr[pos]=value;
		pos++;
		
		
		return pos;
		}	
	}
	//decrease size of arr to be printed 
	int pop(int count){
		count--;
		return count;
	}
	//no elements 
	void isempty(int top){
		if(top==0){
			cout<<"Stack is empty."<<endl;
		}
	}
	//CountItems 
	void size(int count){
	
		cout<<"the no. of elements="<<count<<endl;
	}
};
int main(){
	stackarr s1;
	int arr[100], pos,size,value,top=0,a,count;
	cout<<"give the size of the stack"<<endl;
	cin>>size;
	s1.isempty(top);
	cout<<"give the  elements(push) and their positions."<<endl;
	for(int i=0;i<size;i++){
	cin>>value>>pos;
    //push 
	count=s1.push(value,size,arr,pos);
	}
	
	cout<<"Displaying the elements:"<<endl;
	for(int j=0;j<count;j++){
		
		cout<<arr[j]<<"->";
	}
	cout<<"NULL"<<endl;
	a=s1.pop(count);
	cout<<"Displaying the elements after pop:"<<endl;
	for(int j=0;j<a;j++){
		
		cout<<arr[j]<<"->";
	}
	cout<<"NULL"<<endl;
	s1.size(a);
	
return 0;
}


