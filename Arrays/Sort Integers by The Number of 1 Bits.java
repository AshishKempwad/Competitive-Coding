//Directly using Comparator - Method 1

public int[] sortByBits(int[] arr){
        return Arrays.stream(arr)
                .boxed() //// Convert int array to Integer stream
                .sorted(Comparator.comparing(Integer::bitCount).thenComparing(Integer::intValue)) // First sort by number of 1 bits, then by value
                .mapToInt(num->num)// Convert back to int array
                .toArray();
    }


//Using custom comparator - Method 2

class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] nums = Arrays.stream(arr).boxed().toArray(Integer[]::new);

        Comparator<Integer> comparator = new BitCountComparator();

        Arrays.sort(nums,comparator);

        return Arrays.stream(nums).mapToInt(Integer::intValue).toArray();
    }
}

class BitCountComparator implements Comparator<Integer>{
    private int findBitCount(int num){
        int count = 0;

        while(num > 0){
            count++;
            num &= (num-1);
        }

        return count;
    }

    public int compare(Integer a, Integer b){
        int bitCountA = findBitCount(a);
        int bitCountB = findBitCount(b);

        if(bitCountA == bitCountB){
            return a-b;
        }

        return bitCountA - bitCountB;
    }
}


