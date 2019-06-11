package kr.ac.kookmin.cs.oop.ch2;

abstract class Calculator {
  public abstract int add(int a,int b);
  public abstract int subtract(int a, int b);
  public abstract double average(int[] a);
}

public class GoodCalc extends Calculator {

  @Override
  public int add(int a, int b) {
    return a+b;
  }

  @Override
  public int subtract(int a, int b) {
    return a-b;
  }

  @Override
  public double average(int[] a) {
    int i = 0;
    double sum = 0;
    for(i = 0; i < a.length; i++) {
      sum += a[i];
    }
    return sum/i;
  }

  public static void main(String[] args) {
    Calculator myCalc = new GoodCalc();
    int[] a  = {1,2};
    System.out.println(myCalc.average(a));
  }
}