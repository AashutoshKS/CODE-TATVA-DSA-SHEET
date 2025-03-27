//PROBLEM :
                
                Given a sentence text (A sentence is a string of space-separated words) in the following format:
                First letter is in upper case.
                Each word in text are separated by a single space.
                Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. 
                  If two words have the same length, arrange them in their original order.
                
                Return the new text following the format shown above.



//APPROACH :
                track all the present words in the string, COnvert the 1st charector to lowercase
                  -> sort the vector on the basis of pair<len,index> since in case of same len we have to push the 1st element who appeared first
                  -> traverse the sorted list to detect the string
                  -> upparcase the first charector


//CODE :
                class Solution {
                public:
                    string arrangeWords(string text) {
                        vector<string>nums;
                        string s = "";
                        for(int i = 0;i < text.size(); i++) {
                            if(text[i] == ' ') {
                                nums.push_back(s);
                                s = "";
                            } else {
                                s += text[i];
                                if(i == text.size() - 1) nums.push_back(s);
                            }
                        }
                        nums[0][0] += 32;
                        vector<pair<int,int>>nums1;
                        for(int i = 0;i < nums.size(); i++) {
                            int s = nums[i].size();
                            nums1.push_back({s,i});
                        }
                        sort(nums1.begin(),nums1.end());
                        string ans = "";
                        for(int i = 0; i < nums1.size(); i++) {
                            string sub = nums[nums1[i].second] + " ";
                            ans.append(sub);
                            if(i == nums1.size() - 1) ans.pop_back();
                        }
                        ans[0] -= 32;
                        return ans;
                    }
                };
