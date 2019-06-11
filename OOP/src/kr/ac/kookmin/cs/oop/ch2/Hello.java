package kr.ac.kookmin.cs.oop.ch2;

abstract class Shape {
	protected String color;

	public Shape() {
		color = "white";
	}

	public Shape(String color) {
		this.color = color;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	abstract int getArea();
}

class Circle extends Shape {

	private int radius;

	public Circle() {
		color = "white";
		radius = 1;
	}

	public Circle(String color, int radius) {
		this.color = color;
		this.radius = radius;
	}

	public int getRadius() {
		return radius;
	}

	public void setRadius(int radius) {
		this.radius = radius;
	}

	public int getArea() {
		return 3 * radius * radius;
	}

}

class Rectangle1 extends Shape {

	private int height;
	private int width;

	public Rectangle1() {
		color = "white";
		width = 1;
		height = 1;
	}

	public Rectangle1(String color, int width, int height) {
		this.color = color;
		this.width = width;
		this.height = height;
	}

	public int getWidth() {
		return width;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public int getHeight() {
		return height;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	public int getArea() {
		return width * height;
	}

}

public class Hello {

	public static void main(String[] args) {
		Rectangle1 rectangle = new Rectangle1("hi", 1, 1);
		System.out.println(rectangle.getColor());
	}

}
