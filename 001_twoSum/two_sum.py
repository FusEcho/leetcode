import os


def twoSum(nums, target):
    print(nums)
    hashmap = {}
    for i, num in enumerate(nums):
        if hashmap.get(target - num) is not None:
            return [i, hashmap.get(target - num)]

        hashmap[num] = i


if __name__ == '__main__':
    a = twoSum([3, 2, 4], 6)
    print(a)
