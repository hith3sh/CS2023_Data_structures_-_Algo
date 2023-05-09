#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[high]);
    return i+1;
}
//implements quicksort algorithm
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);
    }
}
//this function will return the median of the array in float 
float returnMedian(vector<int> arr) {
   int size=arr.size();
   sort(arr.begin(),arr.end());
   if (size % 2 == 0) {
      return (((float)arr[size/2]+(float)arr[size/2 -1])/2.0);
    }
    else {
        return (float)arr[size/2];
    }
}

int main() {
   int n,newNum;
   //asking the user to enter the size of the array
   cout<< "enter the size of the array: ";
   cin >> n;
   
   //creating a vector array
   vector<int> arr;
   //generate random numbers from 0 to 99
   srand(time(0));
   for(int i=0;i<n;i++){
      arr.push_back(rand()%100);
   }
   //printing the existing array
   cout << "existing array: ";
   for(int i=0;i<n;i++){
      cout << arr[i] <<" ";
   }
   //asking user for a new number
   cout <<endl << "enter a new number: ";
   cin >> newNum;
   arr.push_back(newNum); 
   //printing the median value with sorted array
   quicksort(arr,0,n);
   cout<<"sorted array: ";
   for(int i=0;i<arr.size();i++){
      cout << arr[i] <<" ";
   }
   cout <<"median is: " <<  returnMedian(arr);
   return 0;
}
