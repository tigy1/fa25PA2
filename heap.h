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
        int parent_pos = (pos-1)/2;
        while (pos > 0 && weightArr[data[pos]] < weightArr[data[parent_pos]]) {
            int temp = data[parent_pos];
            data[(pos-1)/2] = data[pos];
            data[pos] = temp;
            pos = parent_pos;
            parent_pos = (pos-1)/2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        int smallest_idx = pos;
        while (true) {
            int left = 2*pos + 1;
            int right = 2*pos + 2;
            if (left < size && weightArr[data[left]] < weightArr[data[pos]]) {
                smallest_idx = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[pos]]) {
                smallest_idx = right;
            }
            if (pos != smallest_idx) {
                int temp = data[pos];
                data[pos] = data[smallest_idx];
                data[smallest_idx] = temp;
                pos = smallest_idx;
            } else {
                break;
            }
        }
    }
};

#endif