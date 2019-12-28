
#pragma once

class PageTable{
  
 
  public:
  unsigned int frameNumber;
  char data;
  bool valid;

}; /* another way to look up a frame number bases on a page number rather than TLB */