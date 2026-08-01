// Problem Link: 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int acual_rotations = k % nums.size();
        if(acual_rotations == 0)
          return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+acual_rotations);
        reverse(nums.begin()+acual_rotations, nums.end());
    }
};

int main(void){

}