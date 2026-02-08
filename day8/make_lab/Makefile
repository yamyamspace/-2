# 1. 컴파일러 설정
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = my_program  # 실행파일

# 2. 소스 파일 및 오브젝트 파일 리스트 (직접 제시)
SRCS = 03_main.c 03_func.c
OBJS = $(SRCS:.c=.o)

# 3. 기본 빌드 규칙 
# make를 실행하면 실행 파일을 생성
all: $(TARGET)

#실행 파일 생성 (링킹 단계)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 4. 의존성 생성 규칙 (gccmakedep 사용)
depend:
	gccmakedep $(SRCS)

# 5. 정리(clean) 규칙
clean:
	rm -f $(TARGET) $(OBJS)

# 아래는 gccmakedep이 자동으로 생성한 의존성 정보
# DO NOT DELETE
03_main.o: 03_main.c /usr/include/stdc-predef.h /usr/include/stdio.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h \
 /usr/lib/gcc/x86_64-linux-gnu/9/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h 03_func.h
03_func.o: 03_func.c /usr/include/stdc-predef.h 03_func.h
