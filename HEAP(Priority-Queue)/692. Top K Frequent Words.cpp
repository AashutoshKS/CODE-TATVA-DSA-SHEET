//PROBLEM :
                    
            Given an array of strings words and an integer k, return the k most frequent strings.
            
            Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.



//APPROACH :
              store each word and its count in max heap, using a map
              return k most frequency element in lexicographically sorted order


//CODE 1:

                  class Solution {
                  public:
                      vector<string> topKFrequent(vector<string>& words, int k) {
                          priority_queue<pair<int,string>>pq;
                          unordered_map<string,int>mp;
                          for(int i = 0;i < words.size(); i++) {
                              mp[words[i]]++;
                          }
                          for(auto& it:mp) {
                              pq.push({it.second,it.first});
                          }
                          vector<string>ans;
                          int key = 0,val = 0;
                          int k1 = k;
                          while(!pq.empty()) {
                              vector<pair<int,string>>nums;
                              if(ans.size() == k && (mp[ans.back()] != pq.top().first)) break;
                              while(ans.size() > 0 && pq.top().first == mp[ans.back()] && ans.back() > pq.top().second) {
                                  string s = ans.back();
                                  ans.pop_back();
                                  nums.push_back({mp[s],s});
                              }
                              ans.push_back(pq.top().second);
                              pq.pop();
                              for(int i = 0;i < nums.size(); i++) pq.push(nums[i]);
                          }
                          return vector(ans.begin(),ans.begin() + k);
                      }
                  };

------------------------------------------------------------------------------------------------------------------------------------------------------------
//CODE 2;
                  class Solution {
                  public:
                      vector<string> topKFrequent(vector<string>& words, int k) {
                          priority_queue<pair<int,string>>pq;
                          map<string,int>mp;
                          for(int i = 0;i < words.size(); i++) {
                              mp[words[i]]++;
                          }
                          for(auto& it:mp) {
                              pq.push({it.second,it.first});
                          }
                          vector<string>ans;
                          int key = 0,val = 0;
                          int k1 = k;
                          while(!pq.empty()) {
                              if(key == 1 && val != pq.top().first) break;
                              ans.push_back(pq.top().second);
                              k1--;
                              if(k1 == 0) {
                                  key = 1;
                                  val = pq.top().first;
                              }
                              pq.pop();
                          }
                          int i = 0,j = 1;
                          for(j = 1;j < ans.size(); j++) {
                              if(mp[ans[j]] != mp[ans[j-1]]) {
                                  sort(ans.begin() + i,ans.begin() + j);
                                  i = j;
                              }
                          }
                          sort(ans.begin() + i,ans.begin() + j);
                          return vector(ans.begin(),ans.begin() + k);
                      }
                  };
