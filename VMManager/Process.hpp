
#include "PageTable.hpp"
#pragma once
class Process{

  public:

  struct ProcessControlBlock{
    PageTable pt[256]; //pagetable with 256 entries
  };
}; // container for page table 