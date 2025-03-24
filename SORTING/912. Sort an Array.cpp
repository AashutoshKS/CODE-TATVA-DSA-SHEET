//PROBLEM :
            Sort an array

//OPTIMAL APPROACH :
            using merge or heap sort ie. n.logn

              
//CODE :

              class Solution {
              private :
                  void merge(vector<int>& nums, int left, int mid, int right) {
                      int i, j, k;
                      int n1 = mid - left + 1;
                      int n2 = right - mid;
              
                      vector<int> leftVec(n1), rightVec(n2);
              
                      for (i = 0; i < n1; i++)
                          leftVec[i] = nums[left + i];
                      for (j = 0; j < n2; j++)
                          rightVec[j] = nums[mid + 1 + j];
              
                      i = 0;
                      j = 0;
                      k = left;
                      while (i < n1 && j < n2) {
                          if (leftVec[i] <= rightVec[j]) {
                              nums[k] = leftVec[i];
                              i++;
                          } else {
                              nums[k] = rightVec[j];
                              j++;
                          }
                          k++;
                      }
                      while (i < n1) {
                          nums[k] = leftVec[i];
                          i++;
                          k++;
                      }
                      while (j < n2) {
                          nums[k] = rightVec[j];
                          j++;
                          k++;
                      }
                  }
                  void mergeSort(vector<int>& nums, int left, int right) {
                      if (left < right) {
                          int mid = left + (right - left) / 2;
                          mergeSort(nums, left, mid);
                          mergeSort(nums, mid + 1, right);
                          merge(nums, left, mid, right);
                      }
                  }
              public:
                  vector<int> sortArray(vector<int>& nums) {
                      mergeSort(nums,0,nums.size() - 1);
                      return nums;
                  }
              };

//using CPP STL

              class Solution {
              public:
                  vector<int> sortArray(vector<int>& nums) {
                      sort(nums.begin(),nums.end());
                      return nums;
                  }
              };
