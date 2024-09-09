class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        long int hours = 0;
        int res = INT_MAX;
        int low = 1, high = piles[piles.size() - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            for (auto p : piles) {
                hours += ceil((double)p / mid);
            }
            if (hours <= h) {
                res = min(res, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            hours = 0;
        }
        return res;
    }
};