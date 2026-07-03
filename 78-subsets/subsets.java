class Solution {
    List<List<Integer>>result = new ArrayList<>();
    ArrayList<Integer> empty = new ArrayList<>();
    public void solve(int i,int[]nums){
        if(i==nums.length){
            result.add(new ArrayList<>(empty));
            return;
        }
        empty.add(nums[i]);
        solve(i+1,nums);
        empty.remove(empty.size()-1);
        solve(i+1,nums);
    }
    public List<List<Integer>> subsets(int[] nums) {
        solve(0,nums);
        return result;
    }
}