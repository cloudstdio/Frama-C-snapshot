/* run.config
   OPT: -rte -rte-no-all -rte-print -rte-precond -journal-disable
*/

// if f() assigns i there might be a problem 
//@ assigns \nothing;
int f();

int main() {
  int i;
  int t[10];

  i = 0; 
  t[i] = f();
}