//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        //pushes index value into next most available spot & corrects the heap
        data[++size] = idx;
        upheap(size, weightArr);
    }

    int pop(int weightArr[]) {
        // Replaces root with last element, then call downheap() so not to disrupt order, b/c removing
        //last element doesn't affect heap order
        int smallest = data[0];
        data[0] = data[size--];
        downheap(0, weightArr);
        return smallest;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif