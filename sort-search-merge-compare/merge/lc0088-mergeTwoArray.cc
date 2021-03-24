
void mergeTwoArray(vector<int>& A, int m, vector<int>& B, int n) {
    int i = n-1, j = m-1, k = m+n-1;
    while (i>=0 && j>=0) {
        A[k--] = (A[i] >= B[j]) ? A[i--] : B[j--];    
    }
    while (j>=0) {
        A[k--] = B[j--];
    }
}

