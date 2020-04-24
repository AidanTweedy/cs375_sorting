#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#include <algorithm>
#include <chrono> 
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
int main(int argc, char *argv[])
{  
    /*
    //change to main()
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
    */
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
    chrono::time_point<chrono::system_clock> start, end;
    out << "-----------------------" << endl;
    out << "After sorting" << endl;
    out << "-----------------------" << endl;
    for(int i = 0; i < test_cases.size(); i++) {
        int arr[test_cases.at(i).size()];
        for(int j = 0; j < test_cases.at(i).size(); j++) {
           arr[j] = test_cases.at(i).at(j);
        }
        int n = sizeof(arr) / sizeof(arr[0]);  
        start = chrono::system_clock::now();
        insertionSort(arr,n);
        end = chrono::system_clock::now();
        auto duration = duration_cast<microseconds>(end - start); //Time of sort in microseconds
        float TTS = duration.count(); //Time to sort
        out << "TIME TO SORT: " << TTS << " microseconds" << "\n";

        /*
        for(int j = 0; j < test_cases.at(i).size(); j++) {
            out << arr[j] << ",";
        }
        out << "" << endl;
        */
        //out << "Time to complete sort: " << elapsed.count() << " seconds" << endl;
    }
    out.close();
    return 0;
    
}

