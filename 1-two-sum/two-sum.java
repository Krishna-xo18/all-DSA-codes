class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] old = Arrays.copyOf(nums, nums.length);
        Arrays.sort(nums);
        int start = 0;
        int end = nums.length - 1;
        int ans1 = 0;
        int ans2 = 0;
        while (start < end) {
            if ((nums[start] + nums[end]) == target) {
                ans1 = nums[start];
                ans2 = nums[end];
                break;
            } else if (nums[start] + nums[end] < target) {
                start++;
            } else {
                end--;
            }
        }
        List<Integer> finalAnsList = new ArrayList<>();
        for (int i = 0; i < old.length; i++) {
            if (ans1 == old[i]) {
                finalAnsList.add(i);
            } else if (ans2 == old[i]) {
                finalAnsList.add(i);
            }
        }
        // Convert List<Integer> to int[]
        int[] finalAns = new int[finalAnsList.size()];
        for (int i = 0; i < finalAnsList.size(); i++) {
            finalAns[i] = finalAnsList.get(i);
        }
        return finalAns;
    }
}