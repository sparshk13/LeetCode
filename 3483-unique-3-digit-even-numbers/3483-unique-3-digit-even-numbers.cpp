class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> arr(10, 0);
        int count = 0;

        for (auto num: digits) {
            arr[num]++;
        }

        for (int h = 1; h <= 9; h++) {
            if (arr[h] == 0) continue;
            arr[h]--;

            for (int t = 0; t <= 9; t++) {
                if (arr[t] == 0) continue;
                arr[t]--;

                for (int o = 0; o < 9; o += 2) {
                    if (arr[o] == 0) continue;
                    count++;
                }
                arr[t]++;
            }
            arr[h]++;
        }
        return count;
    }
};