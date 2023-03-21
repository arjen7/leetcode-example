class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long result=0;
        int counter=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                result+=++counter;
            }
            else
                counter=0;
        }
        return result;
        
    }
};
