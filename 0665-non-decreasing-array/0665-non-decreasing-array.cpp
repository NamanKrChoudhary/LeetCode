class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool check1 = true;
        vector<int> arr = nums;
        if(nums.size() == 1 || nums.size() == 2) return true;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]<arr[i-1]){ arr[i] = arr[i-1]; break;}
        }
        for(int i=1; i<arr.size(); i++) if(arr[i] < arr[i-1]) check1 = false;
        arr = nums;
        bool check3 = true;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]<arr[i-1]){ arr[i-1] = arr[i]; break;}
        }
        for(int i=1; i<arr.size(); i++) if(arr[i] < arr[i-1]) check3 = false;
        arr = nums;
        bool check2 = true;
        for(int i=arr.size()-1; i>=1; i--)
        {
            if(arr[i]<arr[i-1]){ arr[i] = arr[i-1]; break;}
        }
        for(int i=arr.size()-1; i>=1; i--) if(arr[i] < arr[i-1]) check2 = false;
        arr = nums;
        bool check4 = true;
        for(int i=arr.size()-1; i>=1; i--)
        {
            if(arr[i]<arr[i-1]){ arr[i-1] = arr[i]; break;}
        }
        for(int i=arr.size()-1; i>=1; i--) if(arr[i] < arr[i-1]) check4 = false;
        if(check1 || check2 || check3 || check4) return true;
        else return false;
    }
};