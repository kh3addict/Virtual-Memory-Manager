
#pragma once
class usedUpFrame{
  public:
  bool usedUp = false; /* each usedUpFrame has a usedUp bool which sdetermines whetehr frame is used up or not */
  int frameNumber = -99999; /* arbiritarily set the value of the frame number to -9999 */
};
 class FIFO{ /* This is the algorithim used to generate the frame for the page table */
   public:
   usedUpFrame arr[256]; // usedUpFrame array has 256 frames
   int index = 0;

  void fullUpArray(){
     int k = 0;
	for (usedUpFrame  i: usedUpFrames) {/* convert the list to an array so that we can use to index */
		arr[k++] = i;
	}

   }
   usedUpFrame findVictim(){/* find the victim frame which is the first frame that isn't used up */

   usedUpFrame framez; // declare a usedUpFrame Entry 
      
       
	 


  for(int i =0; i < 256; i++){



     
      
    if(arr[i].usedUp == false){// the first entry that is not used up

      

      index = i;// get hte index of that entry

      framez = arr[i];// set the framez equal to that element
      break; // break since we found the first one.
    }
  }

  return framez;// return the framexz
  
     }
   
      
     
   

   int FIFO1(){

 


     usedUpFrame frame = findVictim();/* find the first frme that isn't used up */
     frame.usedUp = true; // the frame has been used up
     arr[index] = frame; // fill up the array with a frame

 

 
     return frame.frameNumber;// reutrn the frame number
      
     
   }

   void fillUpUsedUpFramesList(){// Fill up used up frames list wit h 1-256 entries
     for(int i =0; i < 256; i++){
       usedUpFrame usedUp;
       usedUp.frameNumber = i;// set each frameNumber to 1....256
       usedUp.usedUp = false;// set each one to false because initially none are touched
       usedUpFrames.push_back(usedUp);// push back the frame to the usedUpFrames
     }
   } 

   public:
   Word front;
   std::list<usedUpFrame> usedUpFrames;//declare usedUpFrames list to store usedUpFrames


 };
