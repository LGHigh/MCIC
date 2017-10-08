
Programming Style:

  1.Trees are described by a grammer.

  2.A tree is described by one or more typedefs, corresponding to a symbol in the grammer.

  3.Each typedef defines a pointer to a corresponding struct. The struct name, which ends in an underscore, is never used anywhere except in the declaration of the typedef and the definition of the struct itself.

  4.Each struct contains a kind fiel, which is an enum showing different variants, one for each grammer rule; and a u field, which is a union.

  5.If there is more than one nontrivial (value-carrying) symbol in the right-hand side of a rule (example: the rule CompoundStm), the union will have a component that is itself a struct comprising these values (example: the compound element of the A_stm_union).

  6.If there is only one nontrivial symbol in the right-hand side of a rule, the union will have a component that is the value (example: the num field of A_exp union).

  7.Every class will have a constuctor function that initializes all the fields. The malloc function shall never be called directly, except in these constructor functions.

  8.Each module (header file) shall have a prefix unique to that module (example, A_)

  9.Typedef names (after the prefix) shall start with lowercase letters; constructor functions (after the prefix) with uppercase; enumeration atoms (after the prefix) with lowercases; and union variants (which have no prefix) with lowercase.



Modularity principles for C programs:

  1.Each phase or module of the compiler belongs in its own ".c" file, which will have a corresponding ".h" file.
  
  2.Each module shall have a prefix unique to that module. All global names (structure and union fields are not global names) exported by the module shall start with the prefix. Them the human reader of a file will not have to look outside that file to determine where a name comes from.

  3.All functions shall have prototype, and the C compiler shall be told to warn about uses of functions without prototypes.

  4.We will #include "util.h" in each file:

    *#include <assert.h>
    *
    *typedef char * string;
    *string String(char *);
    *
    *typedef char bool;
    *#define TRUE 1
    *#define FALSE 0
    *
    *void *checked_malloc(int);

    The inclusion of assert.h encourages the liberal use of assertions by the C programmer.
   
  5.The string type means a heap-allocated string that will not be modified after its initial creation. The String function builds a heap-allocated string from a C-style character pointer (just like the standard C library function strdup). Function that take strings as arguments assume that the contents will never change.

  6.C's malloc function returns NULL if there is no memory left. The Tiger compiler will not have sophisticated memory management to deal with this problem. Instead, it will never call malloc directly, but call only our own function, cheched_malloc, which guarantees never to return NULL:

    *void * checked_malloc(int len){
    *  void *p = malloc(len);
    *  assert(p);
    *  return p;
    *}
    
  7.We will never call free. Of course, a production-quality compiler must free its unused data in order to avoid wasting memory. The best way to do this is to use an automatic garbage collector. Without a garbage collector, the programmer must carefully free(p) when the structure p is about to become inaccessible--not too late, or the pointer p will be lost, but not too soon, or else still-useful data may be freed (and then overwritten). In order to be able to concentrate more on compiling techniques than on memory deallocation techniques, we can simply neglect to do any freeing.

