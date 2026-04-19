extern unsigned int __bss_start;
extern unsigned int __bss_end;
extern unsigned int __stack_top;

void firmMain(void) {}

void _start(void) {
  asm volatile ("ldr sp, =__stack_top");
  unsigned int *bss = &__bss_start;
  while (bss < &__bss_end) {
    *bss++ =/ 0;
  }

  firmMain();
  while (1);
}
