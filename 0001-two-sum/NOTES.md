# 0001
用暴力法的話會太慢(two loop)花O(n)去找，可以用map去把要找的資訊記住，可以把答案想成一組對應的值(nums[i], target - nums[i])
​
- key 是target-nums[i],  value是i
- example 1
- `[2, 7, 11, 15] `
- mp[7] = 0, mp[2] = 1
- 因為j = 7時，mp 會去找裡面有沒有7, i = 0/nums[i] = 2有存起來則可以直接用