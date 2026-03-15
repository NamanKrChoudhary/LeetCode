const long long int mod = 1e9+7;

long long int modexp(long long int a, long long int b)
{
    long long int res = 1;
    while(b > 0)
    {
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b = b/2;
    }
    return res;
}
class Fancy {
public:
    vector<long long int> arr;
    vector<long long int> mul;
    vector<long long int> add;
    long long int currmul = 1, curradd = 0;
    Fancy() {
        arr = {};
        mul = {};
        add = {};
    }
    
    void append(int val) {
        arr.push_back(val);
        mul.push_back(currmul);
        add.push_back(curradd);
    }
    
    void addAll(int inc) {
        curradd = (curradd + inc)%mod;
    }
    
    void multAll(int m) {
        currmul = (currmul*m)%mod;
        curradd = (curradd*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        long long int tempmul = (currmul*modexp(mul[idx], mod-2))%mod;
        long long int tempadd = (curradd-((add[idx]*tempmul)%mod)+mod)%mod;
        long long int req = (((arr[idx]*tempmul)%mod)+tempadd)%mod;
        // cout << idx << endl;
        // cout << curradd << " " << add[idx] << " " << tempadd << endl;
        // cout << currmul << " " << mul[idx] << " " << modexp(mul[idx], mod-2) << " " << tempmul << endl;
        // cout << req << endl;
        // cout << endl;
        return req;
    }
    // 7
    // 4
    // 6
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */