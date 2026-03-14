
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int r = sc.nextInt();
            int c = sc.nextInt();

            int matrix[][] = new int[r][c];

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.spirallyTraverse(matrix);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();

            System.out.println("~");
        }
    }
}



class Solution {
    
    public ArrayList<Integer> spirallyTraverse(int mat[][]) {
        
        int m=mat.length;
        int n=mat[0].length;
        ArrayList<Integer> res=new ArrayList<>();
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom&&left<=right){
            for(int i=left;i<=right;i++){
                res.add(mat[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res.add(mat[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    res.add(mat[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.add(mat[i][left]);
                }
                left++;
            }
        }
        return res;
    }
}
