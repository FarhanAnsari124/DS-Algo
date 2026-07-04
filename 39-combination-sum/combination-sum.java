class Solution {
    List<List<Integer>> result = new ArrayList<>();
    public void solve(int i,int[] arr,ArrayList<Integer> empty,int target){
        if(target==0){
            result.add(new ArrayList<>(empty));
            return;
        }
        if(i>=arr.length || target<0){
            return;
        }
        empty.add(arr[i]);
        solve(i,arr,empty,target-arr[i]);
        empty.remove(empty.size()-1);
        solve(i+1,arr,empty,target);

    }
    public List<List<Integer>> combinationSum(int[] arr, int target) {
        int n=arr.length;
        ArrayList<Integer> empty = new ArrayList<>();
        solve(0,arr,empty,target);
        return result;
    }
}