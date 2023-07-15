/*recognize all the strings ending with  b preceeded by n number of a's using grammer a^nb */
%{
#include "y.tab.h"
%}
%%
a  { return A; }
b  { return B; }
[\n] return '\n';
%%
