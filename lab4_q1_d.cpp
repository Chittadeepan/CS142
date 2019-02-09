#include<iostream>
using namespace std;

class queuearr{
	public:
	int enqueue(int value,int top,int arr[100],int pos){
	//enqueing elements greater than size of arr
	if(pos>top){
		cout<<"queue doesn't contain that many elements\n";
		return NULL;
	    }
	//enqueing elements
	else{
	//enqueing last element 
		arr[pos]=value;
		pos++;
		
		return pos;
		}
	}
	
	int dequeue(int i){
		i++;
		return i;
	}
	//no elements 
	void isempty(int top){
		if(top==0){
			cout<<"Queue is empty."<<endl;
		}
	}
	//CountItems 
	void size(int count,int a){
		int counter=0;
		for(int k=a;k<count;k++){
			counter++;
		}
		cout<<"the no. of elements="<<counter<<endl;
	}
};
int main(){
	queuearr q1;
	int arr[100], size,value,top=0,pos,a,count,i=0;
	// ask user
	cout<<"give the size of the queue."<<endl;
	cin>>size;
	q1.isempty(top);
     //enqueing elements
    
	cout<<"Give the  elements(enqueue) and their positions."<<endl;
	 for(int i=0;i<size;i++){
	cin>>value>>pos;
	

	count=q1.enqueue(value,size,arr,pos);
	}
	cout<<"Displaying the elements:"<<endl;
	for(int j=0;j<count;j++){
		
		cout<<arr[j]<<"->";
		
	}
	cout<<"NULL"<<endl;
	//storing index after dequeued element in a
	a=q1.dequeue(i);
	//display 
	cout<<"Displaying the elements after dequeue:"<<endl;
	for(int j=a;j<count;j++){
		
		cout<<arr[j]<<"->";
	}
	cout<<"NULL"<<endl;
	q1.size(count,a);
	
return 0;
}


