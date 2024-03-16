class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count = 0
        x = 0
        res = {0:-1}

        for i in range(len(nums)):
            num = nums[i]
            if num == 0:
                count -=1
            else:
                count +=1
            
            if count in res:
                x = max(x,i-res[count])
            else:
                res[count] = i
        return x

        