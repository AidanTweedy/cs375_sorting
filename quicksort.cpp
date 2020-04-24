
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#include <algorithm>
#include <thread>
#include <iostream> 
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono> 
#include <ctime>

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

int partition_rand(int arr[], int low, int high){ //chooses random pivot
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

int main(int argc, char *argv[]){
    ifstream infile(argv[1]);
    ofstream out;
    out.open((argv[2]));

    string line;
    vector<int> input;
    vector<vector<int>> test_cases;
    while(getline(infile,line)) {
        //getline(infile,line);
        stringstream s(line);

        while(s.good()) {
            string temp = "";
            getline(s,temp,',');
            int i = stoi(temp);
            input.push_back(i);
        }
        test_cases.push_back(input);
        input.clear();
    }
    out << "Before sorting: " << endl;
    out << "-----------------------" << endl;
    for(int i = 0; i < test_cases.size(); i++) {
        for(int j = 0; j < test_cases.at(i).size(); j++) {
            out << test_cases.at(i).at(j) << ",";
        }
        out << "" << endl;
    }
    out << "-----------------------" << endl;
    out << "After sorting" << endl;
    out << "-----------------------" << endl;
    for(int i = 0; i < test_cases.size(); i++) {
        int arr[test_cases.at(i).size()];
        for(int j = 0; j < test_cases.at(i).size(); j++) {
           arr[j] = test_cases.at(i).at(j);
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        auto start = high_resolution_clock::now(); //Begin timer
  
        quick_sort(arr, 0, n-1);
    
        auto stop = high_resolution_clock::now(); //End timer
        auto duration = duration_cast<microseconds>(stop - start); //Time of sort in microseconds
        float TTS = duration.count(); //Time to sort
        out << "TIME TO SORT: " << TTS << "microseconds";

        //print_array(arr, TTS);
    }
    out.close();
/*
    //RAND QUICK SORT
    auto start2 = high_resolution_clock::now(); //Begin timer
  
    quick_sort_rand(arr, 0, n-1);
    
    auto stop2 = high_resolution_clock::now(); //End timer
    auto duration2 = duration_cast<microseconds>(stop - start); //Time of sort in microseconds
    TTS = duration2.count(); //Time to sort

    print_array(sort_copy, TTS);

    return 0;
    */

}
