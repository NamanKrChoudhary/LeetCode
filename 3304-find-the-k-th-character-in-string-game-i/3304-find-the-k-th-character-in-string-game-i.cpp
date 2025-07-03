class Solution {
public:
    char kthCharacter(int k) {
        long long int temp = k;
        long long int steps = 0;
        while(temp > 1)
        {
            long long int curr = 1;
            while((curr*2)<temp) curr = curr*2;
            if(temp%curr == 0) temp = temp/2;
            else temp = temp%curr;
            steps = steps + 1;
        }
        steps = steps%26;
        char c = 'a'+steps;
        return c;
    }
};