#include <iostream> 
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono> 
#include <ctime>

using namespace std;

void merge(int[],int,int,int);
void mergeSort(int[],int,int);

int main(int argc, char *argv[]) {
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
        start = chrono::system_clock::now();
        mergeSort(arr,0,test_cases.at(i).size()-1);
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed = end - start;
        for(int j = 0; j < test_cases.at(i).size(); j++) {
            out << arr[j] << ",";
        }
        out << "" << endl;
        out << "Time to complete sort: " << elapsed.count() << " seconds" << endl;
    }
    // int arr[input.size()];
    // for(int i = 0; i < input.size(); i++) {
    //     arr[i] = input.at(i);
    // }
      
    // start = chrono::system_clock::now();
    // mergeSort(arr,0,input.size()-1);
    // for(int i = 0; i < input.size(); i++) {
    //     out << arr[i] << ",";
    // }
    // out << "" << endl;
    // end = chrono::system_clock::now();
    // chrono::duration<double> elapsed = end - start;
    // out << elapsed.count() << " seconds" << endl;
    out.close();
    return 0;
}
void merge(int arr[], int front, int mid, int back) {
    int break_1 = mid - front + 1;
    int break_2 = back - mid;
    int left [break_1];
    int right [break_2];
    for(int i = 0; i < break_1; i++) {
        left[i] = arr[front+i];
    }
    for(int i = 0; i < break_2; i++) {
        right[i] = arr[mid+i+1];
    }
    int left_point = 0;  
    int right_point = 0; 
    int orig_point = front; 
    while (left_point < break_1 && right_point < break_2) 
    { 
        if (left[left_point] <= right[right_point]) 
        { 
            arr[orig_point] = left[left_point]; 
            left_point++; 
        } 
        else
        { 
            arr[orig_point] = right[right_point]; 
            right_point++; 
        } 
        orig_point++; 
    } 
    while (left_point < break_1) 
    { 
        arr[orig_point] = left[left_point]; 
        left_point++; 
        orig_point++; 
    } 
    while (right_point < break_2) 
    { 
        arr[orig_point] = right[right_point]; 
        right_point++; 
        orig_point++; 
    } 
}
void mergeSort(int arr[], int front, int back) {
    if(front < back) {
        int mid = (front + back) / 2;
        mergeSort(arr, front, mid);
        mergeSort(arr,mid+1,back);
        merge(arr,front,mid,back);
    }
}