class Solution {
    public int numTeams(int[] rating) {
        int cnt = 0;
        for (int i = 0; i < rating.length - 2; i++) {
            for (int j = i; j < rating.length - 1; j++) {
                for (int k = j; k < rating.length; k++) {
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) ||
                            (rating[i] > rating[j] && rating[j] > rating[k])) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
}