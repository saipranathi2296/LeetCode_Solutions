// Last updated: 7/6/2026, 12:08:05 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq;

        for(int i=0;i<n;i++)
        {
pq.push(stones[i]);
        }
        while(!pq.empty()&& pq.size()>1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x<=y)
            {
                pq.push(y-x);

            }
            else if(y<=x)
            {
                pq.push(x-y);
            }
           

        }
        return pq.top();
    }
};