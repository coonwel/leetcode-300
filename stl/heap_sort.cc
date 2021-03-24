class Solution {
public:
    void heapsort(std::vector<int>& nums) {
        for (int i = nums.size()/2; i >= 0; i--) {
            adjustHeap(nums, i, nums.size());
        }

        for (int j = nums.size()-1; j > 0; j--) {
            std::swap(nums[0], nums[j]);
            adjustHeap(nums, 0, j);
        }
    }

    // 迭代版本
    void adjustHeap(std::vector<int>& nums, int parent, int length) {
        int temp = nums[parent];
        int child = 2*parent+1;
        while (child < length) {
            if (child+1<length && nums[child] < nums[child+1]) {
                child++;
            }

            if (temp >= nums[child]) {
                break;
            }

            nums[parent] = nums[child];
            parent = child;
            child = 2*child+1;
        }
        nums[parent] = temp;
    }

    // 递归版本
    void adjustHeapII(std::vector<int>& nums, int parent, int length) {
        int largest = parent;
        int left = 2*parent+1;
        int right = 2*parent+2;
        if (left < length && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < length && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != parent) {
            std::swap(nums[largest], nums[parent]);
            adjustHeapII(nums, largest, length);
        }
    }
};

