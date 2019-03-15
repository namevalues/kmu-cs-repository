package kr.ac.kookmin.cs.oop.ch2;

public class Hello {

	public static int sum(int a, int b) {
		return a+b;
	}
	
	public static void main(String[] args) {
		int i = 20;
		int s;
		char a;
		
		s = sum(i,10);
		a = '?';
		System.out.println(a);
		System.out.println("Hello");
		System.out.println(s);
	}

}
