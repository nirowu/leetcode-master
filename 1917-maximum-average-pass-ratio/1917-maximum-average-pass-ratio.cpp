using info = tuple<double, int, int>;
info A[100005];

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        const int n = classes.size();
        int idx = 0; double sum = 0.0;
        for (auto& pq: classes) {
            int p = pq[0], q = pq[1];
            sum += (double) p/q;
            double inc = (double)(q - p) / (q * (q + 1.0));
            A[idx++] = {inc, p, q};
        }
        make_heap(A, A+n);

        while(extraStudents--) {
            pop_heap(A, A+n);
            auto [inc, p, q] = A[n-1];
            if (inc == 0) break; 

            sum += inc; 
            double newInc = (double)(q - p) / ((q + 1.0) * (q + 2.0));
            A[n-1] = {newInc, p+1, q+1};
            push_heap(A, A+n);
        }
        return sum/n;
    }
};