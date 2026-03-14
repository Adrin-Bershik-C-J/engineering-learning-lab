import java.util.*;
public class Main {
public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    String s=sc.next();
    int i,j;
    for(i=0;i<s.length();i++){
        for(j=0;j<s.length();j++){
            if(i==j){
                System.out.print(s.charAt(i));
            }else if((i+j)==s.length()-1){
                System.out.print(s.charAt(i));
            }else{
                System.out.print("  ");
            }
        }
        System.out.println();
    }
    }
}