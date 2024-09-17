class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        HashMap<String, Integer> map = new HashMap<>();
        String[] words1 = s1.split(" ");
        String[] words2 = s2.split(" ");

        for (String word : words1) map.put(word, map.getOrDefault(word, 0) + 1);
        for (String word : words2) map.put(word, map.getOrDefault(word, 0) + 1);

        ArrayList<String> list = new ArrayList<>();
        for (String word : map.keySet()) {
            if (map.get(word) == 1) list.add(word);
        }
        return list.toArray(new String[list.size()]);
    }
}