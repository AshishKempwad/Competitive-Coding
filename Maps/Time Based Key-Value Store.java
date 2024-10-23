import java.util.*;

class TimeMap {
    // HashMap where key is the string and value is another TreeMap of timestamp to value.
    private Map<String, TreeMap<Integer, String>> map;

    public TimeMap() {
        map = new HashMap<>();
    }
    
    // Method to store the value with timestamp for a given key
    public void put(String key, String value, int timestamp) {
        // Get the TreeMap corresponding to the key or create a new TreeMap if key doesn't exist
        map.computeIfAbsent(key, k -> new TreeMap<>()).put(timestamp, value);   //O(1) - TC
    }
    
    // Method to retrieve the latest value for the key with the maximum timestamp <= given timestamp
    public String get(String key, int timestamp) {
        // Check if the key exists in the map
        if (!map.containsKey(key)) {
            return "";
        }
        
        // Retrieve the TreeMap for the key
        TreeMap<Integer, String> timeMap = map.get(key);
        // Get the greatest key less than or equal to the given timestamp - in O(logn) - Binary Search is performed internally using floorEntry method
        Map.Entry<Integer, String> entry = timeMap.floorEntry(timestamp);
        // Return the corresponding value if found, otherwise return an empty string
        return entry != null ? entry.getValue() : "";
    }
}
