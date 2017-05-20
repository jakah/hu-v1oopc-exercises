#include "hwlib.hpp"
/// \file

/// \brief
/// counter that is dislayed using leds
/// \details
/// This function creates a counter that is displayed using leds, the counter
/// can be increased or decreased using buttons.
/// @param[in] leds  An array of the leds.
/// @param[in] button_increase The button that is used to increase the counter.
/// @param[in] button_decrease The button that is used to decrease the counter.
void counter( hwlib::port_out & leds, hwlib::pin_in & button_increase ,
              hwlib::pin_in & button_decrease) {
   unsigned counter = 0;
   // This variable becomes true when the increase button is pressed and changes
   // back to 0 only when the button is reased.
   bool button_increase_pressed = false;
   // This variable becomes 1 when the decrease button is pressed and changes
   // back to 0 only when the button is reased.
   bool button_decrease_pressed = false;
   for(;;){
     if (button_increase.get() == 0 && button_increase_pressed == false){
           // Check if counter value is smaller than the number of leds.
           if (counter < leds.number_of_pins()){
             counter++;
           }
           button_increase_pressed = true;
      }
      if (button_increase.get() == 1){
          button_increase_pressed =false;
      }

      if (button_decrease.get() == 0 && button_decrease_pressed == false){
          // Check if counter is smaller or equal to the number of leds.
          if (counter > 0 && counter <= leds.number_of_pins()){
            counter--;
          }
          button_decrease_pressed = true;
      }
      if (button_decrease.get() == 1){
          button_decrease_pressed = false;
      }

      for (unsigned int i = 0 ; i < counter; i++){
          leds.set( 1 << i );
      }
      // Exception for the counter value of 0 becasue no leds should be turned
      // on when counter is 0 so all leds should be of.
      if (counter == 0){
          leds.set(0x00);
      }
   }
}

/// \brief
/// The main function for this file.
/// \details
/// This is the main function, it initializes all the input and output connected
/// to the gpio pins. It then calls the counter function.
int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   namespace target = hwlib::target;

   // Initialize the leds.
   auto led0 = target::pin_out( target::pins::d7 );
   auto led1 = target::pin_out( target::pins::d6 );
   auto led2 = target::pin_out( target::pins::d5 );
   auto led3 = target::pin_out( target::pins::d4 );

   auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3);

   // Initialize the buttons.
   auto button_up = target::pin_in( target::pins::d3 );
   auto button_down = target::pin_in( target::pins::d2 );

   counter( leds, button_up, button_down);
}
