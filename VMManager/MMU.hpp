

 
#include <iostream>
#include<list>
#include <fstream>

 
#include "Ram.hpp"
#include  "TLB.hpp"
#include "PageFault.hpp"
#include "Address.hpp"
#include "Process.hpp"
#include  "FIFO.hpp"
#include "queue"
 

 
#pragma once
class MMU{


  public:
  ifstream inz;// declare ifstream inz
  static int tlbHits; //declare tlbHits
  std::list<TLBentry> TranslationLookAsideBuffer; // declare TranslationLookAsideBuffer list for the FIFO
  TLBentry queue[16];//declare QUeue for the LRU
   
  static char  RAMz[256][256];// declare the RAMZ

  int counter = 15; // set counter = 15 for the LRU

  MMU(){ 
      tlbHits = 0; // clear TLB by sretting TLB hits to 0
      inz.open("addresses.txt");// open addresses.txt file
       
      std::cin.rdbuf(inz.rdbuf());// redirect to cin
      }

      ~MMU(){
        inz.close();//destructor closes the file
      }




       
       
/* reads logical address */
 public:
  void read( Word displacement, Word page,  Process::ProcessControlBlock *pcb, signed char *data  ,bool useFIFO ) {  
        



 
      if(useFIFO){     

       
      std::list<TLBentry>::iterator it;// if use FIFO then implement FIFO algoritim





      for(it = TranslationLookAsideBuffer.begin(); it != TranslationLookAsideBuffer.end();it++){//initially TLB will be empty to this loop wont even have effect at the beginning

        if(static_cast<std::uint32_t>(it->pageNumber )==    page.value_ ){ // but once a value gets populated in the TLB it will check
          *data = RAMz[it->frame ][static_cast<int>(displacement.value_)];// get data at the RAM using the TLB frame
          tlbHits++;// increment tlbHits
          return;// break out of the read since we read from TLB
        }
      }

         

     
       if(pcb->pt[page.value_].valid == false ){// chekc if page bit is invalid
        PageFault pf; //throw page fault
      }
         


      else {


        *data = RAMz[pcb->pt[page.value_].frameNumber][static_cast<int>(displacement.value_)];/* if page bit is valid then use the page table frame to index the ram */

        if( TranslationLookAsideBuffer.size() < 16  ){ // update the tlb

           
           
          TLBentry entry; // create a tlb entry
          entry.pageNumber = page.value_; // set the entry page number to the page value
          entry.frame = pcb->pt[page.value_].frameNumber; // set the entry frame number to the page table frame
            TranslationLookAsideBuffer.push_back(entry);// push back the entry


        }

        if( TranslationLookAsideBuffer.size() == 16  ){// if TLB size == 16


           

            
            TranslationLookAsideBuffer.pop_front();// thne pop the TRanslationLookAsideBuffer
          TLBentry entry;//create an entry
          entry.pageNumber = page.value_;
          entry.frame = pcb->pt[page.value_].frameNumber;
            TranslationLookAsideBuffer.push_front(entry);// push the entry to the front


        }
        
      }

      }

      

    


    else{// else impelement LRU
        





      for(int i = 0; i < 15;i++){
        if(static_cast<std::uint32_t>(queue[i].pageNumber) == page.value_){// check if the queue page number is equal to the page value
          *data = RAMz[queue[i].frame ][static_cast<int>(displacement.value_)];// initally this will be empty to it will skip this
          tlbHits++;
          return;// break out of the for loop and break out of the read function
        }
      }

         

     
       if(pcb->pt[page.value_].valid == false ){
        PageFault pf;// generate page fault for page invalid bit
      }
         


      else {




        cout << "Value of counter" << counter;


        


        *data = RAMz[pcb->pt[page.value_].frameNumber][static_cast<int>(displacement.value_)];
         
        if( counter > 0  ){

           counter--;
           
          TLBentry entry;
          entry.pageNumber = page.value_;
          entry.frame = pcb->pt[page.value_].frameNumber;
            queue[counter] = entry;


        }

        if( counter == 0  ){

          counter++;

          for(int i =0; i < 16;i++){

            if(i < 15){ 
            queue[i+1] = queue[i];
          }
          }
           
            
          TLBentry entry;
          entry.pageNumber = page.value_;
          entry.frame = pcb->pt[page.value_].frameNumber;
             queue[0] = entry;


        }
        
      }

      }
      



   


      

 
    

    

  } 

};


  

 