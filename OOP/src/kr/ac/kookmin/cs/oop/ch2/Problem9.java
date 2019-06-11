package kr.ac.kookmin.cs.oop.ch2;

class Solution {
  public int a;
  private int b;
  int c;
}

class Calc {
  public static int abs(int a) {
    return a>0?a:-a;
  }

  public static int max(int a, int b) {
    return(a>b)?a:b;
  }

  public static int min(int a, int b) {
    return(a>b?b:a);
  }
}

public class Problem9 {


  public static void main(String[] args) {
    System.out.println(Calc.abs(-5));
    System.out.println(Calc.max(-5,3));
    System.out.println(Calc.min(-5,3));
  }
}

