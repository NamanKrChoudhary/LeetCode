class Solution {
    // Custom struct prevents the massive memory overhead of vectors/arrays in the PQ
    struct State {
        long long cost;
        int k;
        int16_t type;
        int16_t r;
        int16_t c;
        // Min-heap comparator
        bool operator>(const State& other) const {
            return cost > other.cost; 
        }
    };

public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        // Cap max teleports. You can never mathematically use more teleports than total cells.
        // Prevents memory allocation crashes if LeetCode tries to pass k = 10^9
        k = min(k, n * m); 

        // Flattened 2D DP tracking ONLY the max teleports remaining (Pareto Pruning)
        // type 0 = arrived via teleport, type 1 = arrived via normal move
        vector<int> max_k_0(n * m, -1);
        vector<int> max_k_1(n * m, -1);

        vector<array<int, 3>> cells;
        cells.reserve(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }
        sort(cells.begin(), cells.end());

        priority_queue<State, vector<State>, greater<State>> pq;
        vector<int> currmaxi(k + 1, 0);

        pq.push({0, k, 1, 0, 0});

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            long long currval = curr.cost;
            int currk = curr.k;
            int type = curr.type;
            int r = curr.r;
            int c = curr.c;
            int flat_idx = r * m + c;

            // EARLY EXIT: The absolute first time we pop the destination, it is mathematically 
            // guaranteed to be the minimum cost. Stop the entire algorithm instantly.
            if (r == n - 1 && c == m - 1) return currval;

            // Pareto Dominance POP Pruning
            if (type == 1) {
                if (currk <= max_k_1[flat_idx]) continue;
                max_k_1[flat_idx] = currk;
            } else {
                // If we arrived via teleport, it's dominated by BOTH an equal-k teleport 
                // AND an equal-k normal move (since normal moves can do more things).
                if (currk <= max_k_0[flat_idx] || currk <= max_k_1[flat_idx]) continue;
                max_k_0[flat_idx] = currk;
            }

            // Move Down
            if (r + 1 < n) {
                long long nextval = currval + grid[r + 1][c];
                // PUSH Pruning: Don't flood PQ if we already found a better path
                if (currk > max_k_1[(r + 1) * m + c]) {
                    pq.push({nextval, currk, 1, (int16_t)(r + 1), (int16_t)c});
                }
            }

            // Move Right
            if (c + 1 < m) {
                long long nextval = currval + grid[r][c + 1];
                if (currk > max_k_1[r * m + (c + 1)]) {
                    pq.push({nextval, currk, 1, (int16_t)r, (int16_t)(c + 1)});
                }
            }

            // Teleport Logic (Flawlessly amortized using your currmaxi logic)
            if (type == 1 && currk > 0) {
                while (currmaxi[currk] < cells.size() && grid[r][c] >= cells[currmaxi[currk]][0]) {
                    int nr = cells[currmaxi[currk]][1];
                    int nc = cells[currmaxi[currk]][2];
                    int next_flat = nr * m + nc;
                    
                    if (!(nr == r && nc == c)) {
                        int nextk = currk - 1;
                        if (nextk > max_k_0[next_flat] && nextk > max_k_1[next_flat]) {
                            pq.push({currval, nextk, 0, (int16_t)nr, (int16_t)nc});
                        }
                    }
                    currmaxi[currk]++;
                }
            }
        }

        return -1; 
    }
};