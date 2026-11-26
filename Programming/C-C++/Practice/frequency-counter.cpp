#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void display(vector<int>& input, bool running, int number) {
    while(running)
    {
        std::cout << "press (-1) to quit" << endl;
        std::cout << "Input : ";
        std::cin >> number;
        input.push_back(number);
    
        if(number == -1 ) {
            input.pop_back();
            running = false;
        };
        
    };
}

int partition(vector<int>& arr, int start, int end) {
        int i = start - 1;
        int pivot = arr[end];

       for(int j = start; j < end; j++) {
            if(arr[j] <= pivot) {
                i++;
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }

        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[end]; 
        arr[end] = temp;

        return i + 1;
}

void quicksort(vector<int>& input, int start, int end) {
    if(start >= end) return;

    int pivotIndex = partition(input,  start, end);

    quicksort(input, start, pivotIndex - 1);
    quicksort(input, pivotIndex + 1, end);

}
void frequency(vector<int> input) {
   int counter = 0; 
   for(int i = 0; i < input.size(); i++) {
       for(int j = i + 1; j < input.size(); j++) {

           if(input[i] == input[j]) {
               counter++;

               if(j >= 0 && j < input.size()) {
                   input.erase(input.begin() + j);
                   j--;

               }
           }
       } if(counter == 0) {
           if(i >= 0 && i < input.size()) {
                input.erase(input.begin() + i);
                
           }
       } 
       if(i > 0) {
        cout << input[i] << " : " << counter << endl;
        counter = 0;
       }
   }
}
int main() {
    vector<int> input; 
    int number;
    bool running = true;

    display(input, running, number);
    cout << "original Array : ";
    for (int x : input) {
        cout << x << " ";
    }
    cout << endl;

    quicksort(input, 0, input.size() - 1);
    cout << "sorted : ";
    for (int x : input) {
        cout << x << " ";
    }

    cout << endl;
   
    frequency(input);

}
