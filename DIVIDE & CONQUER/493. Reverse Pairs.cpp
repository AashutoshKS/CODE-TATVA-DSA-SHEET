//PROBLEM :

      Given an integer array nums, return the number of reverse pairs in the array.
      
      A reverse pair is a pair (i, j) where:
      
      0 <= i < j < nums.length and
      nums[i] > 2 * nums[j].


//APPROACH :
      Use merge sort algorithm 
      before merning the 2 sorted array use 2 pointer to count the number of valid pairs...


//CODE :
      class Solution {
          int ans = 0;
          //merge sort algo
          void merge(vector<int>& arr, int left, int mid, int right) {
              int n1 = mid - left + 1;
              int n2 = right - mid;
              vector<int> L(n1), R(n2);
              for (int i = 0; i < n1; i++)
                  L[i] = arr[left + i];
              for (int j = 0; j < n2; j++)
                  R[j] = arr[mid + 1 + j];
      
              int i = 0, j = 0;
              int k = left;
              while (i < n1 && j < n2) {
                  if (L[i] <= R[j]) arr[k++] = L[i++];
                  else  arr[k++] = R[j++];
              }
              while (i < n1) {
                  arr[k++] = L[i++];
              }
      
              while (j < n2) {
                  arr[k++] = R[j++];
              }
          }
          void mergeSort(vector<int>& arr, int left, int right) {
              if (left >= right)
                  return;
      
              int mid = left + (right - left) / 2;
              mergeSort(arr, left, mid);
              mergeSort(arr, mid + 1, right);
              int i = left, j = mid + 1;
      
              //2 pointer to count the number of pairs
              while(i <= mid && j <= right) {
                  long long val = (long long)2*arr[j];
                  if(arr[i] > val) {
                      ans += mid - i + 1;
                      j++;
                  } else {
                      i++;
                  }
              }
              merge(arr, left, mid, right);
          }
      public:
          int reversePairs(vector<int>& arr) {   
              int n = arr.size(); 
              mergeSort(arr, 0, n - 1);
              return ans;
          }
      };
