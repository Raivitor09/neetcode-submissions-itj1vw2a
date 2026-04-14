class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) { // Mantemos < ao invés de <= para evitar problemas de indexação
            int mid = left + (right - left) / 2;

            if (nums[left] <= nums[right]) {  
                return nums[left];  
            }

            if (nums[mid] < nums[right]) { // Se mid for menor que right, o mínimo está à esquerda ou no próprio mid
                right = mid;  
            } else {
                left = mid + 1;
            }
        }

        return nums[left]; // Retorna o menor valor
    }
};
