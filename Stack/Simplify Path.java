class Solution {
    public String simplifyPath(String path) {
        String[] components = path.split("/");
        Stack<String> stack = new Stack<>();
        
        for (String component : components) {
            if (component.equals(".") || component.isEmpty()) {
                continue; // Skip current directory and empty parts
            } else if (component.equals("..")) {
                if (!stack.isEmpty()) {
                    stack.pop(); // Go up to the parent directory
                }
            } else {
                stack.push(component); // Valid directory
            }
        }
        
        StringBuilder result = new StringBuilder();
        for (String dir : stack) {
            result.append("/").append(dir);
        }
        
        return result.length() == 0 ? "/" : result.toString();
    }
}
