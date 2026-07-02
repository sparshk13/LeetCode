class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int speed) {
        long long time = 0;

        for (auto pile: piles) {
            time += (pile + speed - 1) / speed;
            if (time > h) {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(), piles.end());
        int s = 1;
        int e = max;
        int ans = e;

        while (s <= e) {
            int mid = s + (e-s)/2;

            if (canFinish(piles, h, mid)) {
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