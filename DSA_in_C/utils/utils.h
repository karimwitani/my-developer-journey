#pragma once

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void printArray(int arr[], int size);

void swap(int array_to_sort[], int pos1, int pos2);

// void shift(int arr[], int shift_end_idx, int shift_start_idx);