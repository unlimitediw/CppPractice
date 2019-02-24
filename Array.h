#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSumMap(vector<int> &nums, int target) {
        vector<int> res;
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            auto it = dic.find(target - nums.at(i));
            if (it != dic.cend()) {
                res.push_back(dic[target - nums.at(i)]);
                res.push_back(i);
                break;
            }
            dic[nums.at(i)] = i;
        }
        return res;
    }
};