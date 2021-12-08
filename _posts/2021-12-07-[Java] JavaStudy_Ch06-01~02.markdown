---
layout: post
title: "[Java] JavaStudy_Ch06-01~02. 내부클래스"
date: 2021-12-07 11:13:00 +0900
category: java
---
# 01. 여러 내부 클래스의 정의와 유형

## 내부 클래스 (inner class)

- 클래스 내부에 클래스를 선언하는 것 (중첩 클래스라고도 말함)
- 클래스를 특정 클래스 내부에서만 사용하는 경우 사용한다.
- 가장 많이 사용 : 익명 클래스 (anonymous class)
- 내부 클래스의 종류
    - 인스턴스 대부 클래스
    - 정적 (static) 내부 클래스
    - 지역 (local) 내부 클래스
    - 익명 (anonymous) 내부 클래스 : 이름이 없는 클래스 - 많이 사용됨
    - 익명 빼고는 변수와 똑같다고 보면 된다.
- 실질적으로 사용할 일이 그리 많진 않다.

### 인스턴스 내부 클래스 (instance inner class)

- 내부적으로 사용할 클래스를 선언 (그렇기에 대부분 private으로 선언 권장)
- 외부 클래스가 생성된 후에 생성됨 (정적 내부 클래스와 다름)
- private가 아닌 내부 클래스는 다른 외부 클래스에서 생성할 수 있음
    
    ```java
    OutClass outClass = new OutClass();
    OutClass.InClass inClass = outClass.new InClass();
    ```
    
- 특징
    - 밖에 있는 outClass 안에 있기 때문에 외부클래스의 private 멤버를 모두 사용 가능함.
    - static 변수를 안에서 선언할 수 없다. (아우터 클래스가 생성된 뒤 만들어지는 클래스인데, staitc 변수는 생성과 상관없이 사용가능한 변수니까.) - 정적 내부클래스에서 사용해야 함.
- 예제
    
    ```java
    package ch01;
    //인스턴스 내부 클래스
    class OutClass {
            private int num = 10;
            private static int sNum = 20;
            private InClass inClass;
    
            public OutClass() {  // outClass 생성하면서 inClass 생성
                inClass = new InClass();
            }
    
            private class InClass { //보통 private로 선언
                int inNum = 100;
                static int sInNum = 500;
                void inTest() {
                    System.out.println("");
                    System.out.println("OutClass num = " + num + "(외부 클래스의 인스턴스 변수)");
                    System.out.println("OutClass sNum = " + sNum + "(외부 클래스의 스태틱 변수)");
                    System.out.println("OutClass inNum = " + inNum + "(내부 클래스의 인스턴스 변수)");
                }
            }
    
            public void usingClass() {
                inClass.inTest(); //내부 클래스의 메서드를 외부클래스에서 호출하여 사용
            }
    }
    
    public class InnerTest {
        public static void main(String[] args) {
            OutClass outClass = new OutClass();
            outClass.usingClass();
    
            /*내부 클래스가 private이 아니라면 밑에와 같이 외부에서 생성이 가능하긴 하다. 하지만 보통 private로 내부클래스를 선언.
    
            OutClass.InClass inner = outClass.new InClass();
            inner.inTest();
    
             */
        }
    }
    ```
    

### 정적 내부 클래스 (static inner class)

- 외부 클래스 생성과 무관하게 사용할 수 있음
- 정적 변수, 정적 메서드 사용
- 정적 내부 클래스에서 외부클래스의 인스턴스변수 호출은 할 수 없다. 왜냐하면 외부 클래스가 생성되기 이전에도 정적 내부클래스 호출이 가능하기 때문에!
- 정리하자면,
    - static inner class의 일반 인스턴스 메서드에서는
        - 생성과 상관없는 내/외부 static 변수들만 호출이 가능.
        - 내부 인스턴스 변수는 본인 클래스 변수이므로 호출 가능.
    - static inner class의 static 메서드에서는
        - 내/외부 static 멤버만 호출 가능, 내부 인스턴스 변수 호출 불가
- 예제
    
    ```java
    package ch01;
    // 정적 내부 클래스
    
    class OutClass {
        private int num = 10;
        private static int sNum = 20;
    
        static class InStaticClass {
            int iNum = 100;
            static int sInNum = 200;
            void inTest() {
                System.out.println("OutClass iNum = " + iNum + "(내부 클래스의 인스턴스 변수)");
                System.out.println("OutClass sNum = " + sNum + "(외부 클래스의 스태틱 변수)");
                System.out.println("OutClass sInNum = " + sInNum + "(내부 클래스의 인스턴스 변수)");
            }
            static void sTest() {
                System.out.println("OutClass sNum = " + sNum + "(외부 클래스의 스태틱 변수)");
                System.out.println("OutClass sInNum = " + sInNum + "(내부 클래스의 인스턴스 변수)");
            }
        }
    }
    
    public class InStaticTest {
        public static void main(String[] args) {
            OutClass.InStaticClass sInClass = new OutClass.InStaticClass(); //static class를 outClass 생성과 상관없이 생성할 수 있음
            sInClass.inTest();
            OutClass.InStaticClass.sTest(); //생성 없이 static 메서드는 호출 가능
        }
    }
    ```
    
    ![https://gitlab.com/easyspubjava/javacoursework/-/raw/master/Chapter6/6-01/img/method.png](https://gitlab.com/easyspubjava/javacoursework/-/raw/master/Chapter6/6-01/img/method.png)
    

### 지역 내부 클래스 (local inner class)

- 지역변수처럼, 메서드 내부에 정의하여 사용하는 클래스
- 메서드의 호출이 끝나면 메서드에 사용된 지역변수의 유효성은 사라지는데. 메서드 호출 이후에도 사용해야 하는 경우가 있을 수 있으므로 지역 내부 클래스에서 사용하는 메서드의 지역변수나 매개변수는 final로 선언된다.
- 예제
    
    ```java
    package ch01;
    //지역 내부 클래스 - 메서드 내부에 클래스
    
    class Outer2 {
    
        int outNum = 100;
        static int sNum = 200;
    
        Runnable getRunnable(/*final*/int i) { // (자바 인터페이스, 클래스를 스레드화 할 때 사용됨.)
            /*final*/int num = 10; // precompile 단계에서 final을 붙여 상수화 시켜준다.
            class MyRunnable implements Runnable { //지역 내부 클래스
    
                int localNum = 1000;
                @Override
                public void run() {
                    //i = 50;     // err: i와 num은 final이라 constant memory에 있다. (스택이 아니라.) 그래서 상수화되어 바꿀 수 없다.
                    //num =20;    // err: 메서드는 실행 후 모두 없어지기 때문에. 하지만 이 클래스는 Runnable로 호출될 수 있으니까.
    
                    System.out.println("i = " + i);
                    System.out.println("num = " + num);
                    System.out.println("localNum = " + localNum);
    
                    System.out.println("outNum = " + outNum + " (외부 클래스 인스턴스 변수)");
                    System.out.println("Outter.sNum = " + Outer2.sNum + " (외부 클래스 인스턴스 변수)");
                }
            }
            return new MyRunnable(); // 내부 클래스를 생성해서 반환해주는 메서드인 것.
        }
    }
    
    public class AnonymousInnerTest {
        public static void main(String[] args) {
    
            Outer2 out = new Outer2();
            Runnable runner = out.getRunnable(100); // 호출된 후 이 메서드는 끝이난다.
            runner.run();
        }
    }
    ```
    
    - MyRunnable 클래스를 사용하려면 직접 생성하는 것이 아닌, getRunnable() 메서드를 호출하여 생성된 개체를(Runnable type) 반환받아야 함.

### 익명 내부 클래스 (annonymous inner class)

- 앞에 예제처럼, Runnable로 메서드를 통해 반환되는 지역 내부 클래스는 사실 내부에서만 사용되기때문에 이름이 그 때밖에 안쓰이잖슴? 이름이 사실상 없어도 됨.. 그것이 익명 내부 클래스
- 클래스의 이름을 생략하고 주로 하나의 인터페이스나 하나의 추상클래스를 구현하여 반환
- 인터페이스나 추상 클래스 자료형의 변수에 직접 대입하여 클래스를 생성하거나 지역 내부 클래스의 메서드 내부에서 생성하여 반환할 수 있다.
- 안드로이드 widget의 이벤트 핸들러에 활용됨
    
    ![https://gitlab.com/easyspubjava/javacoursework/-/raw/master/Chapter6/6-01/img/android.png](https://gitlab.com/easyspubjava/javacoursework/-/raw/master/Chapter6/6-01/img/android.png)
    
- 예제
    
    ```java
    package ch01;
    //익명 내부 클래스
    
    class Outer3 {
    
        int outNum = 100;
        static int sNum = 200;
    
        Runnable getRunnable(int i) {
            int num = 10;
    
            return new Runnable() { // 바로 return으로 클래스를 Runnable type으로 반환해준다. 이름 없이. 익명 클래스
                int localNum = 1000;
                @Override
                public void run() {
    
                    System.out.println("i = " + i);
                    System.out.println("num = " + num);
                    System.out.println("localNum = " + localNum);
    
                    System.out.println("outNum = " + outNum + " (외부 클래스 인스턴스 변수)");
                    System.out.println("Outter.sNum = " + Outer2.sNum + " (외부 클래스 인스턴스 변수)");
                }
            };
        }
    
        Runnable runnable = new Runnable() { // Outer3의 인스턴스 변수
            @Override
            public void run() {
                System.out.println("Runnable class");
            }
        };
    }
    
    public class AnonymousInnerTest {
        public static void main(String[] args) {
    
            Outer3 out = new Outer3();
            Runnable runner = out.getRunnable(100);
    
            runner.run();
            out.runnable.run(); //instance 변수의 메서드를 호출
        }
    }
    ```