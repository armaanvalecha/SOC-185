class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int len = nums.size();
if(len==1) return 0;
if(nums[0] > nums[1]) return 0;
if(nums[len-1] > nums[len-2]) return len-1;
int low = 1, high = len-2;
while(low <= high){
int mid = low + (high-low)/2;
if(nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]) return mid;
else if(nums[mid] > nums[mid-1]) low = mid+1;
else high = mid -1;
}
return -1; 
    }
};