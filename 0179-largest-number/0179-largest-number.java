class Solution {
    public String largestNumber(int[] nums) {
        String[] arr = IntArraytoStringArray(nums);
        Arrays.sort(arr, (a,b) -> {
            String order1 = a + b;
            String order2 = b + a;
            return order2.compareTo(order1);
        });
        if (arr[0].equals("0")) {
            return "0";
        }
        StringBuilder result = new StringBuilder();
        for (String num: arr) {
            result.append(num);
        }
        return result.toString();
    }

    public static String[] IntArraytoStringArray (int[] array) {
        String[] Array = new String[array.length];
        for (int i = 0; i < array.length; i++) {
            Array[i] = String.valueOf(array[i]);
        }
        return Array;
    }
}