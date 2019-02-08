#include<iostream>
using namespace std;
//partition function 
int partition(int arr[],int pivot,int start,int end){
   for(int i=start;i<end;i++){
       int temp;
       if(arr[i]>arr[pivot]){
         temp=arr[i];
         arr[i]=arr[pivot];
         arr[pivot]=temp;    
           }
       }
       return pivot ;
       
     }
     
     
//quick sort function

void qs(int arr[],int start,int end){
   if(start<end){
     int pivot=end;
     int p;
    p= partition(arr,pivot,start,end);
    
     qs(arr,0,p-1);
     qs(arr,p+1,end);
     
     }
 }
 
int main(){
  int arr[100];int size;
  //ask user
  cout<<"give size of the array"<<endl;
  cin>>size;
  cout<<"give the elements of the array"<<endl;
  
  for(int i=0;i<size;i++){
  cin>>arr[i];
  }
  cout<<"Array after sorting :"<<endl;
  qs(arr,0,size-1);
  for(int i=0;i<size;i++){
  cout<<arr[i];
  }
}
  