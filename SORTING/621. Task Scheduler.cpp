//PROBLEM :

          You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one
          task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
          
          Return the minimum number of CPU intervals required to complete all tasks.

            
//APPROACH :
            use greedy to pick the element with most frequency


//CODE :
        class Solution {
        public:
            int leastInterval(vector<char>& tasks, int n) {
                sort(tasks.begin(),tasks.end());
                int count = 1;
                priority_queue<int>pq;
                for(int i = 1;i < tasks.size(); i++) {
                    if(tasks[i] == tasks[i-1]) {
                        count++;
                    } else {
                        pq.push(count);
                        count = 1;
                    }
                }
                pq.push(count);
                int ans = 0;
                while(!pq.empty()) {
                    vector<int>fre;
                    int k = 0;
                    int c = n;
                    while(!pq.empty() && (c--) >= 0) {
                        if(pq.top() > 1) fre.push_back(pq.top() - 1);
                        k++;
                        pq.pop();
                    }
                    if(fre.size() == 0) ans += k;
                    else ans += n + 1;
                    for(int i = 0;i < fre.size(); i++) {
                        pq.push(fre[i]);
                    }
                }   
                return ans;
            }
        };
