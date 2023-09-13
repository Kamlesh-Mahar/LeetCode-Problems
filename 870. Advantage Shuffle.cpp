class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ord = vector<int>(B.size()), ans = vector<int>(A.size());
        
        for (int i = 0; i < B.size(); i++) ord[i] = i;

        sort(ord.begin(), ord.end(), [&](int a, int b) {return B[a] > B[b];});
        sort(A.begin(), A.end(), greater<>());

        int i = 0, j = B.size() - 1;
        for (int ix : ord)
            ans[ix] = A[i] > B[ix] ? A[i++] : A[j--];
        return ans;
    }
};