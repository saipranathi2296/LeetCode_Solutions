// Last updated: 7/6/2026, 12:07:34 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> result;
        result.push_back(0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=gain[i];
            result.push_back(sum);

        }
   return *max_element(result.begin(),result.end());

    }
};