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
1. git pull
2. git add *
3. git commit -m "day1"
4. git push

c- char 디바이스
b- 블록 디바이스
l- 심볼릭 링크
d- 디렉토리
p- 파이프

## Day 2

* converting file format:
unix2dos inputfile out_dos
unix2mac infile outmac

* 파일 타입 보기
file 명령어 : 파일의 타입들을 알려줌 ex, c source, ascii text
od명령어 : octal dump 리눅스, 유닉스에서 파일 내용을 8진수, 16진수, 10진수, 아스키 등 원하는 형태로 보여줌.
od -x/o/d/c(16,8,10,ascii)

* 내 터미널 확인하는 법
    pcc028@ajousw:/dev$ ls -l std*
    lrwxrwxrwx 1 root root 15 Sep  9 21:55 stderr -> /proc/self/fd/2
    lrwxrwxrwx 1 root root 15 Sep  9 21:55 stdin -> /proc/self/fd/0
    lrwxrwxrwx 1 root root 15 Sep  9 21:55 stdout -> /proc/self/fd/1
    pcc028@ajousw:/dev$ cd /proc/
    pcc028@ajousw:/proc$ ls -l self
    lrwxrwxrwx 1 root root 0 Sep  9 21:55 self -> 1131272

    pcc028@ajousw:/proc/self$ ls -l /dev/stdin
    lrwxrwxrwx 1 root root 15 Sep  9 21:55 /dev/stdin -> /proc/self/fd/0
    pcc028@ajousw:/proc/self$ cd fd
    pcc028@ajousw:/proc/self/fd$ ls -al
    total 0
    dr-x------ 2 pcc028 pcc  0 Jan 14 11:26 .
    dr-xr-xr-x 9 pcc028 pcc  0 Jan 14 11:26 ..
    lrwx------ 1 pcc028 pcc 64 Jan 14 11:26 0 -> /dev/pts/15   //내 터미널에 연결되어있음. 각 터미널에서 디폴트로 0= stdin, 1= stdout, 2= stderr로 정해놓음.
    lrwx------ 1 pcc028 pcc 64 Jan 14 11:26 1 -> /dev/pts/15
    lrwx------ 1 pcc028 pcc 64 Jan 14 11:26 2 -> /dev/pts/15
    lrwx------ 1 pcc028 pcc 64 Jan 14 11:26 255 -> /dev/pts/15
    pcc028@ajousw:/proc/self/fd$ tty          //내 터미널 번호 보기.
    /dev/pts/15

### 표준 입출력 리디렉션

* |&는 표준 에러와 표준 출력 모두 파이프로 넘기겠다
* &>은 stderr와 stdout을 동시에 같은 파일로 리디렉션

맨 앞에 나온 파일하나를 가지고 뒤에서는 1>, 2>해서 맨 앞 파일의 출력 입력을 리디렉션 함.
예시)
* a.out < in_linux 2>&1 1> out44 :
 순차적으로 처리! stderr는 화면으로 나옴 이미 실행됨.
 1. in_linux가 stdin과 연결되어 a.out의 입력(stdin)이 in_linux파일의 내용이 됨.
 2. 2>&1에서 2는 stderr을 뜻하고 1은 stdout을 뜻한다 이 작동은 stderr를 stdout의 위치로 보내는 것이며 현재 stdout은 터미널을 향하므로 stderr는 터미널로 출력된다.
 3. 1> out44 에서 stdout이 out44라는 파일과 연결되어 out44에 출력이 나온다.  
 결과적으로 stderr와 stdout이 도중에 같은 위치로 연결되었지만 stdout이 이후 다른 곳으로 리디렉션되면서 순차성에의해 stderr과 stdout의 위치가 달라졌다.
vs
* a.out < in_linux 1> out44 2>&1
 1. in_linux의 값을 a.out이 입력으로 받는다.
 2. 1> out44 에서 a.out의 stdout이 out44파일로 간다.
 3. 2>&1에서 stderr가 stdout과 같은 곳으로 간다 즉 stderr도 out44파일에 출력된다.
 결과적으로 stderr과 stdout이 같은 파일(out44)에 존재한다.

* 다른 컴퓨터의 파일 가져오기:
cp ~pcc000/pcc2026/day2/test_wc .  // cp 다른 컴퓨터에 위치한 파일경로 .은 내 현재 디렉토리리

## Day 3

컴파일 순서:
    1. c preprocessor :   .c, .cpp, .h
    2. compiler :   include header, macro, .i
    3. assembly :   .s
    4. linker :  .o , .a
    cpp hello.c > hello.i : c preprocessor , #define값들 인라인으로 처리
    gcc -S hello.i: 어셈블리 코드
    as hello.i -o hello.o : objectfile로 변환.

유용한 기능: 
    file - determine file type
    nm - list symbols from object files
    ldd - print shared object depentancies
    objdump - disassembler of object code

* function call memory
main이 끝나면 stack(아래로 쌓임)과 heap(위로 쌓임) 메모리가 반환된다.

a.out은 디스크에 있는 실행파일 = static data로 들어가서 다시 새로 생성할 필요 없음.
- a.out을 실행할 때마다 static/data 영역도 매번 새로 매핑됨
다만, static/data 영역은
실행 중에는 계속 유지
함수 호출/반환과 무관

* 함수의 호출은 비용이 크다.
위의 코드가 짧고 함수 호출을 100만 번 한다면 위의 코드를 함수 안에 삽입 시키는게 메모리 효율적, 가독성은 좀 떨어질 수 있음.
inline function inline 함수는 성능 최적화를 위해 코드를 호출 위치에 복붙하여 코드가 길어짐.

* recursion은 성능 + 메모리 공간적으로 비싸다. inline으로도 표현 불가능.

echo $?    //첫번째 실행시 직전에 실행한 파일의 출력값이 나옴 두번째 실행시 잘 실행 됐으면 0 없는 파일이 하나라도 있으면 2(err)

cpp 파일명.c에서 #은 작동하지 않는 커멘트
cpp 파일명 // 커멘트(주석)가 사라지고, #define값이 바로 변수에 써짐 즉 처리됨.

.s파일은 어셈블리 파일

모든 함수명은 글로벌 변수다. - 어셈블리 파일로 확인가능

as main.s -o main.o //기계어 objectfile로 바뀜.

strings main.o // main.o파일에서 사람이 읽을 수 있는 부분만 출력해줌
cc -c main.c  //c 소스코드를 바로 main.o로 
cc 명령어는 gcc, cpp, gcc, as를 다 포함
main; echo $? // 명령어 두개 한번에 쓰는 법: ; 사용

cpp file.c 대신 cc -E file.c를 사용하여 #define과정에서의 문제, 전처리 (문제)를 알 수 있음. 

ld file.o -o file 을 사용하기 위해서는 file.s코드에 _start를 명시해야한다.
ls -o main.o main // main.o파일과 main파일을 long format으로 출력하는데 소유자 (owner)만 보여주고 그룹은 생략,
ls -l이 젤 많이 보여줌.(-l옵션이 full 옵션)

* multiple file compile: 
    프로파일링 하려면 함수를 쪼개야 최적화 가능. 메인함수에 다 쓰면 최적화 불가능.
    cc file1.c file2.c 하면 두개의 파일을 같이 컴파일 할 수 있음.

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
보안을 위해 다 쓴 메모리에 일부러 가비지값 넣기!

##pointer
int * a; // a는 주소, *a는 a의 주소에 있는 값은 integer
(int *) qa; //error type conversion

```c
#include <stdio.h>
int main()
{
        int b;
        int * a;
        int (*pa);
        int * qa;

        printf("%p %p %p %p\n", &b, a, pa, qa); // garbage data가 출력됨.
        a = pa = qa = &b;
        printf("%p %p %p %p\n", &b, a, pa, qa);
}
```
$ a.out
0x7ffe91f2a8dc (nil) 0x55ab8026c080 0x7ffe91f2a9f0  // garbage data, nil로 초기화 시키기!
0x7ffe91f2a8dc 0x7ffe91f2a8dc 0x7ffe91f2a8dc 0x7ffe91f2a8dc

* *&b = *(&b)는 b의 주소에 있는 값.
* null주소에 있는 값은 가져올 수 없다.
* 좋은 습관: free(pi); pi= NULL; free 후 null로 만들기.
* const(변하지 않음)가 앞에 있는 것을 수식. int * const A //A는 안변하는 포인터인데 그 안의 int 값은 변할 수 있음 int앞에는는 const없어서.
* const를 쓰고 타입 캐스팅하면 const사용 안됨. 그 외 경우에는 const값을 바꾸면 컴파일러가 에러를 내줌
* int *a; //a++ 주소 4증가
* int vector[] ={100,200,300}; int *p0= vector; //vector == &vector[0] == 배열의 첫번째 원소 주소

```c
#include <stdio.h>
int main()
{
        int arr[3] = {100,200,300};
        int * p =arr;
        int a = 0;
        a = *p + *++p;
        printf("%d\n", a);
        int l=0;
        printf("%d\n", l++ + 10*l++ + 100*++l); //310
}
```
답이 310인 이유: 처음 l++에서 계산시 0->1반영 안됨. 10*l++에서 1*10, l=2 아직 계산에 반영 안됨. ++l=3 3*100 따라서 다 더하면 310 왼쪽에서부터 순서대로 계산.

main함수에서 int * 10개 선언, fmalloc함수에 파라미터로 넘김. 주소에 malloc으로 넣어서 끝냄. 그리고 그 malloc에 데이터 쓰기.

# Day 7
## pointer of function 
* void (*foo)() : 함수이름에 괄호치기
 Compare
○ int *f4(); /* function return integer pointer
○ int (*f5)(); /* function pointer return integer
○ int* (*f6)(); /* function pointer return integer pointer
○ rearrange 
int *f4(); → int*  f4();
사칙연산
```c
#include <stdio.h>

int add(int a, int b){ return a+b; }
int sub(int a, int b){ return a-b; }
int div(int a, int b){ return b==0?0:a/b; }
int mul(int a, int b){ return a*b; }

int main()
{
        const int (*f[4])(int, int) = {add, sub, mul, div} ;
        int fval=0, a=0,b=0;
        scanf("%d %d %d", &fval, &a,&b);
        //fval 0: add....
        printf("%d\n", f[fval](a,b));
}
```
위 코드의 문제점: fval이 arr 4를 넘어갔을때 defence code필요

* 마크로 만들 때 모든 변수에 괄호치기
* 계산할때 필요한 타입 캐스팅 하기 명확하게

__STDC_NO_VLA__ //variable length array 지원 안함 크기 지정.

int* ptr1, ptr2; == int *ptr1, ptr2
int  *ptr1, *ptr2; 둘이 다름

typedef int* PINT; // typedef는 , 앞뒤로 다 적용됨.
PINT ptr1, ptr2 == int *ptr1, *ptr2

데이터 타입 바꾸는것 = aliasing 

# gdb
    * cd, list (+ 함수명){소스코드 보여줌}, run, next, continue, print, b{브레이크 포인트트}, backtrace
core dumped : 프로그램이 치명적인 에러로 죽으면서 그 순간의 메모리 상태를 core파일로 저장

Program received signal SIGSEGV, Segmentation fault.
0x000000000000001f in ?? ()
(gdb) where
    0  0x000000000000001f in ?? ()
    1  0x000055555555521d in fcall (f=0x1f, a=200, b=300) at debug.c:12
    2  0x00005555555552c6 in main () at debug.c:24
* 함수의 포인터를 쓰면 어떤 함수인지 모른다 디버깅하기 어려움

gdb = GNU Debugger
프로그램을 한 줄씩 실행하고, 메모리를 들여다보고, 죽는 지점을 정확히 잡아내는 도구
gdb 쓰기 전에 꼭 해야 할 것:
컴파일 할 때 -g옵션 쓰기
ex) gcc -g test.c -o0 test //최적화 없이 컴파일 -o0해야 gdb에서 지역변수 확인이 확실히 가능. 아니면 컴파일러가 걍 사용하고 정보 삭제해버릴수 있음

gdb시작하는 법:
gdb ./test 들어가면 (gdb)라는 프롬프트가 뜸 여기서 gdb명령어 치기

브레이크 포인트는 관찰 시작 시점ㅈ 표시, 실제 실행은 run -> breakpoint에서 멈춘 뒤 이후에 step/ print로 한줄씩 관찰하면서 오류 찾
gdb명령어:
1. b : 브레이크 포인트 걸기 ex) b main
2. run : 실행 , breakpoint에서 멈춤
3. 한줄 실행 1. next : 함수 안으로 안들어감
            2. step : 함수 안으로 들어감
4. p : 값 보기 ex) p p 또는 p *p 또는 p &p 처럼 사용가능 p == print
5. continue : 다음 breakpoint까지 진행
포인터 디버깅 핵심 기능:
1. 메모리 직접보기:
  x/4x p // 4개를 hex로 examine
  x/4c p // 4개를 char로 examine

2. segfault 났을때:
  그냥 gdb로 실행하면: run
  터지면: bt -> (backtrace) 어느 함수 어느 줄에서 터졌는지 바로 나옴.

breakpoint삭제하는 법: 
1. info breakpoints를 쳐서 num을 확인한  delete num 하면 됨.

gdb내에서 c코드 보기: list명령어

gdb 종료: quit / ctl+d
함수 종료 직전에 멈추려면 줄 번호 직접 지정 ex) b num
finish 명령은 현재 함수 끝까지 실행하고 호출한 함수로 돌아갈때 유용.

## 프로파일링(pg, gprof)
순서:
1. cc -g -pg rgba.c
2. a.out
3. gprof a.out gmon.out 

실습
이미지를 만들어서 이미지에디터를 256*256으로 만들어서 png로 세이브하고 unsinged int 256*256으로 담아주는 코드 0.5를 곱한 후(50% 어둡게) png파일로 세이브 하는 코드

# Day8

* 개발하는 아키텍처의 특징 문서 읽기 optimizaion법. ex) arm9에서는 레지스터 4개 이하(변수 4개 이하) 쓰는게 빠름.
* performance속도: cpu(레지스터 > cache(l1,l2)) > 메모리> storage > io > human( ex) scanf)
* 현재 cpu가 가진 기능. 
    * function call과 if문을 쓰면 performance가 느려짐. 분기조건 계산을 기다려야하기 때문에 파이프라인이 느려지는 문제.-> 순서바꿔서 빠르게 최적화-> 코드 뒤죽박죽됨. 소스 코드 순서 != 실제 실행 순서
    * 파이프라인 : n개의 단계로 쪼개면(=n명이 모두 일하면) n배 빨라짐
* 속도 때문에 숫자 뒤에 f꼭 붙이기 안붙이면 double이 되는데 정밀도는 올라가지만 그만큼 느려짐(약 8배). 
 
gcc 컴파일 최적화 (-O(대문자)):
-O0 (기본값): 최적화를 수행하지 않으며, 디버깅에 적합.
-O1: 컴파일 시간을 크게 늘리지 않으면서 기본적인 성능 향상 수행.
-O2: 권장 수준. 대부분의 경우 가장 안정적이고 좋은 성능 제공.
-O3: 가장 높은 수준의 최적화. 함수 인라이닝, 루프 언롤링 등을 포함하여 속도를 크게 향상시키지만 바이너리 크기가 커질 수 있음.

```c
for f in rgba_*; do echo $f >> perf.txt ; { time $f ;} 2>> perf.txt; done
```

* Makefile 만들기
 Makefile은 수많은 소스 파일을 하나하나 직접 컴파일하는 번거로움을 해결해주는 빌드 자동화 도구. Makefile을 만든 후에는 make만 치면 컴파일 됨. 
 핵심원리: 타임 스탬프 비교. 재료(dependency)가 결과물(target)보다 더 최신인가? ex) 03_main.o 와 03_main.c의 수정시간 time stamp비교하여 어떤 파일이 컴파일이 필요한지 알아냄. 
 파일이 수정되지 않았지만 컴파일 하고싶을때 "touch 파일명"을 한 후 make하면 컴파일됨.

```c
# 1. 컴파일러 설정
CC = gcc
TARGET = my_program

# 2. 소스 및 오브젝트 파일
SRCS = 03_main.c 03_func.c
OBJS = $(SRCS:.c=.o)

# 3. 디버그 모드 설정 (기본값: 1 - 켬)
DEBUG ?= 1

ifeq ($(DEBUG), 1)
    # 디버그 모드: -g(디버깅 정보), -DDEBUG_MODE(매크로 정의)
    CFLAGS = -g -DDEBUG_MODE -Wall -Wextra
    MODE_MSG = "Debug mode (with -g and -DDEBUG_MODE)"
else
    # 릴리즈 모드: -O2(최적화), 매크로 제외
    CFLAGS = -O2 -Wall -Wextra
    MODE_MSG = "Release mode (optimized)"
endif

# 4. 빌드 규칙
all: 
	@echo "Building in $(MODE_MSG)..."
	$(MAKE) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 5. 의존성 생성 (gccmakedep)
depend:
	gccmakedep $(SRCS)

# 6. 정리
clean:
	rm -f $(TARGET) $(OBJS)

# DO NOT DELETE
```