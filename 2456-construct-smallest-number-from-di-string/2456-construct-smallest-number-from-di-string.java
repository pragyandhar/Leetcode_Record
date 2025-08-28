class Solution {
    public String smallestNumber(String pattern) {
        int n = pattern.length();
        int count = 1;
        String result = "";
        Stack<String> num = new Stack<>();

        for (int i = 0; i < n+1; i++) {
            num.push(Integer.toString(count));
            count++;

            if (i == n || pattern.charAt(i) == 'I') {
                while (!num.isEmpty()) {
                    result += num.peek();
                    num.pop();
                }
            }
        }
        return result.toString();
    }
}