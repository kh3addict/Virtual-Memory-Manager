#include "Address.hpp"
#include "FIFO.hpp"
#include "BackingStore.hpp"
class Memmgr{



   private:
   std::list<unsigned int> freeFrameList; /* list of frames that are not occupied*/


   public:


   unsigned int frameNumber = 1;
    
//When theres a page fault this function is called to resolve it
   void pageIn(Word page, Process::ProcessControlBlock  *pcb,Word displacement, signed char *data,FIFO *fifo ){
      if(!freeFrameList.empty()){


        cout << "not empty";
         
        frameNumber = freeFrameList.front();
        pcb->pt[page.value_].frameNumber = frameNumber;
        pcb
        ->pt[page.value_].valid = true; 
        



          



          


         

        freeFrameList.pop_front();
         

      }

      else{


        cout << "empty";

        
        frameNumber = fifo->FIFO1();
          
        freeFrameList.push_back(frameNumber);

        
         
        pcb->pt[page.value_].valid = true;
        
         


        
         



      }

      BackingStore backingStore;
       
 /* reads data from backingstore */     backingStore.read(page.value_,frameNumber,displacement.value_, data, pcb  );
   }








 };




 

  

 
  
 