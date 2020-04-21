#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#include <algorithm>
#include <chrono> 
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

static int ARR_SIZE = 265;


void swap(int* x, int* y){ //helper function to swap elements in array  
    int z;
    z = *x;  
    *x = *y;  
    *y = z;  
}

int partition(int arr[], int lowest, int highest){ //splits array based on pivot found, > and < 
    int pivot = arr[highest]; 
    int i = (lowest - 1);  
  
    for (int j = lowest; j <= highest - 1; j++){   
        if (arr[j] < pivot){  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[highest]);  
    return (i + 1);  
}  

int partititon_rand(int arr[], int low, int high){ //chooses random pivot
    int randNum = low + rand() % (high - low); 

    swap(arr[randNum], arr[high]); 
  
    return partition(arr, low, high); 
} 

void quick_sort(int arr[], int low, int high){ //quick sort function (calculated pivot)
    if(low < high){ 
        int pivot = partition(arr, low, high);

        //Sort below and above partition
        quick_sort(arr, low, pivot-1);
        quick_sort(arr, pivot+1, high);
    }
}

void quick_sort_rand(int arr[], int low, int high){ //quick sort function (random pivot)
    if(low < high){ 
        int pivot = partition_rand(arr, low, high);

        //Sort below and above partition
        quick_sort_rand(arr, low, pivot-1);
        quick_sort_rand(arr, pivot+1, high);
    }
}


void print_array(int arr[], float time){ //function to print array and time to sort
    cout << "\n";
    for(int i = 0; i < ARR_SIZE-1; i++){
        cout << arr[i] << ", ";
    }
    cout << "\n";
    cout << "Time to sort: " << time << "\n";
}

int main(){
    int sort_array[ARR_SIZE]; //initialize array
    int sort_copy[ARR_SIZE];
    copy(begin(sort_array), end(sort_array), begin(sort_copy)); //Copy to second array so both sorts start with same array

    int n = sizeof(sort_array) / sizeof(sort_array[0]);

    srand(time(0)); //Seeds randNum number generation based on system time
    
    for(int i = 0; i < ARR_SIZE-1; i++){ //fills sort_array[] with randNum numbers to be sorted
        sort_array[i] = rand();
    }
    auto start = high_resolution_clock::now(); //Begin timer
  
    quick_sort(sort_array, 0, n-1);
    
    auto stop = high_resolution_clock::now(); //End timer
    auto duration = duration_cast<microseconds>(stop - start); //Time of sort in microseconds
    float TTS = duration.count(); //Time to sort

    print_array(sort_array, TTS);

    //RAND QUICK SORT
    auto start = high_resolution_clock::now(); //Begin timer
  
    quick_sort_rand(sort_array, 0, n-1);
    
    auto stop = high_resolution_clock::now(); //End timer
    auto duration = duration_cast<microseconds>(stop - start); //Time of sort in microseconds
    TTS = duration.count(); //Time to sort

    print_array(sort_array, TTS);

    return 0;

}