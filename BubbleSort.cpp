#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);
void bubbleSort(int *a, int n);

int main(int argc,char*argv[]) {
  //Check if correct number of arguments is provided
    if(argc!=3){
        cout<<"Usage: BubbleSort seed length"<<endl;
        exit(1);
    }

    // get input: first is random seed, second is vector length
    int seed, length;
    seed=atoi(argv[1]);
    length=atoi(argv[2]);

    //seed=4;
    //length=5;
    srand(seed);


    cout<<seed<<" "<<length<<endl;


    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace

    // define an integer pointer dynamically allocate an array of integers
    int* array=new int[length];


    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // copy the random list of integers from vector to array
    for(int i=0;i<length;i++){
        array[i]=v.at(i);
        cout<<array[i]<<'\t';
    }
    cout<<endl;


    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    bubbleSort(array, length);
    clock_t end_bubbleSort = clock();

    // check output, make sure array is sorted after bubbleSort
    for(int i=1;i<length;i++){
        assert(array[i-1]<=array[i]);
    }


    // print sorted vector after mergeSort
    cout << "Sorted by MergeSort:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort
    cout<<"Sorted by BubbleSort:"<<endl;
    for(int i=0;i<length;i++){
        cout<<array[i]<<'\t';
    }
    cout<<endl;

    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << elapsed_mergeSort << " " << elapsed_bubbleSort << endl;


    //Unit test for Swap
 /*   int *A=new int[2];
    A[0]=2;
    A[1]=4;
    cout<<"Unit Test for Swap"<<endl;
    cout<<"Input: 2 4"<<endl;
    cout<<"Expected output: 4 2"<<endl;
    swap(A[0],A[1]);
    cout<<"Actual Output: "<<A[0]<<" "<<A[1]<<endl;
    delete[] A;
    */

    //Unit Test for BubbleSort
  /*  int *B=new int[3];
    B[0]=5;
    B[1]=3;
    B[2]=2;
    cout<<"Unit Test for BubbleSort"<<endl;
    cout<<"Input: 5 3 2"<<endl;
    cout<<"Expected output: 2 3 5"<<endl;
    bubbleSort(B,3);
    cout<<"Actual Output: "<<B[0]<<" "<<B[1]<< " "<<B[2]<<endl;
    delete[] B;
*/

  delete[] array;
    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {
    int temp;
    temp=*a;
    *b=*a;
    *a=temp;
}

// BubbleSort function
void bubbleSort(int *a, int n) {
    while(n>0){
        for(int i=1;i<n;i++){
            if(a[i-1]>a[i]) {
                swap(a[i - 1], a[i]);
            }
            //cout << a[i - 1] << " " << a[i] << endl;
        }
        n--;
    }
}