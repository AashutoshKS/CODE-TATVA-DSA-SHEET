//PROBLEM :

      Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.
      
      A group of duplicate files consists of at least two files that have the same content.
      
      A single directory info string in the input list has the following format:
      
      "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
      It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
      
      The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
      
      "directory_path/file_name.txt"



//APPROACH :
        For all the different file by seperating each string on the basis of spaces " ", 
        for each text content initialise its index and store in map.
        Check the file which are repeated and store in the array 

        since we only have to store the ambiguous data..... delete the index which do not have ambiguous contentt..




//CODE :
      class Solution {
      public:
          vector<vector<string>> findDuplicate(vector<string>& paths) {
              vector<vector<string>>ans;
              map<string, int>mp;
              int idx = 1;
              for(int i = 0; i < paths.size(); i++) {
                  string temp;
                  vector<string>parts;
                  stringstream ss(paths[i]);
                  while (getline(ss, temp, ' ')) {
                      parts.push_back(temp);
                  }
                  string sub = "";
                  string file = "";
                  int br = 0;
                  for(int j = 1; j < parts.size(); j++) {
                      for(int k = 0;k < parts[j].size(); k++) {
                          if(parts[j][k] == '(') {
                              br = 1;
                              continue;
                          }
                          if(br == 1) {
                              file += parts[j][k];
                          } else {
                              sub += parts[j][k];
                          }
                      }
                      string add = parts[0] + "/" + sub;
                      if(mp[file] == 0) {
                          ans.push_back({});
                          mp[file] = idx;
                          ans[idx - 1].push_back(add);
                          idx++;
                      } else {
                          int cidx = mp[file] - 1;
                          ans[cidx].push_back(add);
                      }
                      sub = "", file = "", br = 0;
                  }   
              }
              for(int i = 0;i < ans.size(); i++) {
                  if(ans[i].size() == 1) {
                      ans.erase(ans.begin() + i);
                      i--;
                  }
              }
              return ans;
          }
      };
