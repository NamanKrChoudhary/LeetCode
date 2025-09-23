class Solution {
public:
    int compareVersion(string version1, string version2) {
        string v1 = version1, v2 = version2;
        long long int dots1 = 0, dots2 = 0;
        for(int i=0; i<v1.size(); i++) if(v1[i] == '.') dots1++;
        for(int i=0; i<v2.size(); i++) if(v2[i] == '.') dots2++;
        if(dots1 > dots2)
        {
            for(int i=0; i<dots1-dots2; i++)
            {
                v2.push_back('.');
                v2.push_back('0');
            }
        }
        else if(dots2 > dots1)
        {
            for(int i=0; i<dots2-dots1; i++)
            {
                v1.push_back('.');
                v1.push_back('0');
            }
        }
        int j = 0, k=0;
        for(int i=0; i<=max(dots1, dots2); i++)
        {
            string curr1 = "";
            string curr2 = "";
            while(j < v1.size() && v1[j] != '.')
            {
                curr1.push_back(v1[j]);
                j++;
            }
            j++;
            while(k < v2.size() && v2[k] != '.')
            {
                curr2.push_back(v2[k]);
                k++;
            }
            k++;
            long long int c1 = stoll(curr1);
            long long int c2 = stoll(curr2);
            if(c1 < c2) return -1;
            else if(c2 < c1) return 1;
        }
        return 0;
    }
};