---
layout: post
title: "[Java] JavaStudy_Ch05-11~13. Iterator, HashSet, TreeSet"
date: 2021-11-28 11:13:00 +0900
category: java
---
# ch11. Iterator

## Collection 요소를 순회하는 Iterator

- Collection을 구현한 모든 클래스에 Iterator 호출하면 Iterator가 반환된다. (?)

## 요소의 순회란?

- 컬렉션 프레임워크에 저장된 요소들을 하나씩 차례대로 참조하는 것
- 순서가 있는 List인터페이스의 경우는 Iterator를 사용하지 않고 get(i)메서드를 활용할 수 있음.
- Set 인터페이스의 경우 get(i)메서드가 제공되지 않으므로 Iterator를 활용하여 객체를 순회함.

## Iterator 사용하기

- `boolean hasNext()`
    
    ```java
    while (ir.hasNext()) {
     
    }
    ```
    
    - 이후에 요소가 더 있는 지를 체크하는 메서드
    - 요소가 있으면 true 를 반환
- `E next()`
    
    ```java
    Member member = ir.next();
    ```
    
    - 다음에 있는 요소를 반환 (다음 인덱스의 요소 반환)

# ch12. HashSet
## 중복되지 않게 자료를 관리하는 Set인터페이스를 구현한 클래스와 그 활용

## HashSet 클래스

- Set 인터페이스를 구현한 클래스와
- 멤버의 중복 여부를 체크하기 위해 인스턴스의 동일성을 확인해야 한다.
- 동일성 구현을 위해 필요에 따라 `equals()` 와 `hashCode()` 메서드를 재정의한다.
    - Object 클래스에 위치
    
- 고유 코드를 (동일성 판단을 위한) 무엇으로 판단할 건 지 equals()를 오버라이딩
- 그 고유 코드를 무엇으로 지정하는 지를 hashCode() 오버라이딩하여 정의한다.

```java
package ch12;

import java.util.HashSet;

public class MemberHashSet {

    private HashSet<Member> hashSet;

    public MemberHashSet() {
        hashSet = new HashSet<>();
    }

    public MemberHashSet(int size) {
        hashSet = new HashSet<>(size);
    }

    public void addMember(Member member) {
        hashSet.add(member);
    }

    public void showAllMember() {
        for (Member member : hashSet) {
            System.out.println(member);
        }
        System.out.println();
    }
}
```

```java
@Override
    public boolean equals(Object obj) {
        if (obj instanceof Member) {
            Member member = (Member)obj;
            if (this.memberId == member.memberId) {
                return true;
            }
            else return false;
        }
        return false;
    }

    @Override
    public int hashCode() {
        return memberId;
    }
```

# ch13. TreeSet
## TreeSet?

- HashSet과 마찬가지로 Set 인터페이스를 구현한 클래스로써 객체를 중복해서 저장할 수 없고 저장 순서가 유지되지 않는다는 Set의 성질을 그대로 가지고 있다.
- 하지만 HashSet과는 달리 TreeSet은 이진 탐색 트리(BinarySearchTree) 구조로 이루어져 있다.
- 탐색 트리는 추가와 삭제에는 시간이 조금 더 걸리지만 정렬, 검색에 높은 성능을 보이는 자료구조
- HashSet보다 데이터의 추가와 삭제는 시간이 더 걸리지만 검색과 정렬에는 유리

## 사용

- 이진 검색트리에 저장하기 위해 각 객체를 비교해야 한다.
- 비교대상이 되는 객체에 **Comparable**이나 **Comparator** 인터페이스를 구현해야 TreeSet에 추가될 수 있다.
- String 클래스는 이미 Comparable 인터페이스가 구현되어있어 오름차순으로 정렬되어 출력됨
    
    ```java
    import java.util.TreeSet;
    
    public class TreeSetTest {
    
    	public static void main(String[] args) {
    
    		TreeSet<String> treeSet = new TreeSet<String>();
    		treeSet.add("홍길동");
    		treeSet.add("강감찬");
    		treeSet.add("이순신");
    		
    		for(String str : treeSet) {
    			System.out.println(str);
    		}
    	}
    }
    ```
    
    ```java
    강감찬
    이순신
    홍길동
    ```
    

## 인터페이스 구현 예시

### Comparable

```java
public class Member implements Comparable<Member>{

	......

	@Override
	public int compareTo(Member member) {
		
		//return (this.memberId - member.memberId);   //오름차순
		return (this.memberId - member.memberId) *  (-1);   //내림 차순
	}
}
```

### Comparator

```java
class MyCompare implements Comparator<String>{

	@Override
	public int compare(String s1, String s2) {
		return (s1.compareTo(s2)) *-1 ;
	}
}

public class ComparatorTest {
	
	public static void main(String[] args) {
		
		Set<String> set = new TreeSet<String>(new MyCompare());
		set.add("aaa");
		set.add("ccc");
		set.add("bbb");
				
		System.out.println(set);
	}
}
```

- Comparable이 이미 구현된 경우, Comparator로 비교하는 방식을 다시 구현할 수 있다.