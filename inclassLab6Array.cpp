#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define size 10
int arr[size];
int top = -1;

bool isEmpty(){
   if (top=-1){
      return true;
   }else{
      return false;
   }
}
void Push(int value){
   if (top==size-1){
      cout << "stack is full"<<endl;
   }else{
      top++;
      arr[top]=value;
   }
}
void Pop(){
   if (isEmpty()){
      cout << "cant pop, stack is empty"<<endl;
   }else{
      cout<<"popped element: "<< arr[top]<<endl;
      top--;
   }
}
void Display() {
   if(top>=0) {
      for(int i=top; i>=0; i--)
      cout<<arr[i]<<" "<<endl;
   }else{
      cout<<"nothing to display, Stack is empty"<<endl;
   }
}

int main(){
   auto start_time = high_resolution_clock::now();
   Push(8);
   Push(10);
   Push(5);
   Push(11);
   Push(15);
   Push(23);
   Push(6);
   Push(18);
   Push(20);
   Push(17);
   Display();
   Pop();
   Pop();
   Pop();
   Pop();
   Pop();
   Display();
   Push(4);
   Push(30);
   Push(3);
   Push(1);
   Display();
   auto end_time = high_resolution_clock::now();
   auto execution_time = duration_cast<microseconds>(end_time - start_time);
   cout << "Execution time: " << execution_time.count() << " us" << endl;
   return 0;
}