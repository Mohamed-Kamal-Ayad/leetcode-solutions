class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
            1- init 2 pointers
                - p1 -> start array
                - p2 -> end array
            2- loop over SORTED array
                - sum numbers[p1] + numbers[p2]
                - if sum == target return {p1,p2}
                - elif sum > target -> p2--
                - else -> p1++
        */

        int p1 = 0, p2 = numbers.size() - 1;

        for (int i = 0; i < numbers.size(); i++) {
            int sum = numbers[p1] + numbers[p2];
            if (sum == target)
                break;
            else if (sum > target)
                p2--;
            else
                p1++;
        }
        return {++p1, ++p2};
    }
};