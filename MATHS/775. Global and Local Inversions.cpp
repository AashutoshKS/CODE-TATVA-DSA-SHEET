//PROBLEM : 

      You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].
      
      The number of global inversions is the number of the different pairs (i, j) where:
      
      0 <= i < j < n
      nums[i] > nums[j]
      The number of local inversions is the number of indices i where:
      
      0 <= i < n - 1
      nums[i] > nums[i + 1]
      Return true if the number of global inversions is equal to the number of local inversions.




//APPROACH 1 :
      - count local inversion in O(n)
      - count globle inversion using merge sort algo...
      - compare if both are equal


//COMPLEXITY :
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(n)


//code :
      class Solution {
      public:
          long long mergeSort(vector<int>& a, vector<int>& temp, int l, int r) {
              if (l >= r) return 0;
              int mid = (l + r) / 2;
      
              long long inv = 0;
              inv += mergeSort(a, temp, l, mid);
              inv += mergeSort(a, temp, mid + 1, r);
      
              int i = l, j = mid + 1, k = l;
      
              while (i <= mid && j <= r) {
                  if (a[i] <= a[j]) temp[k++] = a[i++];
                  else {
                      temp[k++] = a[j++];
                      inv += (mid - i + 1);
                  }
              }
      
              while (i <= mid) temp[k++] = a[i++];
              while (j <= r) temp[k++] = a[j++];
      
              for (int p = l; p <= r; p++) a[p] = temp[p];
      
              return inv;
          }
      
          bool isIdealPermutation(vector<int>& nums) {
              int n = nums.size();
      
              // local inversion count (O(n))
              int loc = 0;
              for (int i = 0; i < n - 1; i++) {
                  if (nums[i] > nums[i + 1]) loc++;
              }
      
              vector<int> arr = nums;
              vector<int> temp(n);
      
              long long glo = mergeSort(arr, temp, 0, n - 1);
      
              return glo == loc;
          }
      };




//APPROACH 2:
      if nums[i] > nums[i+1] then local inv = 1 and also globbal inversion is 1
      In simple word if global inversion is always >= local inversion
      use this logic for the question



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)



//CODE :
      class Solution {
      public:
          bool isIdealPermutation(vector<int>& nums) {
              int mx = -1; 
              for (int i = 0; i + 2 < nums.size(); ++i) {
                  mx = max(mx, nums[i]);
                  if (mx > nums[i + 2])
                      return false;
              }
      
              return true;
          }
      };
      
              
