class Solution {
    private List<Integer> helperSort(int[][] arr, int k) {
        int[] deg = new int[k];
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            list.add(new ArrayList<>());
        }

        Queue<Integer> q = new LinkedList<>();
        for (int[] a : arr) {
            list.get(a[0] - 1).add(a[1] - 1);
            deg[a[1] - 1]++;
        }

        for (int i = 0; i < k; i++) {
            if (deg[i] == 0) {
                q.add(i);
            }
        }

        List<Integer> res = new ArrayList<>();
        while (!q.isEmpty()) {
            int temp = q.poll();
            res.add(temp + 1);
            for (int l : list.get(temp)) {
                if (--deg[l] == 0) {
                    q.add(l);
                }
            }
        }
        return res;
    }

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        List<Integer> list1 = helperSort(rowConditions, k);
        List<Integer> list2 = helperSort(colConditions, k);

        if (list1.size() < k || list2.size() < k) {
            return new int[0][0];
        }

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < k; i++) {
            map.put(list2.get(i), i);
        }

        int[][] res = new int[k][k];
        for (int i = 0; i < k; i++) {
            res[i][map.get(list1.get(i))] = list1.get(i);
        }
        return res;
    }
}