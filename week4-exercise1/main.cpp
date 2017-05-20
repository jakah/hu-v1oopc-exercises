#include "hwlib.hpp"
/// \file

/// \brief
/// kitt function
/// \details
/// This function shows a kitt display on the leds connected to a port.
/// Each group of two leds is on for m milliseconds.
void kitt( hwlib::port_out & leds, int ms = 400 ){
   for(;;){
      for( unsigned int i = 0; i < leds.number_of_pins() - 1 ; ++i ){
         leds.set( 0x03 << i );
         hwlib::wait_ms( ms );
      }
      for( unsigned int i = leds.number_of_pins() - 3; i > 0; --i ){
         leds.set( 0x03 << i );
         hwlib::wait_ms( ms );
      }
   }
}
/// \brief
/// The main function for this file.
/// \details
/// This is the main function, it initializes all the leds connected to the
/// gpio pins. It then calls the kitt function.
int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   namespace target = hwlib::target;
   // Initialize the leds.
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );

   auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3 );

   ::kitt( leds );
}
