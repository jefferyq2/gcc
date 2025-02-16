/* { dg-options "-O3 -mcpu=v6.00.a -mcpu=v6.00.a" } */

volatile int m1, m2, m3;
volatile long l1, l2;
volatile long long llp;
volatile unsigned int u1, u2, u3;

volatile unsigned long ul1, ul2;
volatile unsigned long long ullp;

int test_mul () {

  /* { dg-final { scan-assembler-not "mul\tr" } } */
    m1 = m2 * m3 ;

  /* { dg-final { scan-assembler-not "muli" } } */
    m3 = m1 * 1234 ;    

  /* { dg-final { scan-assembler-not "mulh" } } */
    llp = ((long long)l1 * l2);

  /* { dg-final { scan-assembler-not "mulhu" } } */
    ullp = ((unsigned long long)ul1 * ul2);

  /* { dg-final { scan-assembler-not "mulhsu" } } */
    llp = ((long long)l1 * ul2);        

  /* { dg-final { scan-assembler-not "bslli" } } */
    m3 = m2 << 25;

  /* { dg-final { scan-assembler-not "bsll" } } */
    m2 = m1 << m3;

  /* { dg-final { scan-assembler-not "bsrai" } } */
    m3 = m2 >> 25;

  /* { dg-final { scan-assembler-not "bsra" } } */
    m2 = m1 >> m3;

  /* { dg-final { scan-assembler-not "idiv" } } */
    m1 = m2 / m1;

  /* { dg-final { scan-assembler-not "idivu" } } */
    u1 = u2 / u3;    

  /* { dg-final { scan-assembler-not "pcmpne" } } */
    m3 = (m3 != m1);

  /* { dg-final { scan-assembler-not "pcmpeq" } } */
    return (m1 == m2);
}



volatile float f1, f2, f3;

void float_func () 
{
  /* { dg-final { scan-assembler-not "fmul" } } */
    f1 = f2 * f3;

  /* { dg-final { scan-assembler-not "fadd" } } */
    f1 = f2 + f3;

  /* { dg-final { scan-assembler-not "frsub" } } */
    f1 = f2 - f3;

  /* { dg-final { scan-assembler-not "fdiv" } } */
    f1 = f2 / f3;

}

void float_cmp_func () 
{
    /* { dg-final { scan-assembler-not "fcmp" } } */
    if (f2 <= f3) 
        f1 = f3;
    else if (f2 == f3) 
        f1 = f3;
    else if (f2 < f3) 
        f1 = f3;
    else if (f2 > f3) 
        f1 = f3;
    else if (f2 >= f3) 
        f1 = f3;
    else if (f2 != f3) 
        f1 = f3;
    
}
