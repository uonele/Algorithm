class Solution:
    def smaller(self, a, b):
        return True if (str(a) + str(b)) < (str(b) + str(a)) else False
    def largestNumber(self, nums):
        result = ""
        for i in range(0,len(nums)):
            for j in range(i,len(nums)):
                if self.smaller(nums[i],nums[j]):
                    temp = nums[i]
                    nums[i] = nums[j]
                    nums[j] = temp
        for i in nums:
            result = result + str(i)
        if result[0]=='0':
            return '0'
        return result

if __name__ == '__main__':
    s = Solution()
    nums = [0, 1, 55, 7, 6, 5, 4, 3, 2, 1]
    print s.largestNumber(nums)