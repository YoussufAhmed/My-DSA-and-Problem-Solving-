#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Max=0;
        int Counter=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                Counter++;
                Max = max(Counter, Max);
            }
            else{
                Counter=0;
            }
        }
        return Max;
    }
};

int main(void){
    Solution s;

    vector<int> nums {0, 0, 1, 1, 1, 0, 1};
    int res = s.findMaxConsecutiveOnes(nums);
    return res;
}