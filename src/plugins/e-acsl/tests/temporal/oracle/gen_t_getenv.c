/* Generated by Frama-C */
#include "stdio.h"
#include "stdlib.h"
char *__gen_e_acsl_literal_string_2;
char *__gen_e_acsl_literal_string;
void __e_acsl_globals_init(void)
{
  __gen_e_acsl_literal_string_2 = "PATH";
  __e_acsl_store_block((void *)__gen_e_acsl_literal_string_2,sizeof("PATH"));
  __e_acsl_full_init((void *)__gen_e_acsl_literal_string_2);
  __e_acsl_mark_readonly((void *)__gen_e_acsl_literal_string_2);
  __gen_e_acsl_literal_string = "HOME";
  __e_acsl_store_block((void *)__gen_e_acsl_literal_string,sizeof("HOME"));
  __e_acsl_full_init((void *)__gen_e_acsl_literal_string);
  __e_acsl_mark_readonly((void *)__gen_e_acsl_literal_string);
  return;
}

int main(int argc, char const **argv)
{
  int __retres;
  __e_acsl_memory_init(& argc,(char ***)(& argv),(size_t)8);
  __e_acsl_globals_init();
  char *g1 = (char *)0;
  __e_acsl_store_block((void *)(& g1),(size_t)8);
  __e_acsl_full_init((void *)(& g1));
  __e_acsl_temporal_store_nblock((void *)(& g1),(void *)0);
  __e_acsl_temporal_reset_parameters();
  __e_acsl_temporal_reset_return();
  __e_acsl_full_init((void *)(& g1));
  g1 = __gen_e_acsl_getenv(__gen_e_acsl_literal_string);
  __e_acsl_temporal_pull_return((void *)(& g1));
  __e_acsl_temporal_reset_parameters();
  __e_acsl_temporal_reset_return();
  char *g2 = __gen_e_acsl_getenv(__gen_e_acsl_literal_string_2);
  __e_acsl_store_block((void *)(& g2),(size_t)8);
  __e_acsl_full_init((void *)(& g2));
  __e_acsl_temporal_pull_return((void *)(& g2));
  /*@ assert g1 ≡ \null ∨ \valid(g1); */
  {
    int __gen_e_acsl_or;
    /*@ assert
        Value: ptr_comparison: \pointer_comparable((void *)g1, (void *)0);
    */
    if (g1 == (char *)0) __gen_e_acsl_or = 1;
    else {
      int __gen_e_acsl_initialized;
      int __gen_e_acsl_and;
      __gen_e_acsl_initialized = __e_acsl_initialized((void *)(& g1),
                                                      sizeof(char *));
      if (__gen_e_acsl_initialized) {
        int __gen_e_acsl_valid;
        __gen_e_acsl_valid = __e_acsl_valid((void *)g1,sizeof(char),
                                            (void *)g1,(void *)(& g1));
        __gen_e_acsl_and = __gen_e_acsl_valid;
      }
      else __gen_e_acsl_and = 0;
      __gen_e_acsl_or = __gen_e_acsl_and;
    }
    __e_acsl_assert(__gen_e_acsl_or,(char *)"Assertion",(char *)"main",
                    (char *)"g1 == \\null || \\valid(g1)",14);
  }
  /*@ assert g2 ≡ \null ∨ \valid(g2); */
  {
    int __gen_e_acsl_or_2;
    /*@ assert
        Value: ptr_comparison: \pointer_comparable((void *)g2, (void *)0);
    */
    if (g2 == (char *)0) __gen_e_acsl_or_2 = 1;
    else {
      int __gen_e_acsl_initialized_2;
      int __gen_e_acsl_and_2;
      __gen_e_acsl_initialized_2 = __e_acsl_initialized((void *)(& g2),
                                                        sizeof(char *));
      if (__gen_e_acsl_initialized_2) {
        int __gen_e_acsl_valid_2;
        __gen_e_acsl_valid_2 = __e_acsl_valid((void *)g2,sizeof(char),
                                              (void *)g2,(void *)(& g2));
        __gen_e_acsl_and_2 = __gen_e_acsl_valid_2;
      }
      else __gen_e_acsl_and_2 = 0;
      __gen_e_acsl_or_2 = __gen_e_acsl_and_2;
    }
    __e_acsl_assert(__gen_e_acsl_or_2,(char *)"Assertion",(char *)"main",
                    (char *)"g2 == \\null || \\valid(g2)",15);
  }
  __retres = 0;
  __e_acsl_delete_block((void *)(& g2));
  __e_acsl_delete_block((void *)(& g1));
  __e_acsl_memory_clean();
  return __retres;
}


