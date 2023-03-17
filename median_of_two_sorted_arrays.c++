class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        int arr[nums1.size()+nums2.size()];
        int i=0,j=0,k=0;
        while(k<n){
            if(i>=nums1.size())
                arr[k++]=nums2[j++];
            else if(j>=nums2.size())
                arr[k++]=nums1[i++];
            else if(nums1[i]<=nums2[j])
                arr[k++]=nums1[i++];
            else
                arr[k++]=nums2[j++];
        }
        if(n%2==1)
            return arr[n/2];
        return (double)(arr[n/2-1]+arr[n/2])/2;
    }
};
