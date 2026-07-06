// Last updated: 7/6/2026, 12:07:30 PM
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat[0].size()-1;
        vector<int>result;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int maxrow=0;
            for(int i=0;i<mat.size();i++)
            {
                if(mat[i][mid]>mat[maxrow][mid])
                {
                    maxrow=i;
                }
            }
            int left=(mid-1>0)?mat[maxrow][mid-1]:-1;
            int right=(mid+1<mat[0].size())?mat[maxrow][mid+1]:-1;
            if(mat[maxrow][mid]>left && mat[maxrow][mid]>right)
            {
                return {maxrow,mid};
            }
                else if(right>mat[maxrow][mid])
                {
low=mid+1;
                }
                else
                {
                    high=mid-1;
        }
        }
        return {-1,-1};
            
        }
    };
// };
// Pick the middle column
// In that column, find the row with the maximum value
// This ensures:
// The chosen cell is already greater than up & down
// Now compare this cell with:
// Left neighbor
// // Right neighbor
// ← smaller   PEAK   smaller →
// ✅ This is a peak → return it.

// Case 2: Right neighbor is bigger
// css
// Copy code
// PEAK < right
// ➡️ Move right

// A peak must exist on the right side

// Case 3: Left neighbor is bigger
// css
// Copy code
// left > PEAK
// ⬅️ Move left

// A peak must exist on the left side