#pragma once
struct PageFault{

    PageFault() { 
    throw  "page fault exception has occured";
    }

}; //catches page fault