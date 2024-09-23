/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {

        int [][]matrix = new int[m][n];
        int dir = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = -1;
            }
        }

        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        while(top <= down && left<=right && head!=null){
            if(dir == 0){
                for(int i=left;head!=null && i<=right;i++){
                    matrix[top][i] = head.val;
                    head = head.next;
                }
                top++;
            }else if(dir == 1){
                 for(int i=top;i<=down && head!=null;i++){
                    matrix[i][right] = head.val;
                    head=head.next;
                 }
                 right--;
            }else if(dir == 2){
                for(int i=right;i>=left && head!=null;i--){
                    matrix[down][i] = head.val;
                    head=head.next;
                }
                down--;
            }else if(dir == 3){
                for(int i = down;i>=top && head!=null;i--){
                    matrix[i][left] = head.val;
                    head=head.next;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return matrix;
        
    }

    
}
