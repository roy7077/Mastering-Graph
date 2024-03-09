class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        vector<string> usedLevel;
        queue<vector<string>> q;
        usedLevel.push_back(beginWord);
        q.push(usedLevel);
        int level=0;
        
        while(!q.empty())
        {
            vector<string> vec=q.front();
            q.pop();
            
            string word=vec[vec.size()-1];
            
            if(vec.size()>level)
            {
                level++;
                for(auto it:usedLevel)
                st.erase(it);
                
                usedLevel.clear();
            }
            
            if(word==endWord)
            {
                if(ans.empty())
                {
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size())
                ans.push_back(vec);
                else
                continue;
            }
            
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.count(word))
                    {
                        usedLevel.push_back(word);
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                    }
                }
                
                word[i]=original;
            }
            
            
        }
        
        return ans;
    }
};