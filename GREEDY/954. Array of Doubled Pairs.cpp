//PROBLEM :

        Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] 
        for every 0 <= i < len(arr) / 2, or false otherwise.


//APPROACH :
        in simple word for n/2 we need its double present in the array from the rest of the n/2 elements
        put numbers in map
        sort the list 
        search from starting if the double is not presen treturn true
            exception ->
                -4 is double of -2 similarly -6 is double of -3
                but while sorting -4 is present before -2 and -6 is present before -3
                we can reverse all the -ve elements in the list to hab=ndle the edge case


//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(n)


//CODE :
        class Solution {
        public:
            bool canReorderDoubled(vector<int>& arr) {
                unordered_map<int, int> mp;
                for (int i : arr)
                    mp[i]++;
                sort(arr.begin(), arr.end());
                int j = 0;
                while (j < arr.size() && arr[j] < 0)
                    j++;
                reverse(arr.begin(), arr.begin() + j);
                for (int i = 0; i < arr.size(); i++) {
                    if (mp[arr[i]] != 0) {
                        if (mp[2 * arr[i]] == 0)
                            return false;
                        mp[arr[i]]--;
                        mp[2 * arr[i]]--;
                    }
                }
                return true;
            }
        };
