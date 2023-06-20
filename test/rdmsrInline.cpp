#include <stdio.h>
#include <cstdint>

extern "C" uint64_t __rdmsr_proc(uint64_t arg1);

int main() {
  printf("Getting information from rdmsr asm mnemonic.\n");

  // DEBUG test stuff
  //uint64_t return_value_from_rdmsr;
  // uint64_t test_return_value = __rdmsr_proc(0xDEAD);
  // printf("Test_return_value: %lld\n", test_return_value);

  uint64_t apic_base_address_command = 0xC1;
  
  // This won't work - ring 0, na userland access, sorry, for those we have to use Windows API
  printf("Apic_base_address: %llx\n", __rdmsr_proc(apic_base_address_command));

  return 0;
}
