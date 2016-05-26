public class Solution {
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    public int evalRPN(String[] tokens) {
        if (tokens == null || tokens.length == 0) {
            return 0;
        }
        HashSet<String> hashSet = new HashSet<String>();
        hashSet.add("+");
        hashSet.add("-");
        hashSet.add("*");
        hashSet.add("/");
        Stack<String> stack = new Stack<String>();
        for (String token : tokens) {
            if (hashSet.contains(token)) {
                int num2 = Integer.parseInt(stack.pop());
                int num1 = Integer.parseInt(stack.pop());
                int r;
                switch (token) {
                    case "+":
                        r = num1 + num2;
                        break;
                    case "-":
                        r = num1 - num2;
                        break;
                    case "*":
                        r = num1 * num2;
                        break;
                    default:
                        r = num1 / num2;
                }
                stack.push(Integer.toString(r));
            } else {
                stack.push(token);
            }
        }
        return Integer.parseInt(stack.pop());
    }
}
