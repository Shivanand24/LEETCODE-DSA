class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        List<Integer> criticals = new ArrayList<>();
        ListNode prev = head, curr = head.next;
        int idx = 1;
        
        while (curr.next != null) {
            if ((curr.val > prev.val && curr.val > curr.next.val) ||
                (curr.val < prev.val && curr.val < curr.next.val)) {
                criticals.add(idx);
            }
            prev = curr;
            curr = curr.next;
            idx++;
        }
        
        if (criticals.size() < 2) return new int[]{-1, -1};
        
        int minDist = Integer.MAX_VALUE;
        for (int i = 1; i < criticals.size(); i++)
            minDist = Math.min(minDist, criticals.get(i) - criticals.get(i-1));
        
        int maxDist = criticals.get(criticals.size()-1) - criticals.get(0);
        return new int[]{minDist, maxDist};
    }
}