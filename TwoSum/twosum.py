from textwrap import indent


class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for numindex in range(len(nums)):
            for index in range(numindex + 1, len(nums)):
                if nums[numindex] + nums[index] == target:
                    return [numindex, index]
        
        return []

solution = Solution()

print(solution.twoSum([2, 7, 11, 15], 9))
print(solution.twoSum([3, 3], 6))
print(solution.twoSum([3, 3], 5))
