class Solution {

// most basic logic - we start from the left and start to check for zeroes
// let the window start from the first and foremost 0 that we find and flip the whole k length bits. now check for immediate next
// zero after the flipping is over. this means we check the flipped bits too. such as if 1 is flipped to zero we perform the next 
// operation taking this element as the first.

// we check how many times has a character been changed. we check it by maintaining
// an array with the index of last element affected by each of the change that happened. we remove the elements 
// that are less than the current index meaning that the effect of those changes is not on the current element.
// no we check the size of the array with no of changes and check if its even or odd.
// if its even this means the current elements must be treated as it is meaning they have been flipped even times.
// if its odd this means current elemets must be treated opposite to that of current element.
// now if we have any element that needs to be changed inside the last window means these cant be changed ie -1;
public:
    int minKBitFlips(vector<int>& nums, int k) {
        deque<long long int> arr;
        long long int ans = 0;
        long long int n = nums.size();
        for(int i=0; i<n; i++)
        {
            while(!arr.empty() && arr[0]<i) arr.pop_front();
            if(arr.empty() || arr.size()%2 == 0)
            {
                if(nums[i] == 0)
                {
                    if(i > (n-k) && i<n) {ans = -1; break;}
                    ans = ans + 1;
                    arr.push_back(i+k-1);
                }
            }
            else if(arr.size()%2 == 1)
            {
                if(nums[i] == 1)
                {
                    if(i > (n-k) && i<n) {ans = -1; break;}
                    ans = ans + 1;
                    arr.push_back(i+k-1);
                }
            }
        }
        return ans;
    }
};