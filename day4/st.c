#define AAA 100
#define KKK AAA AAABBB
#define KKKK(a) #a
#define _FAA(_FAA_PARAM_1_AAA)    2*(_FAA_PARAM_1_AAA)
#define CAT(A,B) A##B

KKKK(KKK)
AAA
#undef AAA //UNDEFINE

#define AAABBB CCCCCCCC
CAT (AAA, BBB)

#define AAA 200 
_FAA(2032)
AAA

__LINE__
__FILE__
printf("%s", __DATE__)
