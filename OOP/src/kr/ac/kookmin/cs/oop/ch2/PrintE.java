package kr.ac.kookmin.cs.oop.ch2;

class Point {
  private int x,y;
  public void set(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public Point(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public String toString() {
    return "Point("+x+"."+y+")";
  }

  public void showPoint() {
    System.out.println("(" + x + " , " + y + ")");
  }
}

class ColorPoint extends Point {
  private String color;

  public ColorPoint(int x,int y, String color) {
    super(x, y);
    this.color = color;
  }
  public void setColor(String color) {
    this.color = color;
  }
  public void showColorPrint() {
    System.out.print(color);
    showPoint();
  }
}

public class PrintE {
  public static void main(String[] args) {
    Point p = new Point(1,2);
    System.out.println(p.toString());

    ColorPoint cp = new ColorPoint(5,6,"blue");
    cp.showColorPrint();
  }
}
