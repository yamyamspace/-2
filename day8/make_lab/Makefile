# 1. Ç·α׷¥ ¼³d
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = my_program

# 2. ¼ҽº ¹×¿:êƮ ÆÀ ¸®½ºƮ
SRCS = 03_main.c 03_func.c
OBJS = $(SRCS:.c=.o)

# 3. ±⺻ ºô±Ô¢
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 4. Àx¼º »ýĢ (gccmakedep »ç)
depend:
	gccmakedep $(SRCS)

# 5. d¸® ±Ô¢
clean:
	rm -f $(TARGET) $(OBJS)

# À ¶ó¾Ʒ¡¿¡ gccmakedepÀ Àx¼º dº¸¸¦ Àµ¿8·ÎÃ°¡Ç´ϴÙ
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
