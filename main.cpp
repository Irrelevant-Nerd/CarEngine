#include <iostream>
#include "car_engine.hpp"

int main()
{
  CarEngine car_engine {50};
  car_engine.set_fuel(30);
  car_engine.start();
  car_engine.start();

  std::cout << "Fuel: " << car_engine.get_fuel_percentage() << "%\n";
  std::cout << "Current fuel in liters: " << car_engine.get_fuel_liters() << '\n';
  std::cout << "Max fuel in liters: " << car_engine.get_max_fuel_liters() << '\n';

  car_engine.stop();
  car_engine.stop();

  return 0;
}
