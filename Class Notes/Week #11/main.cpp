#include <iostream>
using namespace std;

class MinHeap {
    int *harr;
    int capacity;
    int heapSize;

public:

    MinHeap(int c) {
        heapSize = 0;
        capacity = c;
        harr = new int[c];
    }

    void Heapify();
    int extractMin();

    void insertKey(int k) {
        if(heapSize == capacity) {
            cout << "heap full!!" << endl;
            return;
        }
        heapSize++;
        harr[heapSize] = k;

        percolateUp(heapSize);
    }

    void percolateUp(int index);
    void percolateDown(int index);
    MinHeap *initHeapfromArray(int *values, int length);
    void swap(int index1, int index2);
    int minimum(int a, int indexa, int b, int indexb);

};

void MinHeap::swap(int index1, int index2) {
    int temp = harr[index1];
    harr[index1] = harr[index2];
    harr[index2] = temp;
}

void MinHeap::percolateUp(int index) {
    if(index > 1) {
        if(harr[index/2] > harr[index]) {
            swap(index, index/2);
            percolateUp(index/2);
        }
    }
}

int MinHeap::minimum(int a, int indexa, int b, int indexb) {

}

void MinHeap::percolateDown(int index) {
    int min;

    if(2 * index + 1 <= heapSize) {
        min = minimum(harr[2 * index], 2 * index, harr[2 * index + 1 * index + 1]);

        if(harr[index] < harr[min]) {
            swap(index, min);
            percolateDown(min);
        }
    }

    else if(2 * index == heapSize) {
        if(harr[index] > harr[2 * index]) {
            swap(index, min);
        }
    }
}

MinHeap *MinHeap::initHeapfromArray(int *values, int length) {

    MinHeap *h = new MinHeap(length);

    for(int i = 1; i < length; i++) {
        h->harr[i] = values[i - 1];
    }

    h->heapSize = length;
    h->Heapify();

    return h;
}

void MinHeap::Heapify() {
    int i;

    for(i = heapSize/2; i > 0; i--) {
        percolateDown(i);
    }
}

int MinHeap::extractMin() {
    int retVal;

    if(heapSize > 0) {
        retVal = harr[1];
        harr[1] = harr[heapSize];
        heapSize--;
        percolateDown(1); 

        return retVal;
    }

    else {
        return -1;
    }

}

void sort(int values[], int length) {
    MinHeap* h = new MinHeap(length);
    h = h->initHeapfromArray(values, length);

    for(int i = 0; i < length; i++) {
        values[i] = h->extractMin();
        cout << "array[" << i << "]: " << values[i] << endl;
    }
}

int main() {
    std::cout << "Hello World!\n";
}