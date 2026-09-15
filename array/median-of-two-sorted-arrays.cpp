class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;
        int mid = total / 2;

        int i = 0, j = 0;
        int count = 0;

        int curr = 0;
        int prev = 0;

        while(count <= mid)
        {
            prev = curr;

            // take from nums1
            if(j >= n || (i < m && nums1[i] <= nums2[j]))
            {
                curr = nums1[i];
                i++;
            }

            // take from nums2
            else
            {
                curr = nums2[j];
                j++;
            }

            count++;
        }

        if(total % 2 == 1)
            return curr;

        return ((double)prev + curr) / 2;
    }
};