#include "bits/stdc++.h"
using namespace std;

void naive(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return;

    int pos = 0;
    vector<int> dp(n), last(n);

    for(int i = 0; i < n; ++i){
        dp[i] = 0;
        last[i] = -1;

        for(int j = 0; j < i; ++j) if(arr[j] < arr[i] && dp[j] > dp[i]){
            dp[i] = dp[j];
            last[i] = j;
        }

        ++dp[i];
        if(dp[i] > dp[pos]) pos = i;
    }

    vector<bool> isLIS(n);
    while(pos != -1) isLIS[pos] = true, pos = last[pos];

    vector<int> left, right;
    for(int i = 0; i < n; ++i)
        if(isLIS[i]) left.push_back(arr[i]);
        else right.push_back(arr[i]);

    naive(right);
    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void optimization_1(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return;

    int maxpos = 0;
    vector<int> dp, pos, last;

    for(int i = 0; i < n; ++i){
        int j = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

        if(j == dp.size()){
            dp.push_back(arr[i]);
            pos.push_back(i);
        }
        else{
            dp[j] = arr[i];
            pos[j] = i;
        }

        if(j == 0) last.push_back(-1);
        else last.push_back(pos[j - 1]);

        maxpos = *pos.rbegin();
    }

    vector<bool> isLIS(n);
    while(maxpos != -1) isLIS[maxpos] = true, maxpos = last[maxpos];

    vector<int> left, right;
    for(int i = 0; i < n; ++i)
        if(isLIS[i]) left.push_back(arr[i]);
        else right.push_back(arr[i]);

    optimization_1(right);
    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void optimization_2(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return;

    int maxpos = 0;
    vector<int> dp, pos, last;

    for(int i = 0; i < n; ++i){
        int j = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

        if(j == dp.size()){
            dp.push_back(arr[i]);
            pos.push_back(i);
        }
        else{
            dp[j] = arr[i];
            pos[j] = i;
        }

        if(j == 0) last.push_back(-1);
        else last.push_back(pos[j - 1]);

        maxpos = *pos.rbegin();
    }

    vector<bool> isLIS(n);
    while(maxpos != -1) isLIS[maxpos] = true, maxpos = last[maxpos];

    vector<int> left, right;
    for(int i = 0; i < n; ++i)
        if(isLIS[i]) left.push_back(arr[i]);
        else right.push_back(arr[i]);


    reverse(right.begin(), right.end());
    optimization_2(right);
    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void optimization_3(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return;

    int maxpos = 0;
    vector<int> dp, pos, last;

    for(int i = 0; i < n; ++i){
        int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

        if(j == dp.size()){
            dp.push_back(arr[i]);
            pos.push_back(i);
        }
        else{
            dp[j] = arr[i];
            pos[j] = i;
        }

        if(j == 0) last.push_back(-1);
        else last.push_back(pos[j - 1]);

        maxpos = *pos.rbegin();
    }

    vector<bool> isLIS(n);
    while(maxpos != -1) isLIS[maxpos] = true, maxpos = last[maxpos];

    vector<int> left, right;
    for(int i = 0; i < n; ++i)
        if(isLIS[i]) left.push_back(arr[i]);
        else right.push_back(arr[i]);


    reverse(right.begin(), right.end());
    optimization_3(right);
    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

/// SOURCE: GEEKSFORGEEKS
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(vector<int> &arr, int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    vector<int> leftArray(subArrayOne), rightArray(subArrayTwo);

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(vector<int> &arr, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}
