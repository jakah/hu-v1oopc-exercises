#include "hwlib.hpp"

class pin_in_and : public hwlib::pin_in {
private:
  hwlib::pin_in &pin1;
  hwlib::pin_in &pin2;
public:
  pin_in_and(hwlib::pin_in &pin1, hwlib::pin_in &pin2):
      pin1( pin1), pin2( pin2){}
  bool get(hwlib::buffering buf=hwlib::buffering::unbuffered) override {
    return !((!pin1.get()) and (!pin2.get()));
  }

};

int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   namespace target = hwlib::target;

   auto led = target::pin_out(target::pins::d6);

   auto in1 = target::pin_in(target::pins::d12);
   auto in2 = target::pin_in(target::pins::d2);

   auto sws = pin_in_and(in1, in2);

  for(;;){
     if ((sws.get()) == 0 ){
        led.set(1);
     }
     else{
       led.set(0);
     }
  }
}
