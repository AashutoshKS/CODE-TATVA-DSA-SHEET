//PROBLEM : 
      We are given a list nums of integers representing a list compressed with run-length encoding.
      
      Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val 
      concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.
      
      Return the decompressed list.


//COMPLEXITY : 
      TIME COMPLEXITY  :O(n)
      SPACE COMPLEXITY : O(n)


//APPROACH
      given nums = [1,3]  ans = [3]
      given nums = [3,1]  ans = [1,1,1]
      similarly if givwen nums = [1,2,3,4]  then ans = [2,4,4,4]
      use the relation for the same


//CODE 
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector <int> v;
        for(int i=0;i<nums.size();i+=2){
            for(int j=0;j<nums[i];j++)
                v.push_back(nums[i+1]);
        }
        return v;
    }
};
