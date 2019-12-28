 


#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include<string>
#include<cstring>
#include<cstdint>
#include<sstream>
#include <list>
 
#include "PageTable.hpp"
#include "Process.hpp"
#include "MemoryManager.hpp"
#include "PageFault.hpp"
#include "MMU.hpp"
#include  "FIFO.hpp"
#include "TLB.hpp"
#include "Address.hpp"
#include "Ram.hpp"
#include "BackingStore.hpp"
 



#define PAGE_REPLACEMENT   1 // Set to 1 if you want FIFO page replacement policy
char MMU::RAMz[256][256]; // The physical RAM accessed by frame Number and offset
int MMU::tlbHits ; // tlb hits - the number of time the tlb is accessed 
 

int main(){
 
 bool useFIFO;

   
#if (PAGE_REPLACEMENT) // if page replace ment is 1 set useFIFO to true else set it to false

 useFIFO = true; //Uses FIFO algorithm 

 #else

 useFIFO = false; //Uses LRU algorithm

#endif






  int pageFaults = 0; // set page Faults = 0


   Memmgr mmgr; // declare mmgr to call the constructor
    


  Process::ProcessControlBlock pcb;//define pcb
  PageTable pte; // define the page table entry
  for(int i = 0; i < 256; i++){
     
    pte.valid = false; // originally set all page table entrys to invalid
    pcb.pt[i] = pte; // push the page table entry. into the page table.
  }
 
   

 
 
  

 
 
 
 FIFO fifo; // declare FIFO object so that we can use the fillupusedFramesListfunction and array
fifo.fillUpUsedUpFramesList();
  

 fifo.fullUpArray();
 
 Word logicalAddress;// declare a Word for the logical address


MMU mmu; // call the MMU() constructor to open the addresses.txt file
 

 

while(cin >> logicalAddress.value_ ){/* redirect the addresses.txt file to stdinput and store value in logical address */

 
   
   Address logicalAddress1;
   
   Word logicalAddress_; // Wrod to store logical address
   Word displacement_; // Word to store displacement
   Word page_; // Word to store the page
   signed char data_; // store the data
  
     logicalAddress1.address(logicalAddress);//call setter for logicalAddress
     logicalAddress_ = logicalAddress;
     logicalAddress1.displacement(logicalAddress_);//call setter for displacement   
     displacement_  = logicalAddress1.displacement();// call getter for displacement

     logicalAddress1.page(logicalAddress_);// call setter for page number
     page_  = logicalAddress1.page();//call getter for page number

      





     try{mmu.read(  displacement_,page_, &pcb, &data_  ,useFIFO);//try to read in a logcial Address if page bit is set to invalid then throw page fault exception

      int physicalPage = pcb.pt[page_.value_].frameNumber;// get the physical page or frame number
      int physicalAddress =   (physicalPage  << 8) | static_cast<int>(displacement_.value_);//calculate the physical address
     cout << "Logical Address " <<  logicalAddress.value_ << "Physical Address is " << physicalAddress << "\n" ; /* display logical address value and physical Address value */
      cout <<  static_cast<signed int>(data_) << "\n" ; /* display data at the physical address */

      

     }

       

     catch( const  char * pageFault ){/* catch the page fault exception that resulted from the invalid bit */



      pageFaults++;// increment number of page faults






      

       
        

 


       mmgr.pageIn(page_, &pcb,displacement_,&data_,&fifo);// page in twice to resolve the page fault
       mmgr.pageIn(page_, &pcb,displacement_,&data_,&fifo);


      std::cout << pageFault << "\n";



       mmu.read( displacement_,page_, &pcb, &data_  ,useFIFO); // read the logical Address again and check if that page has invalid bit

        cout << " PAge fault resolved at" << logicalAddress.value_ <<  "Data at the physical Address is "  <<    static_cast<signed int>(data_) << "\n";/* page fault should be resolved to display data at physical address */


         


 
     }

    

      }



       cout << "Number of pagefaults ==  " << pageFaults << "\n"; //outputs faults
       cout << "Number of tlb hits == " << MMU::tlbHits << "\n"; //outputs hits
 

     } 


 

      


 

 
 

   
    
       


  



      

       
 

 


  
 


 

 


 


   
    
  
    

    
    
  
   
   


 
    
  
  
   
 
 
 