class Solution {
    // Custom MultiSet that does zero heap allocations.
    // Uses hardware bitwise operations to find min/max in O(1) time.
    struct FastMultiSet {
        int freq[1505];
        uint64_t mask[24]; // 24 * 64 = 1536 (enough for 1500 unique elements)
        int sz;
        
        FastMultiSet() {
            memset(freq, 0, sizeof(freq));
            memset(mask, 0, sizeof(mask));
            sz = 0;
        }
        
        inline void insert(int v) {
            if (freq[v] == 0) {
                mask[v >> 6] |= (1ULL << (v & 63));
            }
            freq[v]++;
            sz++;
        }
        
        inline void erase(int v) {
            freq[v]--;
            if (freq[v] == 0) {
                mask[v >> 6] &= ~(1ULL << (v & 63));
            }
            sz--;
        }
        
        inline int get_min() const {
            for (int i = 0; i < 24; ++i) {
                if (mask[i]) {
                    // Find the lowest set bit using GCC built-in
                    return (i << 6) + __builtin_ctzll(mask[i]); 
                }
            }
            return -1;
        }
        
        inline int get_max() const {
            for (int i = 23; i >= 0; --i) {
                if (mask[i]) {
                    // Find the highest set bit using GCC built-in
                    return (i << 6) + 63 - __builtin_clzll(mask[i]);
                }
            }
            return -1;
        }
        
        inline int size() const { return sz; }
        inline bool empty() const { return sz == 0; }
    };

public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxx = -1e18; // Increased safety bound
        
        // 1. Coordinate Compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        
        vector<int> ids(n);
        long long total_sum = 0;
        FastMultiSet master_out;
        
        for(int i = 0; i < n; i++) {
            ids[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
            total_sum += nums[i];
            master_out.insert(ids[i]);
        }
        
        // 2. Your Exact Logic
        for(int i = 0; i < n; i++) {
            FastMultiSet in, outswap, inswap;
            FastMultiSet out = master_out;
            long long outsum = total_sum;
            long long insum = 0, inswapsum = 0, outswapsum = 0;
            
            for(int j = i; j < n; j++) {
                int id = ids[j];
                long long val = nums[j];
                
                in.insert(id);
                insum += val;
                
                if(out.freq[id] > 0) {
                    out.erase(id);
                    outsum -= val;
                }
                else if(outswap.freq[id] > 0) {
                    outswap.erase(id);
                    outswapsum -= val;
                    
                    int ins_id = inswap.get_max();
                    long long ins_val = vals[ins_id];
                    inswap.erase(ins_id);
                    inswapsum -= ins_val;
                    
                    in.insert(ins_id);
                    insum += ins_val;
                }
                
                while(!inswap.empty() && !in.empty()) {
                    int curr_id = inswap.get_max();
                    int curr1_id = in.get_min();
                    if(vals[curr1_id] < vals[curr_id]) {
                        long long curr_val = vals[curr_id];
                        inswap.erase(curr_id);
                        inswapsum -= curr_val;
                        
                        long long curr1_val = vals[curr1_id];
                        in.erase(curr1_id);
                        insum -= curr1_val;
                        
                        inswap.insert(curr1_id);
                        inswapsum += curr1_val;
                        
                        in.insert(curr_id);
                        insum += curr_val;
                    } else {
                        break;
                    }
                }
                
                while(outswap.size() < k && !out.empty() && !in.empty()) {
                    int curr1_id = in.get_min();
                    int curr_id = out.get_max();
                    if(vals[curr1_id] < vals[curr_id]) {
                        long long curr1_val = vals[curr1_id];
                        in.erase(curr1_id);
                        insum -= curr1_val;
                        
                        inswap.insert(curr1_id);
                        inswapsum += curr1_val;
                        
                        long long curr_val = vals[curr_id];
                        out.erase(curr_id);
                        outsum -= curr_val;
                        
                        outswap.insert(curr_id);
                        outswapsum += curr_val;
                    } else {
                        break;
                    }
                }
                
                maxx = max(maxx, insum + outswapsum);
            }
        }
        
        return maxx;
    }
};