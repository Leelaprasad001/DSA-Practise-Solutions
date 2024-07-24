class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (right - left >= k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;
            } else {
                right--;
            }
        }
        vector<int> res(arr.begin() + left, arr.begin() + left + k);
        return res;
    }
};