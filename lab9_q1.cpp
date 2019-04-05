#include<iostream>
using namespace std;

/*

2 Rules for Binary Heap
- Its a complete tree. -> So you can use an array
- Either a max-heap or min-heap. 

Array Implementation 
Root - A[0]

Parent Node : Arr[(i-1)/2]
Left Child  : Arr[(2*i)+1]
Right Child : Arr[(2*i)+2]

Functions:
1. GetMin()
2. ExtractMin()
3. DecreaseKey()
4. Insert()
5. Delete()
6. Display()

*/


class BinaryHeap{
    public:
    // Pointer to array of elements
    int * hArr;
    // Maximum possible size of array
    int mSize;
    // Current size of array 
    int cSize;

    BinaryHeap(int mSize){
        // Constructor 
        hArr = new int[mSize];
        this->mSize = mSize;
        cSize = -1;
    }

    void swap(int *a, int *b){
        // Swap elements ... 
        int temp = *a; 
        *a = *b; 
        *b = temp;
    }

    int parent(int i){ return (i-1)/2;}
    int left(int i){ return (i*2)+1;}
    int right(int i){ return (i*2)+2;}

    int getMin(){ return hArr[0]; }

    void insert(int value){
	//no elements
	if(cSize==-1){
	cout<<"The heap has no elements.\n";
	cSize++;
	}
   // Base case. for Heap Overflow
    if(cSize==mSize){
        cout<<"Size overflow"<<endl;
        }
  // Insert the new key at the end.
    else{
        hArr[cSize]=value;
    
        //Check it for all hierarchy with loop
        int j=cSize;
        
	    while(j!=0){
           
	//Check if it breaks the heap property and fix it. 
          if(hArr[j]<hArr[parent(j)]){
            swap(&hArr[j],&hArr[parent(j)]);
          }
          j=(j-1)/2;
        
	      }
  
	    cSize++; 
	 }     
  }
    void display(){
    	int i;
        // Display the array
        for(int i=0;i<cSize;i++){
          cout<<hArr[i]<<"->";
          }
           
            
     }

    int extractMin()
     { 
          int min;
        // Base case for Empty Heap
          if(cSize==0){
	           cout<<"The heap has no elements.\n";
	}
        // Base case for Heap with 1 value.
           min=hArr[0];
        // Copy the last element to the root. 
           hArr[0]=hArr[cSize-1];
           cSize--; 
        // Call MinHeapify on root. 
           MinHeapify(0);
        // Return the min (Store it, before you replace the root with the last element)
	       return min;
    }

    void decreaseKey(int i, int new_val) 
    { 
        // Algorithm for what happens when I reduce the value of an element indexed at i to new_val. You can assume new_val to be less than the present value of the element. 
        hArr[i] = new_val; 
        // Loop for correcting the Property 2. 
     
	    while(i!=0){
	// Compare with parent and move up till i == 0 or there is no violation.
        if(hArr[i]<hArr[parent(i)]){
            swap(&hArr[i],&hArr[parent(i)]);
            
           
        }
	    else{
		    break;
	    }
        i=(i-1)/2;
        }
	
   } 
    // Deletes the element indexed at i. 
    void deleteKeyAt(int i) 
    { if(i>cSize){
          cout<<"Size Underflow"<<endl;
    }
      else{
          cout<<"\nDeleting key at position "<< i <<" :\n";
        // Decrease the value to INT_MIN at index i use decreaseKey()
          decreaseKey(i,INT_MIN);
        
        // Call ExtractMin
	      extractMin();
	     }
    }

    void MinHeapify(int i) 
    { //stopping condn
	  if((right(i)>cSize)&&(left(i)>cSize)){
	     return;
	}
	// only 1 child
      else if(right(i)>cSize){
         swap(&hArr[left(i)],&hArr[i]);
         }
        // Compare with left and right 
	  else{
         if(hArr[left(i)]<hArr[parent(i)]){
	  // Replace with the smallest.
           swap(&hArr[left(i)],&hArr[i]);
	// Call MinHeapify at the replaced child.
           MinHeapify(left(i));
         }
         else{
	// Replace with the smallest.
           swap(&hArr[right(i)],&hArr[i]);
	// Call MinHeapify at the replaced child.
	       MinHeapify(right(i));
         }
        
       }
  
    }   

        
                 
    

};


int main(){
    BinaryHeap bh1(9);
    for(int i = 10; i>0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
        cout<<endl;
    }
    cout<< "\n \n";
    bh1.display();
    cout<<endl;
    cout<< "\n \n";
   
    cout<< "\n \n";
    for(int i = 10; i>0 ; i--){
      bh1.deleteKeyAt(3);
      bh1.display();
             }
    cout  <<endl;
    bh1.display();
    cout<<endl;
    cout<< "\n \n";
    cout  <<endl;
    cout<<"Extracting the min value :\n";
    bh1.extractMin();
    cout<<endl;
    bh1.display();
}

