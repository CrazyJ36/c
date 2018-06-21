#include <stdio.h>
#include <stdlib.h>

int system_result_checker();

int main() {
  system_result_checker();

}

int system_result_checker() {
  int systemRet = system("echo hello world\n");
  if (!systemRet == 0) {
    printf("System command failed\n");
  } else {
      printf("System command succeded\n");
  }
}
