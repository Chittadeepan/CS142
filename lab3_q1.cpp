#include <iostream>
using namespace std;



class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    Node * prev;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    Node * head;
    DLL(){
        head = NULL;
    }
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ 
	// If not empty list. 
            Node * current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = temp;
            temp->prev = current;    
        }
    }
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout <<"NULL"<<endl;
        cout << "Print in R order : ";
        while(last!=NULL){
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout <<"NULL"<<endl;   
    }
void Countitems(){
	int counter=0;
	//store head in current
	Node*current =head;
	//counting number of elements
	while(current->next!=NULL){
		counter++;current=current->next;
	}
	cout<<"It contains "<< counter+1<<" number of elements."<<endl;

}
    void insertAt(int pos, int data){
        //reach the place before the pos
    
   //create a node
      	Node*temp=new Node(3);
        Node*current =head;
      int counter=0;
	while(current->next->next!=NULL){
		counter++;current=current->next;
	}
	
        if(pos>counter){
		cout<<"Linked list does not have that many elements.\n";
		}
	current=head;
	if(pos!=1) { 
        for(int i=1;i<pos-1;i++){
	
        current =current->next ;
          }
   
        //move ptrs
      temp->next=current->next;
	
	//temp->next=current->prev->next;
	temp->prev=current;
	//update temp
	current->next=temp;
	current->next->next->prev=temp;
        }
       else{
      temp->prev = NULL;
		temp->next=head;
		head->prev=temp;
		//update head
		head= temp ; 
	//temp->next = head;
	//temp->prev=NULL;
         
	 
	//head=temp;
	
       } 
      temp->data=data;
      

    }
    void DeleteAt(int pos){
        //reach the place before the pos
    	Node*prev=NULL;
  	Node*temp=head;
       
	if(pos!=1) { 
      
        for(int i=1;i<pos;i++){
        temp =temp->next ;
          }
	//move ptrs
      temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	
        }
       else{
         
	head->next->prev=NULL;
	head=head->next;
         
     } 
	
    }
    void Del(){
        // Deletes the last element.
	

  //before tail pts NULL 
  Node*current =head ;
  while (current->next->next!=NULL){
    current=current->next;
    }
	//store tail in temp
    Node*temp=current->next;
	//update tail;
	current->next= NULL ;
    
   
    //delete temp
    delete temp;
    
	
    }
    

};

int main(){
    DLL dll1;
    for(int i= 1; i < 5; i++){
        dll1.insert(i);
    }
    dll1.display();
	
	dll1.Countitems();
	dll1.insertAt(2,5);
	dll1.display();
	dll1.insertAt(1,9);
	dll1.display();
	
	dll1.Del();
	dll1.display();
	dll1.DeleteAt(2);
	dll1.display();
	dll1.DeleteAt(1);
	dll1.display();
	dll1.Countitems();
	dll1.insertAt(8,4);
}


