bool compareDesc(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i <= n - k; i++) {
            vector<int> subArray(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> freq;

            for (int num : subArray)
                freq[num]++;

            vector<pair<int, int>> arr(freq.begin(), freq.end());
            sort(arr.begin(), arr.end(), compareDesc);
            int sum = 0;
            for (int j = 0; j < min(x, (int)arr.size()); j++)
                sum += arr[j].first * arr[j].second;

            result.push_back(sum);
        }

    return result;
    };
};