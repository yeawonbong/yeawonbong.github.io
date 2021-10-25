---
layout: post
title: "[Java] JavaStudy_Ch05-09. Collection Framework"
date: 2021-10-25 11:13:00 +0900
category: java
---

목차  
- [컬렉션-프레임워크](#컬렉션-프레임워크)  
- [Collection-인터페이스](#collection-인터페이스)  
    - [List-인터페이스](#list-인터페이스)  
    - [Set-인터페이스](#set-인터페이스)  
- [Map-인터페이스](#map-인터페이스)


# 컬렉션 프레임워크

- 자바 JDK 라이브러리에서 제공되는, 자료구조를 구현해놓은 클래스들이다.
    - 우리가 봤던 대부분의 자료구조가 `java.util` 패키지에 클래스로 구현되어 있다.
- 개발에 소요되는 시간을 절약하면서 최적화된 알고리즘을 사용 수 있다.
- 여러 구현 클래스와 인터페이스의 활용에 대한 이해가 필요하다.
- 대부분 제네릭 클래스로 구현되어 있다.
- 컬렉션 프레임워크의 전반적 구조
    
    ![image](https://user-images.githubusercontent.com/75327385/138640359-e0a67af9-c8ce-46d9-a310-bf04b59109de.png)

    

# Collection 인터페이스

- 하나의 객체를 관리하기 위한 메서드가 선언된 인터페이스
    - 예) 이름이면 이름 이름 이름..
- 하위에 `List`와 `Set` 인터페이스가 있다.

![image](https://user-images.githubusercontent.com/75327385/138640388-da861c4f-f9cf-4fdf-8ab1-83f1d2e974f8.png)

## List 인터페이스

- 순서에 기반한 것
- 그래서 인덱스가 있다.
    - 순회 시 `getI` 로 인덱스로 꺼내온다. (for문같은 걸로 꺼내면 된다)
- 대표적으로 `ArrayList`, `LinkedList`, `Vector`

## Set 인터페이스

- 집합
- 중복을 허용하지 않는다. 유일한 Key값들을 관리할 때 씀
- 순서와 상관이 없다.
    - 순회 시 순서대로 꺼내올 수 없다. 그래서 **Iterator 인터페이스**의 Iterator메소드를 이용해서 사용해야 한다.
- 대표적으로 `HashSet`,  `TreeSet`
    - java에서 Tree → Binary Search Tree, 정렬이 된다.

# Map 인터페이스

- Key Value Pair를 쌍으로 데이터를 관리한다.
    - Key값은 유일, Value는 노상관
- 사전이라고 생각하면 된다.
- 내부적으로 해시 방식을 사용하고 있다.
- 대표적으로 `Hashtable`, `HashMap`, `TreeMap`
