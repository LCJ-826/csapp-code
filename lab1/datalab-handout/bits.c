/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
   return ~(~x&~y)&~(x&y);
   //return (~x & y) | (x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 0x1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
   // return (!((~(x + 1)) ^ x));
   // return !(x ^ 0x7FFFFFFF);
    return (!((~(x + 1)) ^ x)) & (!!(x + 1) ^ 0x0);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int a = 0xa;
  int aa = a | (a << 4);
  int aaaa = aa | (aa << 8);
  int ans = aaaa | (aaaa << 16);
  return !((x & ans) ^ ans);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 7
 *   Rating: 2
 */
int negate(int x) {
  return (~x + 1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a = x >> 6;
  int baseCase1 = !a;
  
  int b = x >> 4;
  int baseCase2 = !(b ^ 0x3);

  int c = x & (0xf);
  int res = c + (~0xA + 1);

  int baseCase3 = !!(res >> 31);
  return baseCase1 & baseCase2 & baseCase3;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask = ((!!x) << 31 ) >> 31;
  return ((~mask) & z) | (mask & y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int case1 = !(x ^ y);

  int signx = (x >> 31) & 1;
  int signy = (y >> 31) & 1;

  int case2 = !((!signx) & signy);
  int case3 = signx & (!signy);

  int ans1 =((x + (~y) + 1) >> 31);
  return case1 | (case2 & (case3 | ans1));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int negX = ~x + 1;
  int sign = (negX | x) >> 31;
  //int sign = !!(negX);
  return sign + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int isZero = !x;
    int flag = x >> 31;
    int mask = ((!!x) << 31) >> 31;
    x = ((~flag) & x) | (flag & (~x)); //zero bao liu x	

    int bit_16, bit_8, bit_4, bit_2, bit_1, bit_0;

    //gao wei pan cun zai bi yao xing
    bit_16 = (!((!!(x >> 16)) ^ (0x1))) << 4;
    x >>= bit_16;
    
    bit_8 = (!((!!(x >> 8)) ^ (0x1))) << 3;
    x >>= bit_8;

    bit_4 = (!((!!(x >> 4)) ^ (0x1))) << 2;
    x >>= bit_4;

    bit_2 = (!((!!(x >> 2)) ^ (0x1))) << 1;
    x >>= bit_2;

    bit_1 = (!((!!(x >> 1)) ^ (0x1))) << 0;
    x >>= bit_1;

    bit_0 = x;

    int res = bit_0 + bit_1 + bit_2 + bit_4 + bit_8 + bit_16 + 1;


    return isZero | (mask & res);
 
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	int e = (uf >> 23) & 0xFF;
	if(!e){// e = 0000 0000
		e = 0xFF;
		uf = (uf & 0x80000000) | (uf << 1);
	        //uf = uf << 1;
	}
        if(!(e ^ 0xFE)){
   	        e = 0xFF;
		uf = (uf & 0x80000000) | (e << 23);
	        //uf = (e << 23);
	}
	if(e ^ 0xFF){
		uf = uf + (1 << 23);
	}
	return uf;

}

unsigned float_i2f(int x){
/**    int e = 158;//127 + 31
    int mask = 1 << 31;
    int sign = x & mask;

    //x = -1
    if(x == mask){
        return mask | (158 << 23);
    }

    if(!x){
       return 0;
    }

    if(sign){
       x = ~x + 1;
    }

    while(!(x & mask)){
       x = x << 1;
       e = e - 1;
    }

   int frac = (x & (~mask)) >> 8;
   if(x & 0x80 && ((x & 0x7F) > 0 || frac & 0x1)){
       frac = frac + 1;		   
   }
   return sign + (e <<23) + frac;  
**/
     int sign, exp, frac, bitc, tailb;
     if(x == 0) return 0;
     else if (x == 0x80000000) return 0xCF000000;
     
     sign = (x >> 31) & 0x1;
     if(sign) x = -x;
     bitc = 1;
     while((x >> bitc) != 0)
	bitc++;
     bitc--;
     exp = bitc + 127;
     x = x << (31 - bitc);
     frac = (x >> 8) & 0x7FFFFF;
     if(bitc > 23){
         tailb = x & 0xFF;
	 
	 if((tailb > 128) || ((tailb == 128) && (frac & 0x1))){
	     frac += 1;
	     if(frac >> 23){
	         exp += 1;
		 frac = 0;
	     }
	 }
     }
     return (sign << 31) | (exp << 23) | frac;    
}


int float_f2i(unsigned uf){
    unsigned s = (uf >> 31) & (0x1);
    unsigned expr = (uf >> 23) & (0xFF);
    unsigned frac = (uf & 0x7FFFFF);

    //0
    if(expr == 0 && frac == 0){
        return 0;
    }

    //nan/inf
    if(expr == 0xFF){
        return 1 << 31;
    }
    
    //fei gui ge hua
    if(expr == 0){
        //0.xxxxx
	return 0;
    }

    //M=1.xxxx
    int e = expr - 127;
    frac = frac | (1 << 23);
    if(e > 31){
        return 1 << 31;
    }else if(e < 0){//num < 1
        return 0;
    }


    if(e > 23){
       frac <<= (e -23);//kuo rong
    }else{
       frac >>= (23 - e);//suo xiao
    }

    if(s){
        return ~frac + 1;//fu shu
    }
    return frac;
        
}
