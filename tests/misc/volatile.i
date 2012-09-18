int volatile G = 1;
volatile int F, E, X, Y, *pV;

int k = 1, x = 2, y = 3;
int a,b,c,d,e,f,g,h,i,j,l,m,n,o, *pv;

struct s { int a; volatile int b; } s1,s2={1,1};

struct sv { int a; volatile int b; };

volatile struct sv sv1, sv2={1,1};

struct sv sv3 = {3};
struct sv sv4 = {4, 5};

int main () {
  G = G;
  k = G;

  /* reading an uninitialized volatile variable */
  a = F ? 11 : 12;

  /* relations involving volatile variables */
  b = F;
  c = F;
  d = b - c; 
  e = F - F;
  g = F;
  f = F - g;
  l = F + 1;
  m = 2 + F;
  n = F - l;
  o = m - l;

  /* lval to lval assignment to volatile variable */
  h = 1;
  E = h;

  /* assignement via pointer */
  X = -1;
  Y = -1; 
  pv = (int *) &X;
  *pv = x; /* assignment to volatile X */
  x = *pv;  
  pV = &Y;
  *pV = y; /* assignment to volatile Y */
  y = *pV;
  
  return Y;
}