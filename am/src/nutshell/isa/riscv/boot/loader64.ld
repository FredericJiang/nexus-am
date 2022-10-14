pmem_base = 0x60000000;

MEMORY {
  ram (rwxa) : ORIGIN = 0x60000000, LENGTH = 128M
}

INCLUDE "section.ld"
