// Last updated: 7/6/2026, 12:08:09 PM
class Solution {
public:
   bool check(vector<int>& weights, int day, int cap)
{
    int sum = 0;
    int total = 1;   // start from day 1

    for(int i : weights)
    {
        sum += i;
        if(sum > cap)
        {
            total++;
            sum = i;
        }
    }
    return total <= day;
}


    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
