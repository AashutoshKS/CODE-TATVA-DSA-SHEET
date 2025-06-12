//PROBLEM :

      Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
      
      Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. 
        Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.


//APPROACH :
      for all element in order based on arr2 and avaliblity in arr1 push 2 answer
      after that push the numbers which are not in arr2 and sort them 



//COMPLEXITY : 
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(n)



//CODE :
        class Solution {
        public:
            vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
                map<int,int>mp;
                for(int it : arr1) mp[it]++;
                vector<int>ans;
                for(int i = 0;i < arr2.size(); i++) {
                    while(mp[arr2[i]] > 0) {
                        ans.push_back(arr2[i]);
                        mp[arr2[i]]--;
                    }
                }
                int n = ans.size();
                for(int i : arr1) {
                    if(mp[i] != 0) ans.push_back(i);
                }
                sort(ans.begin() + n, ans.end());
                return ans;
            }
        };
