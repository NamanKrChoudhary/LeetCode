class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() == 0) return 0;
        else if(nums1.size() == 0)
        {
            if(nums2.size()%2 == 1) return nums2[(nums2.size())/2];
            else 
            {
                double a = (nums2[nums2.size()/2]+ nums2[(nums2.size()/2)-1]);
                cout << a << endl;
                return a/2;
            }
        }
        else if(nums2.size() == 0)
        {
            if(nums1.size()%2 == 1) return nums1[(nums1.size())/2];
            else 
            {
                double a = (nums1[nums1.size()/2]+ nums1[(nums1.size()/2)-1]);
                return a/2;
            }
        }
        long long int s = min(nums1[0], nums2[0]), e = max(nums1[nums1.size()-1], nums2[nums2.size()-1]), mid = s + ((e-s)/2);
        long long int fno1 = 0, fno2 = 0;
        long long int req = ((nums1.size()+nums2.size())/2)+1, tot = nums1.size()+nums2.size();
        long long int nos = nums1.size()+nums2.size();
        double ans = 0;
        while(s<=e)
        {
            mid = s + ((e-s)/2);

            long long int no1 = 0;
            long long int s1 = 0, e1 = nums1.size()-1, mid1 = s1 + ((e1-s1)/2);
            while(s1<=e1)
            {
                mid1 = s1 + ((e1-s1)/2);
                if(nums1[mid1] > mid) {e1 = mid1-1;}
                else if(nums1[mid1] < mid){no1 = mid1+1; s1 = mid1+1;}
                else {no1 = mid1+1; s1 = mid1+1;}
            }
            long long int no2 = 0;
            long long int s2 = 0, e2 = nums2.size()-1, mid2 = s2 + ((e2-s2)/2);
            while(s2<=e2)
            {
                mid2 = s2 + ((e2-s2)/2);
                if(nums2[mid2] > mid) {e2 = mid2-1;}
                else if(nums2[mid2] < mid){no2 = mid2+1; s2 = mid2+1;}
                else {no2 = mid2+1; s2 = mid2+1;}
            }
            if(no1+no2 >= req) {ans = mid; fno1 = no1; fno2 = no2; e = mid-1;}
            else s = mid+1;
            cout << req << " " << no1 << " " << no2 << " " << mid << endl;
        }
        //cout << ans << " " << fno1 << " " << fno2 << endl;
        if(tot == 0) return 0;
        else if(tot%2 == 0)
        {
            long long int pno1 = lower_bound(nums1.begin(), nums1.end(), ans) - nums1.begin();
            long long int pno2 = lower_bound(nums2.begin(), nums2.end(), ans) - nums2.begin();
            cout << pno1 << " " << pno2 << " " << ans <<endl;
            if(pno1+pno2 < req-1) return ans;
            
            long long int prev = 0;

            if(pno1 == 0)
            {
                prev = nums2[pno2-1];
            }
            else if(pno2 == 0) prev = nums1[pno1-1];
            else 
            {
                prev = max(nums1[pno1-1], nums2[pno2-1]);
            }
            double anss = (ans+prev)/2;
            ans = anss;
        }
        return ans;

    }
};