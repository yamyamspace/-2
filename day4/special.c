#define DEBUGPRINT(_fmt, ...) fprintf(Stderr, "[ %s, line %d]:" _fmt, __FILE__, __LINE__, __VA_ARGS__)
DEBUGPRINT("hey, x=%d\n", x);
