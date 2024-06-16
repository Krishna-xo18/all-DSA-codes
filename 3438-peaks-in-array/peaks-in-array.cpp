#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
   

    int countElementsInRange(const set<int>& s, int lower, int upper) {
        auto lower_it = s.lower_bound(lower);
        auto upper_it = s.upper_bound(upper);
        return distance(lower_it, upper_it);
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        ordered_set peaks;

        // Precompute peaks
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (i > 0 && i < nums.size() - 1 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peaks.insert(i);
            }
        }

        vector<int> ans;
        for (const auto& query : queries) {
            if (query[0] == 1) {
                // Query type 1: count peaks in range
                int l=query[1];
                int r=query[2];
                if(r-l<2) ans.push_back(0);
                else ans.push_back(peaks.order_of_key(r)-peaks.order_of_key(l+1));
            } else if (query[0] == 2) {
                // Query type 2: update value at index
                int indexi = query[1];
                int vali = query[2];
                nums[indexi] = vali;

                // Update peak information for indexi and its neighbors
                for (int j = max(1, indexi - 1); j <= min((int)nums.size() - 2, indexi + 1); ++j) {
                    if (j > 0 && j < nums.size() - 1 && nums[j] > nums[j - 1] && nums[j] > nums[j + 1]) {
                        peaks.insert(j);
                    } else {
                        peaks.erase(j);
                    }
                }
            }
        }

        return ans;
    }
};