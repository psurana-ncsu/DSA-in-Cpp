class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> ct(nums.size() + 1, 0);
        int m = 1000000007;

        // Increment start points and decrement end+1 points
        for (int i = 0; i < requests.size(); i++) {
            ct[requests[i][0]]++;
            if (requests[i][1] + 1 < ct.size()) {
                ct[requests[i][1] + 1]--;
            }
        }

        // Compute the prefix sums
        for (int i = 1; i < ct.size(); i++) {
            ct[i] += ct[i - 1];
        }

        // Remove the extra element we added initially for easier computation
        ct.pop_back();

        // Sort the frequency and nums arrays in descending order
        sort(ct.begin(), ct.end(), greater<int>());
        sort(nums.begin(), nums.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (ct[i] == 0) {
                break;
            }
            ans = (ans + (long long)ct[i] * nums[i]) % m;
        }

        return ans;
    }
};

