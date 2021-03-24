class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            long v1 = 0, v2 = 0; // in case of overflow.
            while (i < n1 && version[i] != '.')
                v1 = v1*10 + version[i]-'0';
            while (j < n2 && version[j] != '.')
                v2 = v2*10 + version[j]-'0';
            
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;

            i++; j++;
        }
        return 0;
    }
};
