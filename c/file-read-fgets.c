#include <stdio.h>

#define LEN 1000

int main()
{
  char* file_name = "file.txt";
  FILE *file_pointer;
  char string_buffer[LEN];

  file_pointer = fopen(file_name, "r");
  if (file_pointer == NULL) {
    printf("No file named 'file.txt' in this directory!\n");
    return(1);
  }

  // fgets declaration:
  // char *fgets(char *str_to_read, int max_char_in_read_array, FILE *stream_to_read_from)
  while (fgets(string_buffer, LEN, file_pointer) != NULL) {
    printf("%s", string_buffer);
  }

  fclose(file_pointer);
  return(0);
}
