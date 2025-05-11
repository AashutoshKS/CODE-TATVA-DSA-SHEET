//PROBELM :

        In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
        
        Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.
        
//APPROACH : 
        count frequencies of all the elements at each index push the element of maximum frequency if it is possible to do so, 
        or else push the 2n dmost frequent element
          -> priority queue helps us to do this with ease

//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(n)


//CODE :
        class Solution {
        public:
            vector<int> rearrangeBarcodes(vector<int>& nums) {
                if(nums.size() == 1) return nums;
                priority_queue<pair<int,int>>heap;
                sort(nums.begin(),nums.end());
                int count = 1;
                for(int i=1;i < nums.size();i++){
                    if(nums[i] == nums[i-1]) {
                        count++;
                        if(i == nums.size() - 1) heap.push({count,nums[i-1]});
                    }
                    else {
                        heap.push({count,nums[i-1]});
                        count = 1;
                        if(i == nums.size() - 1) heap.push({count,nums[i]});
                    }
                }
                vector<int>ans;
                while(!heap.empty()) {
                    if(ans.size() == 0) {
                        ans.push_back(heap.top().second);
                        int x = heap.top().first - 1;
                        int y = heap.top().second;
                        heap.pop();
                        if(x > 0) heap.push({x,y});
                    } else {
                        int s = heap.top().second;
                        if(ans.back() == s) {
                            int x1 = heap.top().first;
                            int y1 = heap.top().second;
                            heap.pop();
                            ans.push_back(heap.top().second);
                            int x = heap.top().first - 1;
                            int y = heap.top().second;
                            heap.pop();
                            if(x > 0) {
                                heap.push({x,y});
                            }
                            if(x1 > 0) heap.push({x1,y1});
                        } else {
                            ans.push_back(heap.top().second);
                            int x = heap.top().first - 1;
                            int y = heap.top().second;
                            heap.pop();
                            if(x > 0)heap.push({x,y});
                        }
                    }
                }
                return ans;
            }
        };
        
        
        
        
        
         
