#include <iostream>
#include "car_engine.hpp"

int main()
{
  CarEngine car_engine {120, 20};
  car_engine.set_fuel(100);

  car_engine.start();
  car_engine.start();
  std::cout << "possible distance: " << car_engine.get_possible_distance() << "km\n";
  std::cout << "consumption rate: " << car_engine.get_fuel_consumption_rate() << '\n';
  std::cout << "current fuel level before depletion: " << car_engine.get_fuel_liters() << "L\n";

  car_engine.travel(50);

  car_engine.stop();
  car_engine.stop();

  return 0;
}
