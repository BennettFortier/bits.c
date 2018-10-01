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
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  int negX = ~x;
  int negY = ~y;
  int newVal = negX|negY;
  int returnVal = ~newVal;
  return returnVal;
}
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
int s1r = x >>4;
int shift2 = x>>2;
int shift1 = x>>1;
int val3 = 0x3;
int value = (s1r ^ 0x3);
int af1 = !(shift2 ^ 0xF);
int af2 = !(shift1 ^ 0x1D);
int val = (value + af1 + af2); 
return !val;
 

}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
int bit1 = (x & 0xFF) << 24;
int bit3 = ((x >> 8) & 0xFF) << 16;
int bit5 = ((x >> 16) & 0xFF) << 8;
int bit7 = ((x >> 24) & 0xFF);
int returnBit = bit1 + bit3  + bit5  + bit7;
  return returnBit;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
int val = !!(x ^ 0x0);
int next = (val<<31) >> 31; 
int bool1 = next & y;
int bool2 = ~next & z;
int retVal = bool1 + bool2;
  return retVal;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
int consta = 0x55;
int conste = consta<<24;
int const2 = consta<<16;
int d = consta<<8;
int m1  = consta + conste + const2 + d;
int numb = 0x33;
int numb2 = numb<<24;
int numb3 = numb<<16;
int numb4 = numb<<8;
int m2 = numb+numb2+numb3+numb4;
int a = 0x0F;
int a2 = a<<24;
int a3 = a<<16;
int a4 = a<<8;
int m3 = a+a2+a3+a4;

int temp = x>>1;
int temp2 = temp & m1;
int temp3 = ~temp2;
int temp4 = temp3 + 1;
x = x + temp4;
int temp5 = (x&m2);
int temp6 = (x>>2)&m2;
x = temp5 + temp6;
int temp7 = (x&m3);
int temp8 = (x>>4)&m3;
x = temp7 + temp8;

x+= x>>8;
x+= x>>16;

int retAns = (x & 0x3F);
return retAns;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word are set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  int catch = 0x55;
  int nx = ~x;
int val = 0;
  int val2 = nx & catch;
  int val3 = nx>>8 & catch;
 int val4 = nx>>16 & catch;
 int val5 = nx>>24 & catch;
 val = val2 + val3 + val4 + val5;
 
  
return !val;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    int xor = x ^ y;
    xor = (xor >> 1) | xor;
    xor = (xor >> 2) | xor;
    xor = (xor >> 4) | xor;
    xor = (xor >> 8) | xor;;
    xor = (xor >> 16) | xor;
    int conste = 0x1<<31;

    xor = (~(xor >> 1) | conste) & xor;
    xor = ((x ^ conste) & (y ^ 0x7fffffff)) & xor;
    xor = !!xor;
    return xor;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
	  int firstByte  = x>>31 & 0x8;
  return !!firstByte;
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
   int xShift = x>>31;
   int xLShift = x<<1;
   int check = xLShift>>31 ^ xShift;
   int new_val = xLShift + x;
   int flag = new_val>>31 ^ xShift;
   int broken = flag | check;
   int conste = broken<<31;
   int const2 = conste>>31;
   int neg = 0x1 ^ xShift;
   int nr = (neg<<31)>>31;
   int rightVal = nr ^ conste;
   int retAns = (const2 & rightVal) + (~const2 & new_val);
	return retAns;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
 int first = x>>31;
 int flag = first & 0x1;
 int comp = (flag << 31) >> 31;
// int oppo = !flag;
// int nextStep = ~oppo;
// int lastbit = nextStep >> 31;
// nextStep = nextStep & lastbit;
 int newVal = flag<<31;
 int closer = comp  ^ x;
 int retVal = closer + flag;
 return retVal;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
//check if NaN or inf
int leftOne = uf<<1;
int rightAlot = leftOne>>24;
if(rightAlot != 0xFFFFFFFF){
  if(uf>>31 == 1){
  uf = uf ^ 0x80000000;	
}
}
if(uf == 0x7f800000){
return 0x7f800000;
}
if(uf == 0xff800000){
return 0x7f800000;
}
return uf;

}
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
 int isNeg = uf & 0x80000000;
 int mantissa = uf & 0x007FFFFF;
 int exp = uf & 0x7F800000;
 int mul = mantissa<<1;
 int extraExp = mul & 0x7F800000;
 int mantAgain = mul & 0x007FFFFF;
 int flag = 0;
if ( uf != 0){
flag =0x800000;
}
 int retExp = extraExp + flag + exp;
 int retAns = isNeg + retExp + mantAgain;
return retAns;

}
