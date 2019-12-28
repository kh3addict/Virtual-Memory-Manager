

using namespace std;
#include<iostream>
#pragma once
#define TLB_SIZE 16

#define BUFFER_SIZE 10

#define OFFSET_MASK 255

#define PAGE_SIZE 256

#define PAGES 256

#define OFFSET_BITS 8
#define PAGE_MASK 255

#define MEMORY_SIZE PAGES * PAGE_SIZE
 












 class Word{
   public:
   std::uint32_t value_ = 0;
   
 };

class Address{


  private:
      
      
    Word address_;// Word for address
    Word page_;// Word for page
    Word offset_;// Word for offset 
    Word displacement_;// Word for displacement
    Word frame_;// Word for frame

 public: 


     
 
  operator std::uint32_t();
       operator std::uint32_t( )const;
       std::uint32_t value_ = 0;


     
     
    
 
    

       
     

   

    Word address(){ // getter for address

      return  address_;// return local variable

        
       
    }
     
     void address(  Word &address1){ // setter
        int   addressValue = static_cast<int>(address1.value_);// display address in decimal
        address_.value_ = addressValue; //set the local variable
       
     }

      Word displacement(){ // getter for displacement

         return displacement_; // return displacement


      }
     void displacement(  Word &offset){ // setter for displacement

       offset.value_ = address_.value_ &OFFSET_MASK;// calculate the offset

        
       displacement_ = offset; // update the local variable


        


     }

 

     Word page(){
      return page_;
     }                                                     
    void page(   Word & pageNumber ){// setter for page number 
       pageNumber.value_ = (address_.value_ >> OFFSET_BITS) & PAGE_MASK; // calculation for page number
        
       page_ = pageNumber;// set local variable page_
         

    }   


    };                          