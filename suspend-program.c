/* raise(SIGNAL_CODE); can start, or send A signal.
   This suspends the program. You can see it running
   in the background with the 'jobs' bash command.
   And you can end the background process with:
   kill -KILL %1 //or other job number
   or just type 'fg' then CTRL-C.
*/

#include <stdio.h>
#include <signal.h>

int main() {
  raise(SIGTSTP); // (sigint 17,19,23)
  // at this point if i do sigcont, i can continue working,
  //   or print confirmations that it is back.
}


