class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> arr(26,0);
        for(int i=0; i<text.size(); i++) arr[text[i]-'a']++;
        string s1 = "ban", s2 = "lo";
        int minn = text.size();
        for(int i=0; i<s1.size(); i++) minn = min(minn, arr[s1[i]-'a']);
        for(int i=0; i<s2.size(); i++) minn = min(minn, arr[s2[i]-'a']/2);
        return minn;
    }
};