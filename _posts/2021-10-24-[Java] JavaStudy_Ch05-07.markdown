---
layout: post
title: "[Java] JavaStudy_Ch05-06~08 Generic Programming"
date: 2021-10-24 11:13:00 +0900
category: java
---
- [06-제네릭 프로그래밍](#06-무엇이든-담을-수-있는-제네릭generic-프로그래밍)
- [07-<T extends> 클래스 사용하기](#07-t-extends-클래스-사용하기)
- [08-제네릭-메서드-활용하기](#08-제네릭-메서드-활용하기)

# 06. 무엇이든 담을 수 있는 제네릭(Generic) 프로그래밍

## 제네릭 자료형

- 뜻은 일반화!
- 클래스에서 사용하는 어떤 변수의 자료형이 여러개일 수 있는 경우, 이를 따르기 위해 여러 클래스를 만들기엔 오버헤드다. 그래서 제너릭 자료형을 쓴다.
- 다양한 자료형이 적용될 수 있는 클래스를 만드는 것!
- 클래스에서 사용하는 한 변수의 자료형이 여러개일 수 있고, 그 기능(메서드)은 동일한 경우, **클래스의 자료형을 특정하지 않고 추후 해당 클래스를 사용할 때 지정 할 수 있도록 선언.**
- 실제 사용되는 자료형의 변환은 컴파일러에 의해 검증되므로 안정적인 프로그래밍 방식이다.
- **컬렉션 프레임워크**에서 많이 사용되고 있음.
- 그 외에도 직접 제너릭 방식으로 클래스나 메서드를 만들어 사용할 수 있다.
- 제네릭 타입을 사용하지 않는 경우
    - 변수 하나가 여러 타입일 수 있는 경우 - 타입별로 클래스를 만들거나, Object를 변수의 자료형으로 선언(`Object` 클래스는 모든 클래스의 상위 클래스니까)하여 꺼내쓸 때는 캐스팅해서 씀. 번거롭잖아? 그래서 제네릭 타입이 나왔다!

## 제네릭 클래스 정의

```java
public class GenericPrinter<T> { //Generic Type을 쓰니까 <T> 이렇게 붙여줘야 한다. 
	private T material;
	
	public void setMaterial(T material) {
		this.material = material;
	}
	
	public T getMaterial() {
		return material;
	}
	
	public String toString(){
		return material.toString();
	}
}
```

- 자료형 매개변수 `T` (type parameter) : 해당 클래스를 사용하는 시점에 실제로 사용할 자료형을 지정한다, static 변수는 사용할 수 없음.
- 자료형 매개변수를 사용한 클래스 (여기서 GenericPrinter) : 제네릭 자료형
- 자료형 매개변수를 매개변수로 받는 메서드  : Generic Method
- `E` : element, `K` : key, `V` : value 등 여러 알파벳을 의미에 따라 사용 가능

## **제네릭 클래스 사용**

```java
public class GenericPrinterTest {

    public static void main(String[] args) {

        Powder powder = new Powder();
        GenericPrinter<Powder> powderPrinter = new GenericPrinter<>();
        powderPrinter.setMaterial(powder);

        Powder p = powderPrinter.getMaterial(); //형변환 X
        System.out.println(powderPrinter.toString());

    }
}
```

- Generic Type을 쓰니까 <T> 이렇게 붙여줘야 한다.  - 사용 시 <> 안에 사용할 실제 자료형을 쓰면 됨.
    - 컴파일 시 사용할때 안에 쓰는 실제 자료형으로 T를 모두 replace해준다. 그래서 캐스팅해줄 필요가 없는 것.

- Object 클래스로 쓸 때와의 차이점 : 형변환을 해야하는가, 하지 않아도 되는가가 다르다.

## 다이아몬드 연산자 `<>`

`ArrayList list = newArrayList<>();` 

- 여기서 `<>`를 다이아몬드 연산자라고 함.
- 다이아몬드 연산자 내부에서 자료형은 생략 가능함.
- 제네릭에서 자료형 추론 (자바 10부터) - 지역변수 자료형 추론
    
    ```java
    ArrayList list = new ArrayList() 
    	|
    	V
    var list = new ArrayList(); 
    ```
    

# 07. <T extends 클래스> 사용하기

## 상위 클래스의 필요성

```java
<T extends ParentClass>
```

- T 자료형의 범위를 제한할 수 있다.
    - 위 경우, ParentClass를 상속받은 클래스들만 T를 대체할 수 있다.
    - T 자료형을 쓸 경우, 아무 자료형이나 될 수가 있으니까 가령, ThreeDPrinter의 material이 water로 들어가면 작동이 안되는데, water로도 들어갈 수 있으면 안되니까, 상속을 사용하여(extends) 제한을 걸어준다!
- 상위 클래스에서 선언하거나 정의하는 메서드를 활용할 수 있다.
- 상속을 받지 않는 경우 T는 Object로 변환되어 Object 클래스가 기본으로 제공하는 메서드만 사용할 수 있다.

## T extends를 사용한 프로그래밍

- GenericPrinter에 material 변수의 자료형을 상속받아 구현
- T에 무작위 클래스가 들어갈 수 없게 Material 클래스를 상속받은 클래스로 한정
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/60b78466-3e34-4388-b4ad-61d1dd86a7b6/Untitled.png)
    

## 추가

- C++에 `템플릿 클래스` 와 같은 개념이라고 볼 수 있다.

# 08. 제네릭 메서드 활용하기

## 제네릭 메서드란? [javaDocs](https://docs.oracle.com/javase/tutorial/java/generics/methods.html)

- 자료형 매개변수를 메서드의 매개변수나 반환 값으로 가지는 메서드
- 자료형 매개 변수가 하나 이상인 경우도 있다. (T V E 이렇게)
- 제네릭 클래스가 아니어도 내부에 제네릭 메서드는 구현하여 사용할 수 있음.
    
    ```java
    public <자료형 매개변수> 반환형 메서드 이름(자료형 매개변수...){}
    ```
    

## 제네릭 메서드의 활용 예

- 두 점(top, bottom)을 기준으로 사각형을 만들 때 사각형의 너비를 구하는 메서드를 만들어보자.
- 두 점은 정수인 경우도 있고, 실수인 경우도 있으므로 제네릭 타입을 사용하여 구현한다.

```java
public class Point<T, V> {

    T x;
    V y;

    Point(T x, V y) {
        this.x = x;
        this.y = y;
    }

    public T getX() {
        return x;
    }

    public V getY() {
        return y;
    }
}
```

```java
public class GenericMethod {

    public static <T, V> double makeRectangle(Point<T, V> p1, Point<T, V> p2) {

    double left = ((Number)p1.getX()).doubleValue();
    double right = ((Number)p2.getX()).doubleValue();
    double top = ((Number)p1.getY()).doubleValue();
    double bottom = ((Number)p2.getY()).doubleValue();

    double width = right - left;
    double height = bottom - top;

    return width * height;

    }

    public static void main(String[] args) {

        Point<Integer, Double> p1 = new Point<Integer, Double>(0, 0.0);
        Point<Integer, Double> p2 = new Point<>(10, 10.0); //안써도 됨

        double size = GenericMethod.<Integer, Double>makeRectangle(p1, p2);
        System.out.println(size);

    }
}
```

출력

```
100.0
```

---

- Generic Class 안에 Generic Method가 주로 많이 쓰인다.
- 하지만 위에처럼 Generic Class가 아니라도 Generic Method를 선언하여 쓸 수 있다는 것.