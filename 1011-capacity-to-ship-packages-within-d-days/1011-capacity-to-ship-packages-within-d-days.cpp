class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int currentWeight = 0;
        int daysSpent = 1;

        for (auto weight: weights) {
            if (currentWeight + weight > capacity) {
                currentWeight = 0;
                daysSpent++;
            }
            currentWeight += weight;
        }
        return daysSpent <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0;
        for (auto weight: weights) {
            total += weight;
        }
        int s = *max_element(weights.begin(), weights.end());
        int e = total;
        int ans = total;

        while (s <= e) {
            int mid = s + (e-s)/2;

            if (canShip(weights, days, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};