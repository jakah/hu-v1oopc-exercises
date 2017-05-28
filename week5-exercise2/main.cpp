#include "hwlib.hpp"
class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 4 ];

public:

   pin_out_all(
      hwlib::pin_out & p0,
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,
      hwlib::pin_out & p2 = hwlib::pin_out_dummy,
      hwlib::pin_out & p3 = hwlib::pin_out_dummy
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}

   void set( bool v, hwlib::buffering buf){
      for( auto p  : list ){
          p->set( v );
      }
   }
};

class pin_out_invert : public hwlib::pin_out{
private:
  hwlib::pin_out & output;
public:
  pin_out_invert(hwlib::pin_out &output):
    output(output){}

    void set( bool x, hwlib::buffering buf=hwlib::buffering::unbuffered ) override {
          output.set( ! x );
       }
};

int main( void ){
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   namespace target = hwlib::target;
   auto ds       = target::pin_out( target::pins::d8 );
   auto shcp     = target::pin_out( target::pins::d9 );
   auto stcp     = target::pin_out( target::pins::d10 );

   auto spi_bus  = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
      stcp,
      ds,
      hwlib::pin_in_dummy
   );
  auto hc595 = hwlib::hc595( spi_bus, shcp );

   auto led0 = target::pin_out( target::pins::d3 );
   auto led1 = target::pin_out( target::pins::d6 );
   auto led2 = target::pin_out( target::pins::d5 );
   auto led3 = target::pin_out( target::pins::d4 );

   auto chip = pin_out_all(hc595.p0, hc595.p1, hc595.p2, hc595.p5);

   auto inv0 = pin_out_invert(led0);
   auto inv1 = pin_out_invert(led1);
   auto inv2 = pin_out_invert(led2);
   auto inv3 = pin_out_invert(led3);

   auto inverted = pin_out_all (inv0,inv1,inv2,inv3);
   auto leds = pin_out_all(chip,inverted);

   hwlib::blink(leds);

}
