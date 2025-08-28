class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List> map = new HashMap<>();
        for(String s:strs){
            int [] count = new int[26];
            for(char c : s.toCharArray()){
                count[c-'a'] ++; 
            }
            StringBuilder sb  = new StringBuilder();
            for(int i:count){
                sb.append("#");
                sb.append(i);
            }
            String key = sb.toString();
            if(!map.containsKey(key)){
                map.put(key,new ArrayList<String>());
            }
            map.get(key).add(s);
        }
        return new ArrayList(map.values());
    }
    public static String GetKey(String s) {
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            freq[ch-'a']++;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < freq.length; i++) {
            sb.append(freq[i] + " ");
        }
        return sb.toString();
    }
}