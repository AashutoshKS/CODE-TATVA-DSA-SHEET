/**
PROBELM : 
      Given two arrays of integers nums and index. Your task is to create target array under the following rules:
      
      Initially target array is empty.
      From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
      Repeat the previous step until there are no elements to read in nums and index.
      Return the target array.
      
      It is guaranteed that the insertion operations will be valid.
*/

TIME COMPLEXITY : O(n);
SPACE COMPLEXITY : O(n);

//code
//insert function is used to insert value at a perticular index

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i)
            v.insert(v.begin() + index[i], nums[i]);
        return v;
    }
};
