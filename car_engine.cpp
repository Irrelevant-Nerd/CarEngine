#include "car_engine.hpp"
#include <iostream>

CarEngine::CarEngine(double max_fuel_level, double fuel_consumption_rate)
  : m_max_fuel_level { max_fuel_level }
  , m_fuel_consumption_rate { fuel_consumption_rate }
{
}

void CarEngine::start()
{
  check_fuel(); // we must check the fuel before starting

  if(m_engine_state == EngineState::On)
  {
    std::cout << "the engine is already running\n";
    return ;
  }

  else if(m_engine_state == EngineState::OutOfFuel)
  {
    std::cout << "out of fuel, engine cannot start\n";
    return;
  }

  m_engine_state = EngineState::On;
  std::cout << "the engine is running\n";
}

void CarEngine::stop()
{
  if(m_engine_state != EngineState::Off)
  {
    m_engine_state = EngineState::Off;
    std::cout << "the engine has stopped\n";
  }
  else
    std::cout << "the engine is already off\n";
}

void CarEngine::set_fuel(double fuel_level)
{
  if(fuel_level > m_max_fuel_level || m_cur_fuel_level + fuel_level > m_max_fuel_level)
  {
    m_cur_fuel_level = m_max_fuel_level;
    std::cout << "The total amount of fuel liters already exceeds maximum liters of " << m_max_fuel_level << '\n';
    std::cout << "fuel level is now at " << get_fuel_percentage() << "%\n";
    return;
  }

  else if(fuel_level <= 0)
  {
    std::cout << "fuel liters is 0 or below\n";
    std::cout << "fuel level is now at " << get_fuel_percentage() << "%\n";
    return;
  }

  m_cur_fuel_level += fuel_level;
}

double CarEngine::get_fuel_percentage() const
{
  return (m_max_fuel_level > 0.0) ? ((m_cur_fuel_level / m_max_fuel_level) * 100) : 0.0;
}

double CarEngine::get_fuel_liters() const
{
  return m_cur_fuel_level;
}

double CarEngine::get_max_fuel_liters() const
{
  return m_max_fuel_level;
}

int CarEngine::get_possible_distance()
{
  calculate_possible_distance(); // invoke the calculate_distance() everytime we want the possible distance
                                 // reason: to make sure that the possible distance is always updated everytime we invoke the get_possible_distance()
  return m_possible_distance;
}

double CarEngine::get_fuel_consumption_rate()
{
  return m_fuel_consumption_rate;
}

double CarEngine::get_fuel_consumed(int distance_traveled)
{
  // the math: (distance traveled / 100.0) * consumption rate (l/100km)
  return static_cast<double>((distance_traveled / 100.0) * m_fuel_consumption_rate);
}

void CarEngine::travel(int distance_traveled)
{
  if(m_engine_state == EngineState::Off)
  {
    std::cout << "start the engine first\n";
    return;
  }

  if(m_engine_state == EngineState::OutOfFuel)
  {
    std::cout << "out of fuel, engine cannot start\n";
    return;
  }

  std::cout << "you travelled " << distance_traveled << "km\n";

  // everytime we travel, we deplete the current fuel we have
  m_cur_fuel_level -= get_fuel_consumed(distance_traveled);
  std::cout << "current fuel level after depletion: " << get_fuel_liters() << "L\n";

}

void CarEngine::check_fuel()
{
  if(m_cur_fuel_level <= 0.0)
    m_engine_state = EngineState::OutOfFuel;
}

void CarEngine::calculate_possible_distance()
{
  // the math: (current fuel level / consumption rate (l/100km)) * 100
  m_possible_distance = static_cast<int>((m_cur_fuel_level / m_fuel_consumption_rate) * 100.0);
}



