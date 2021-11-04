#include <stdio.h>

typedef struct s_class t_class;

typedef struct s_class
{
	int var; //멤버 변수
	// void(*constructor)(t_class *tomalloc); //생성자 포인터
	void(*method)(t_class class); //멤버 메서드	
} t_class;

/*void constructor(t_class *class)
{
	tomalloc = malloc(sizeof(t_class));
	
}*/

void method(t_class class)
{
		printf("%d\n", class.var);
}

int main()
{
		t_class class; //생성
		// class.constructor = constructor;
		class.method = method;

		class.var = 3;
		class.method(class);
}