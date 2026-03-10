#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_set<char> st;
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words[i].size(); j++) {
                st.insert(words[i][j]);
            }
        }
        vector<list<int>> graph(26);
        vector<int> indeg(26,0);
        
        for(int i=0; i<words.size()-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            
            int len = min(s1.size(), s2.size());
            bool foundDiff = false;
            
            for(int j=0; j<len; j++) {
                if(s1[j] != s2[j]) {
                    graph[s1[j]-'a'].push_back(s2[j]-'a');
                    indeg[s2[j]-'a']++;
                    foundDiff = true;
                    break;
                }
            }
            if(!foundDiff && s1.size() > s2.size()) return "";
        }
        
        queue<int> q;
        for(auto ele : st) {
            int idx = ele - 'a';
            if(indeg[idx] == 0) q.push(idx);
        }
        
        string ans = "";
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            char ch = char(curr + 97);
            ans += ch;
            
            for(auto neighbor : graph[curr]) {
                indeg[neighbor]--;
                if(indeg[neighbor] == 0) q.push(neighbor);
            }
        }
        
        return (ans.size() == st.size() ? ans : "");
    }
};

int main() {
    int n;
    cin>>n;
    
    vector<string> words(n);

    for(int i=0; i<n; i++) {
        cin>>words[i];
    }

    Solution s;
    cout<<s.findOrder(words);

    return 0;
}