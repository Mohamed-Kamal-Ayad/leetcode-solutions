class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target >= matrix[mid][0] &&
                target <= matrix[mid][matrix[mid].size() - 1]) {
                int arrIndex = mid;
                int lowArr = 0;
                int highArr = matrix[arrIndex].size() - 1;
                while (lowArr <= highArr) {
                    int mid = lowArr + (highArr - lowArr) / 2;
                    if (matrix[arrIndex][mid] == target)
                        return true;
                    else {
                        if (target > matrix[arrIndex][mid])
                            lowArr = mid + 1;
                        else
                            highArr = mid - 1;
                    }
                }
                return false;
            } else if (target < matrix[mid][0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};