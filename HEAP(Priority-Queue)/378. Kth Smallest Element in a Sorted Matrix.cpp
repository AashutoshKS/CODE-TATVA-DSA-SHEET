//PROBLEM :

                Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
                
                Note that it is the kth smallest element in the sorted order, not the kth distinct element.
                
                You must find a solution with a memory complexity better than O(n2).



//APPROACH 1 : BRUTE FORCE
              create a list and push all the elements 
              sort the list and return list[k-1]




//COMPLEXITY :
            TIME COMPLEXITY : O(n*n)
            SPACE COMPLEXITY : O(n*n)


//CODE :
              class Solution {
              public:
                  int kthSmallest(vector<vector<int>>& nums, int k) {
                      vector<int> nums1;
                      for (int i = 0; i < nums.size(); i++) {
                          for (int j = 0; j < nums[0].size(); j++) {
                              nums1.push_back(nums[i][j]);
                          }
                      }
                      sort(nums1.begin(), nums1.end());
                      return nums1[k - 1];
                  }
              };


//APPROACH 2 :
            Since the rows and cols are sorted ie. for a n*n matrix nums[i][n-1] < nums[i+1][n-1]
            we can use this property to find the kth smallest number


//APPROACH 3 : PRIORITY QUEUE

            Push the elements in max heap if the size of heap exceeds k pop heap's top


//COMPLEXITY :
            TIME COMPLEXITY : O(n*n)
            SPACE COMPLEXITY : O(k)



//CODE :

              class Solution {
              public:
                  int kthSmallest(vector<vector<int>>& nums, int k) {
                      priority_queue<int> heap;
                      for (int i=0;i<nums.size();i++) {
                          for(int j = 0;j<nums[0].size();j++){
                              if(heap.size() == k && nums[i][j] >= heap.top())
                                  continue; 
                              heap.push(nums[i][j]);
                              if (heap.size() > k)
                                  heap.pop();
                          }
                      }
                      return heap.top();
                  }
              };
