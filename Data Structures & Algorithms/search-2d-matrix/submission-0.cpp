class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size() - 1, mid;

        while (l <= r) {
            mid = (l+r) / 2;
            cout << l << " " << r << endl;
            if (bs(matrix[mid], target)) {
                return true;
            } else if (matrix[mid][0] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }

    bool bs(vector<int>& arr, int target) {
        int l=0, r=arr.size()-1;
        int mid;

        while (l <= r) {
            mid = (l+r) / 2;

            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};
