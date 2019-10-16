class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []
        lenth = len(nums)
        for i in range(0, lenth):
            for j in range(i + 1, lenth):
                if nums[i] + nums[j] == target:
                    result.append(i)
                    result.append(j)
                    
        return result

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for i in range(0, len(nums)):
            hashmap[nums[i]] = i
        for i in range(0, len(nums)):
            if((target - nums[i]) in hashmap):
                if(hashmap[target - nums[i]] != i):
                    return [i, hashmap[target - nums[i]]]
            
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for i in range(0, len(nums)):
            if((target - nums[i]) in hashmap):
                return [i, hashmap[target - nums[i]]]
            else:
                hashmap[nums[i]] = i
#为什么方法3的时间要更久一些呢？这个网站的错误？