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


//Print Array
void printArray(int sort_array[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << sort_array[i] << ", ";  
    cout << endl; 
}  

//Sorts Array using the insertion sort
void insertionSort(int sort_array[], int n)  
{  
    int i;  
    int node;
    int j;
    for (i = 1; i < n; i++) 
    {  
        node = sort_array[i];  
        j = i - 1;  
        while (0<= j && node < sort_array[j]) 
        {  
            sort_array[j+1] = sort_array[j];  
            j = j-1;  
        }  
        sort_array[j + 1] = node;  
    }  
}  
//Driver
int main()  
{  
    static int ARR_SIZE = 265;
    int sort_array[ARR_SIZE]; 
    for(int i = 0; i < ARR_SIZE-1; i++){ 
        sort_array[i] = rand();
    }
    int n = sizeof(sort_array) / sizeof(sort_array[0]);  


    auto start = high_resolution_clock::now();


    insertionSort(sort_array, n);  

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start); 
    float TTS = duration.count(); 

    printArray(sort_array, n);  
    cout << "Time to sort: " << TTS << " μs" << endl;
    return 0;  
}  
  
