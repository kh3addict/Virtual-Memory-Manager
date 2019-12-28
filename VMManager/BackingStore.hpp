
#pragma once
#include "Ram.hpp"
#include"MMU.hpp"
 
class BackingStore{// BackingStore class

    public:
     

    
     
     ifstream BackingStoreDotBin; // call backing Store construcor
     

    BackingStore(){
     BackingStoreDotBin.open("BACKING_STORE.bin", ios::binary); // backingstore construcotr opens binary file

    }

    ~BackingStore(){
      BackingStoreDotBin.close();// destructor closes binary file

    }
     void read(int page, int frameNumber, int displacement, signed char  *data,Process::ProcessControlBlock  *pcb   ){
        
       if(BackingStoreDotBin.is_open()){ // if backing Store .bin sucessfully opened
         char Frame[256];// then create a frame variable
         int numberToStartReadingFile = page * 256; // start reading BackingStore at desired page 
         
         BackingStoreDotBin.seekg(numberToStartReadingFile);// seek to that location 
         BackingStoreDotBin.read(Frame,256); // read 256 bytes from the starting position
          
         


          

         for(int i =0; i < 256; i++){
             MMU::RAMz[frameNumber][i] = Frame[i];/* Index Ram by Frame number and set the data at the frame number to the frames data */
         }            
 
         *data =    MMU::RAMz[frameNumber][static_cast<int>(displacement)] ; /* Get the data at the ram  uising the frame number and the displacement */


          


          

          
         
         pcb->pt[page].data  = *data;// update the page table accordingly
          
          

       }


     }
  };
