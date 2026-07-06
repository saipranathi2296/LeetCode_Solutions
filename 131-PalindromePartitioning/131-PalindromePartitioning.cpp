// Last updated: 7/6/2026, 12:10:22 PM
class Solution {
    void solve(int index,string s,vector<vector<string>> &ans,vector<string> &res)
    {
        if(index==s.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if (isp(s,index,i))
            {
                res.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,res);
                res.pop_back();
            }
        }
    }
    bool isp(string m, int start,int end)
    {
        while(start<=end)
        {
            if(m[start++]!=m[end--]) 
            {
                return false;
               
            }
            
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        solve(0,s,ans,res);
        return ans;
    }

};