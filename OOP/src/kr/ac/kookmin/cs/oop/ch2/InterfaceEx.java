package kr.ac.kookmin.cs.oop.ch2;

interface PhoneInterface {
  final int TIMEOUT = 10000;
  void sendCall();
  void receiveCall();
  default void printLogo() {
    System.out.println("** PHONE **");
  }
}

interface MP3interface {
  public void play();
  public void stop();  
}

class PDA {
  public int calculate(int x,int y) {
    return x+y;
  }
}

class SmasungPhone extends PDA implements PhoneInterface, MP3interface {
  @Override
  public void sendCall() {
    System.out.println("RRRR");
  }

  @Override
  public void receiveCall() {
    System.out.println("전화왓음");
  }

  public void Flash() {
    System.out.println("전화와서번쩍");
  }

  @Override
  public void stop() {
    System.out.println("음악종료");
  }

  @Override
  public void play() {
    System.out.println("음악시작");
  }
}

public class InterfaceEx {
  public static void main(String args[]) {
    SmasungPhone phone = new SmasungPhone();
    phone.printLogo();
    phone.sendCall();
    phone.receiveCall();
    phone.Flash();
    phone.play();
    phone.stop();
  }
}