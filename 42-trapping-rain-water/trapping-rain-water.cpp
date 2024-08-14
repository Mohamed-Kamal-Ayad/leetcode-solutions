class Solution {
public:
    int trap(vector<int>& height) {
        int w = 0;
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        if (height.size() < 3)
            return 0;
        while (l < r) {
            if (leftMax <= rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                w += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                w += rightMax - height[r];
            }
        }

        return w;
    }
};