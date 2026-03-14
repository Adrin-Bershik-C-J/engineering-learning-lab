//Uncompress a string
// a3b11c1 -> aaabbbbbbbbbbbc

import java.util.*;
public class Uncompress{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        int i=0;
        while(i<str.length()){
            char ch=str.charAt(i);
            if(!Character.isDigit(ch)){
                i++;
                int num=0;
                while(i<str.length()&&Character.isDigit(str.charAt(i))){
                    num=num*10+(str.charAt(i)-'0');
                    i++;
                }
                for(int j=0;j<num;j++){
                    System.out.print(ch);
                }
            }
        }
    }
}
