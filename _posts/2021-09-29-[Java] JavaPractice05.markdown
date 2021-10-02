---
layout: post
title: "[Java] JavaPractice05. abstract class, abstract method, hook method, template method pattern, final"
date: 2021-09-29 11:13:00 +0900
category: java
---

# 추상클래스

[javaDoc](https://docs.oracle.com/javase/tutorial/java/IandI/abstract.html)

[refblog](https://limkydev.tistory.com/188)

## 추상클래스 (abstract class)

```java
public abstract class Classtest{

/*may or may not include abstract methods.*/

	abstract void abstractMethod();

}
```

- `abstract` 예약어 사용
- 추상클래스는 여러 클래스 간에 비슷한 필드와 메서드를 공통적으로 추출해 만들어진 클래스이다.
- 즉, 어느정도 규격을 잡아놓은 기본 클래스인 것!
- 추상 클래스에는 추상 메서드(선언만 있는 메서드)가 포함될 수 있다.
- 추상클래스는 아직 메서드와 내용이 추상적이기 때문에 인스턴스를 생성할 수 없다. 무조건 상속해서 Override로 사용해야 하는 클래스.
    - ↔ Concrete Class 실체 클래스 - 직접 생성할 수 있고, 그만큼 구체적이다.
    - Anonymous subclass
        - 익명클래스 Stackoverflow [https://stackoverflow.com/questions/13670991/can-we-instantiate-an-abstract-class](https://stackoverflow.com/questions/13670991/can-we-instantiate-an-abstract-class)
        - 익명클래스 [https://pangtrue.tistory.com/104](https://pangtrue.tistory.com/104)
- 클래스 다이어그램 Class Diagram
    
    [ref](https://thinking-jmini.tistory.com/26)
    
    ![image](https://user-images.githubusercontent.com/75327385/135401235-5bef8113-d80d-4687-955f-2de10c6df786.png)

    
    - Italic체 - 추상 클래스 / 메서드
    - 하위 클래스들이 상위 클래스인 Car을 상속받은 상태
    - 실체클래스들의 공통적인 특성을추출하여 선언한 클래스가 추상클래스, 실체클래스는 추상클래스를 상속받는 관계인 것.
    

## 추상메서드 (abstract method)

```java
abstract void methodTest(int i);
```

- 구현부(implementation) 없이 선언된 메서드 - braces{} 없이, 선언만 되어있다.
    - 이를 자식 클래스 메서드에서 오버라이딩하여 구현해야 한다.
- 즉, 껍데기 메서드.
- 만약 클래스에 추상메서드가 선언되어 있을 경우, 이는 추상클래스로 선언되어야 한다. (추상 메서드는 추상 클래스에서만 선언할 수 있다)
    - 그렇기때문에 보통 추상 클래스가 상속될 경우, 상속받은 하위 클래스에서 추상 메서드의 구현부를 넣어주는데, 만약 추상메서드 구현부를 써주지 않는 경우, 그 하위 클래스도 abstract로 선언해주어야 한다.
- *~~상위 클래스에서 구현할 수 없는 메서드일 경우, 구현의 책임을 하위 클래스에 위임한다. (하위 클래스에서 반드시 추상 메서드를 알아서 Override하여 구현해주어야 함)~~*

# 공통으로 사용하는 메서드 추가

## 추상 클래스를 사용하는 이유?

- 자식클래스가 기능을 직접 정의할 수 있게 하기때문에, 활용하기가 좋다.
- 자식클래스에게 틀을 잡아주지만, 인스턴스를 바로 생성/초기화 하기 싫을 때.
- 자식 클래스에 추상 메소드를 반드시 구현하도록 하기 위해. (추상 메서드를 구현해야만 인스턴스를 생성할 수 있으므로)
- *상위 클래스에서 구현할 수 없는 메서드일 경우, 구현의 책임을 하위 클래스에 위임한다. (하위 클래스에서 반드시 추상 메서드를 알아서 Override하여 구현해주어야 함)*

### 훅(Hook)메서드 알아보기

- 서브클래스에서 확장할 수 있는, 아무 일도 하지 않거나 기본적인 행동을 제공하는 메소드
- abstract 키워드를 붙이면 상속 받은 클래스는 반드시 해당 메소드를 구현해야 하지만 abstract 키워드를 붙이지 않고 훅 메소드로 만들면 하위 클래스에서 반드시 구현할 필요가 없다. 상속 받은 클래스에서는 선택적으로 오버라이드할 수 있다.
- 후크(hook)는 추상 클래스에서 선언되는 메서드긴 하지만 기본적인 내용만 구현되어있거나, 아무 코드도 들어 있지 않은 메서드 이다.
- 구현이 된 메서드지만, 구현 내용이 비어있는 것
    
    ```jsx
    public void hookMethod(){}
    
    // != public abstract void abstMethod(); //force
    ```
    

# 게임 레벨마다 기능이 다른 경우

## 추상클래스와 템플릿 메서드 패턴

[ref](http://ima.udg.edu/~sellares/EINF-ES1/TemplateMethodToni.pdf)

[ref2](https://johngrib.github.io/wiki/design-pattern/template-method-pattern/#fn:gof)

- 템플릿 메서드 패턴은 상위 클래스에서 메서드 혹은 추상메서드를 활용하여 코드의 틀을 정의하고, 하위 클래스에서 처리 내용을 구체화하는 것을 말한다.
- 추상 클래스인 상위 클래스 내에 템플릿 메서드가 위치하여 전체적인 흐름을 정의하는 역할을 한다.
- framework에서 많이 쓰이는 설계 패턴이다. (틀이 정해져 있고 그 틀 기반으로 상속받아 내용을 채우는 느낌)
- 이 템플릿 메서드는 전반적 흐름, 체계를 딱 정해놓은 것이기 때문에, 흐름이 변하면 안되므로 `final`로 선언한다. (하위 클래스에서 override재정의하지 못하도록)
- 코드의 흐름(시나리오)를 정의하는 메서드이다.
    
    ![image](https://user-images.githubusercontent.com/75327385/135401306-331c68a5-a0f6-4469-858c-f2a45cf233b7.png)
    
- 구현 팁
    - 템플릿 메소드에서 호출하는 메소드들은 템플릿 메소드만호출할 수 있게 하는 것을 고려한다.
        - (위 예제에서 - go()템플릿 메서드에서 사용하는 run, jump, turn은 protected 접근제한)
        - final 예약어

## final 예약어는 언제 사용하는가?

- `Class` : 클래스가 상속되지 않게 하려면 final로 정의한다.
- `method` : 하위 클래스에서 재정의 할 수 없는 메소드 (템플릿 메서드를 정의할 때 흐름을 재정의하지 못하게 final로 정의)
- `Variable` : final 변수 == 상수 (값이 변경될 수 없다.) *const*
    
    ```jsx
    public static final int zero = 0;
    ```