#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void quickSort(int arr[], int left, int right)
{
   int i = left, j = right;
   int pivot = arr[(left + right) / 2];
   while (i <= j)
   {
      while (arr[i] < pivot)
         i++;
      while (arr[j] > pivot)
         j--;
      if (i <= j)
      {
         swap(arr[i], arr[j]);
         i++;
         j--;
      }
   }
   if (left < j)
      quickSort(arr, left, j);
   if (i < right)
      quickSort(arr, i, right);
}

float getMedian(int arr[], int size)
{
   sort(arr, arr + size);
   if (size % 2 == 0)
   {
      return ((float)arr[size / 2 - 1] + (float)arr[size / 2]) / 2.0;
   }
   else
   {
      return (float)arr[size / 2];
   }
}

int main()
{
   int size, num;
   cout << "Enter the size of the array: ";
   cin >> size;

   // Dynamically allocate memory for array
   int *arr = new int[size];

   // Generate random numbers between 1 and 100 for each array element
   srand(time(0));
   for (int i = 0; i < size; i++)
   {
      arr[i] = rand() % 100 + 1;
   }

   // Print the original array
   cout << "Original array: ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;

   // Ask user to add a number to the array
   cout << "enter a new number to the array: ";
   cin >> num;

   // Add the user input number to the end of the array
   arr[size] = num;
   size++;

   // Sort the array using quicksort
   quickSort(arr, 0, size - 1);

   // Print the sorted array
   cout << "sorted array is: ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;

   // Print the median of the sorted array
   cout << "Median is: " << getMedian(arr, size) << endl;

   // Free the dynamically allocated memory
   delete[] arr;

   return 0;
}