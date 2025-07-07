from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        global num1_right_min, num2_left_max
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        size = len(nums1) + len(nums2)
        left_count = (size + 1) // 2

        # 二分找邊界拆分
        l, r = 0, len(nums1)

        # 左 bad 右 good
        while True:
            i = (l + r) // 2
            j = left_count - i

            # max(A左最大，B左最大) <= min(A右最小，B最小)
            num1_left_max = nums1[i-1] if i > 0 else -float("inf")
            num1_right_min = nums1[i] if i < len(nums1) else float("inf")
            num2_left_max = nums2[j - 1] if j - 1 >= 0 else -float("inf")
            nums2_right_min = nums2[j] if j < len(nums2) else float("inf")

            if num1_left_max <= nums2_right_min and num2_left_max <= num1_right_min:
                if size & 1:  # odd
                    return max(num1_left_max, num2_left_max)
                else: #even
                    return (max(num1_left_max, num2_left_max) + min(num1_right_min, nums2_right_min)) / 2
            elif num1_left_max > nums2_right_min:
                    r = i - 1
            else:
                    l = i + 1