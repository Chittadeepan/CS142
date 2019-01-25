#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    Node * head;
    CSLL(){
        head = NULL;
    }
    // Inserts to the end of the linked list.
   void insert(int value){
        
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
        temp->next = head;
    }
    // Displays the linked list.
  void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){ // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
       
        cout << current -> data;
         
        cout << endl;
    }
  void InsertAt(int pos, int value){
         //reach the place before the pos
         
   //create a node
      Node*temp=new Node(3);
        
        Node*current =head;
      int counter=0;
	while(current->next!=head){
		counter++;current=current->next;
	}
	
        if(pos>counter+1){
		cout<<"Linked list does not have that many elements.\n";
		return;
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
       for(int i=1;i<counter+1;i++){
        current =current->next ;
        }
         temp->next=head;
        head=temp;
        current->next =head;
       } 
      temp->data=value;
      
    }
  void DeleteAt(int pos){
    	//reach the place before the pos
    	
  	Node*temp=head;
        Node*current =head;
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
       
        delete current;
        }
       else{
     
              int counter=0;
	while(current->next!=head){
		counter++;current=current->next;
	}        
	 head=head->next;
         current->next =head;
         
       } 
        
    }
    void Delet(){
        // Deletes the last element.
       
        // Deletes the last element.
	

  //before tail pts NULL 
  Node*current =head ;
  while (current->next->next!=head){
    current=current->next;
    }
	//store tail in temp
    Node*temp=current->next;
	//update tail;
	
	current->next= head;
    
   
    //delete temp
    delete temp;
    }
  void CountItems(){
        // Counts the Number of items.
        int counter=0;
	//store head in current
	Node*current =head;
	//counting number of elements
	while(head!=current->next){
		counter++;current=current->next;
	}
	cout<<"It contains "<< counter+1<<" number of elements."<<endl;

    }

};

int main(){
    CSLL csll1;
    for(int i= 1; i < 11; i++){
       csll1.insert(i);
    }
    
   csll1.display();
   csll1.CountItems();
   csll1.InsertAt(3,5);
   csll1.display();
   csll1.InsertAt(1,0);
   csll1.display();
   csll1.Delet();
   csll1.display();
   csll1.DeleteAt(3);
   csll1.display();
   csll1.DeleteAt(1);
   csll1.display();
   csll1.CountItems();
   csll1.InsertAt(16,5);
   return 0;
}