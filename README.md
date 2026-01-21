# 실전코딩2 강의노트

## Day 1

* Orientaion
* git project
* ssh pcc028@ssh.ajousw.kr login
* change password with passwd

```c
int main()
{
    return 10;
}
```

## Day 3

컴파일 순서:
    1. c preprocessor :   .c, .cpp, .h
    2. compiler :   include header, macro, .i
    3. assembly :   .s
    4. linker :  .o , .a

* function call memory
main이 끝나면 stack(아래로 쌓임)과 heap(위로 쌓임) 메모리가 반환된다.

a.out은 디스크에 있는 실행파일 = static data로 들어가서 다시 새로 생성할 필요 없음.
- a.out을 실행할 때마다 static/data 영역도 매번 새로 매핑됨
다만,
static/data 영역은
실행 중에는 계속 유지
함수 호출/반환과 무관

* 함수의 호출은 비용이 크다.
위의 코드가 짧고 함수 호출을 100만 번 한다면 위의 코드를 함수 안에 삽입 시키는게 메모리 효율적, 가독성은 좀 떨어질 수 있음.
inline function inline 함수는 성능 최적화를 위해 코드를 호출 위치에 복붙하여 코드가 길어짐.

* recursion은 성능 + 메모리 공간적으로 비싸다. inline으로도 표현 불가능.

## Day 4

### C Preprocessor (cpp)

* include head files
* define macro : 토큰을 macro 내용으로 대체
* conditional compilation : ex) ifndf
* line control : line number정함

* char set: utf-8

* initial processing 
    1. LF, CR LF and CR processing
    2. if -trigraphs option, process trigraphs ex) ??=을 치면 #으로 바꿔줌. #치면 define되는데 #문자 그대로를 원할때 사용
    3. long line with "\" 백슬래시 merge 여러 줄을 한줄로 병합.
    4. 모든 주석을 빈칸으로 만듬 " " : ex) ab/*...*/cd 토큰 분리.-> ab cd
* tokenization with space

* preprocessing language : 
    1. header include
    2. macro expansion : ex) $ A=100 = $A
    3. conditional compile : #def aaa 100  #if aaa >50 // 1번 후에 2번(aaa가 100으로 치환된 후) 순서 중요
    4. line control diagnostics.

        
* include file 
    1. #include가 recursion이 일어나면 안됨. 프로세스 죽음.
    2. gcc option -I 
        현재 디렉토리는 컴파일이 일어나는 위치 (현재 디렉토리는 소스코드 위치 아님)
        
        cc so/hello.c 명령어를 치면
        소스 파일 위치: so/hello.c
        컴파일이 실행된 위치: day4
        출력 파일 위치: 현재 디렉토리 (.)
        
        default include location : -I 는 default에 추가되는 경로 ./usr/include/
    3. prevent multible include 
        #pragma once
        #ifndef _MATH_
        #include <math.h>
        #endif
* conditional complilation 
    1. #if, #ifdef, #ifndef, #elif, #else, #endif
    2. delete code 
        ex) #if 0 ... #endif

vi 에디터에서 라인 넘버 보려면     :set number 치기
괄호 짝 찾아줌 : %
컴파일 할때 -D 옵션 넣으면 컴파일시 define 됨 미리 정의할 필요 없음.

* macro definiton
오퍼레이션 우선순위 헷갈리니까 무조건 괄호 쓰기!!!
함수형 매크로를 쓸때 argument (a)가 나올때마다 괄호를 싸야 함. 
ex) #define f(a) ((a)*(a))

bad ex) #define f(a) a*a  b=f(20+13)결과: b=20+13*20+13 
bad ex) #define BUFSIZE 1024
        #define TABLESIZE BUFSIZE
        #undef BUFSIZE
        #define BUFSIZE 37
TABLESIZE 결과=37. 헷갈림. 이렇게(중간에 undef, define바꾸기 x) 코드 짜면 안됨.

'if문'이 '?' operator보다 100배 느림. ?가 성능이 월등히 좋음 단, 괄호 사용 중요!
* stringization #foo을 치면 "foo"가 됨.
* concatenation a ## b을 치면 ab 붙여쓰기.

매크로로 매크로 function call하면 안됨. 나쁜 코드.

,없이 "~~~" "~~~" 하면 c컴파일러가 자동으로 concat해줌
ex)  printf("Hello World!\n" "aaaa\n");

##컴퓨터별 자료형 크기
64비트 컴퓨터 : pointer와 long이 8바이트 8*2^64 byte
 vs 차이점
32비트 컴퓨터 : pointer와 long이 4바이트 4*2^32 byte
optimize기본:
32비트 컴퓨터에서 16비트 공간 연산이 32비트 공간 연산보체다 오래걸림. convert 추가 작업 필요-> 성능이 안좋아짐.

2의보수 음수를 오른쪽으로 끝까지 shift하면 -1이 됨. 음수는 옮기면서 왼쪽에 1을 채워서 그럼. 32비트 컴퓨터에서 32비트 shift하면 양수는 0이됨.
모든 비트를 1로 만들려면 a=-1;
16비트로 표현할 수 있는 가장 큰 양의 정수 :ox7fff
32비트 // : ox7fffffff    0111이 7이라서 맨 앞이 7   0111 1111 1111 1111 1111 1111 1111 1111


## Day 5
* floating 데이터를 int로 받아서 비트를 조작하여 x2의 n제곱, /2의 n제곱을 할 수 있다. bit masking사용.
* 데이터 타입을 모르면 (void *)로 처리 가능 하지만 위험성은 있음.

### memory models
* static - 함수, 함수 내 static variable, 0으로 디폴트 초기화.
* auto - 함수 내 로컬 변수, call 할때마다 값 유지 불가능(초기화는 처음 사용할 떄 한번만) stack에서 생겼다가 return되어 사라짐.
* manual - malloc, heap에 만들어짐
* nm hello.o 명령어 : 프로그램이 사용하고 있는 메모리 상태를 보여줌. 주소 없는건 런타임에 정해지는 것들.
* cc -static hello.c : 코드 복붙 동적x 정적 할당. 대신 메모리 사용 많아짐.
* global variable은 복잡하게 짓기.
* 전역변수에 static 변수가 있으면 해당 파일내에서만 사용할 수 있는 변수임.


pcc028@ajousw:~/pcc2026/day5$ cat hello.c

이러면 안됨!!!!
```c
#include <stdio.h>

static int hello_global_a;
int global_b;

int f(int * a)
{
        int b =10;
        *a = 100;
        printf("in f() = %d %d\n", *(a+1), *(a-1));
        return (*a)*b;
}

int main()
{
        int a=0, b=1;
        f(&a);

        hello_global_a=1; global_b=2;
        printf("%d - %d %d\n", a, hello_global_a,global_b);
        return 0;
}
```
pcc028@ajousw:~/pcc2026/day5$ a.out
in f() = 1 21882 // 여기서 1은 main의 b값 근데 원래 f함수는 main의 b를 알면 안됨. 보안상 취약점! 
100 - 1 2





