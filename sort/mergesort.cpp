#include <vector>
#include <iostream>

using namespace std;

void printVec(vector<int> arr) {
    for(int v : arr) {
        cout << v << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int l, int m, int r) {
     int i, j, k;
     vector<int> leftArr(m - l + 1);
     vector<int> rightArr(r - m);

     for(i = 0; i < leftArr.size(); i++) {
         leftArr[i] = arr[l+i];
     }
     for(j = 0; j < rightArr.size(); j++) {
        rightArr[j] = arr[m+j+1];
     }

     i = j = 0;
     k = l;
     while(i < leftArr.size() && j < rightArr.size()) {
         if(leftArr[i] < rightArr[j]) {
             arr[k] = leftArr[i];
             i++;
         } else {
             arr[k] = rightArr[j];
             j++;
         }
         k++;
     }

     while( i < leftArr.size()) {
         arr[k] = leftArr[i];
         k++;
         i++;
     }

     while(j < rightArr.size()) {
         arr[k] = rightArr[j];
         k++;
         j++;
     }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l < r){
        int m = (r-l) / 2 + l;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
        printVec(arr);
    }
}

void sort(vector<int> &arr) {
    mergeSort(arr, 0, arr.size()-1);
}

int main(void) {
    vector<int> arr = {10, 9, 30, 1, 14, 50, 32};
    sort(arr);

    printVec(arr);

    return 0;
}