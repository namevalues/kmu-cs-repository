package kr.ac.kookmin.cs.oop.ch2;

import java.util.*;
class CurrencyConverter {
  private static double rate;
  public static double toDallar(double won) {
    return won/rate;
  }
  public static double toKWR(double dollar) {
    return dollar * rate;
  }
  public static void setRate(double r) {
    rate = r;
  }
}

public class Current {

	public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    //double rate = sc.nextDouble();
    double rate = 1121;
    CurrencyConverter.setRate(rate);
    System.out.println(CurrencyConverter.toDallar(1000000));
    System.out.println(CurrencyConverter.toKWR(100));
	}

}
