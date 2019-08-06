#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sm = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] <= target){
                continue;
            }
            else
            {
                sm = i;
                break;
            }
        }
        vector<int> r;

        for(int i = 0; i < sm / 2; i++){
            for ( int j = 0; j < sm / 2; j++)
            {
                if (nums[i] + nums[j] == target){
                    r.push_back(i);
                    r.push_back(j);
                    break;
                }
            }
        }

        return r;
    }
};