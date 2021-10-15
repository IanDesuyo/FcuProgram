def main():
    nums = [int(i) for i in input().split(" ")]
    nums.sort()

    if (nums[0]**2 + nums[1]**2 == nums[2]**2):
        print("right triangle")
    elif (nums[0]**2 + nums[1]**2 < nums[2]**2):
        print("obtuse triangle")
    elif (nums[0]**2 + nums[1]**2 > nums[2]**2):
        print("acute triangle")

main()