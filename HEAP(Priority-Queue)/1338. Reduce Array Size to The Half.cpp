//PROBLEM :

                    You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
                    
                    Return the minimum size of the set so that at least half of the integers of the array are removed.



//APPROACH :
                  since we have to pick minimum elements so that the lenght of the array is reduced to half,
                  we can pick any element since we are not bound for that
                  in order to pick minimum element we will prefer the element of max frequency
                  count frequencies of all the elements and check how many elements are required
                        -> you can either store the elements in a vector and sort it else 
                        -> use max heap for the same




//COMPLEXITY : 
                  TIME COMPLEXITY : O(2n) = O(n)
                  SPACE COMPLEXITY : O(n)



//CODE :
                class Solution {
                public:
                    int minSetSize(vector<int>& arr) {
                        unordered_map<int,int>mp;
                        for(int i : arr) mp[i]++;
                        priority_queue<int>pq;
                        for(auto it:mp) {
                            pq.push(it.second);
                        }
                        int n = arr.size()/2;
                        int ans = 0;
                        while(!pq.empty() && n > 0) {
                            n -= pq.top();
                            ans++;
                            pq.pop();
                        }
                        return ans;
                    }
                };
