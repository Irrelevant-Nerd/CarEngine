#include "car_engine.hpp"
#include <iostream>

CarEngine::CarEngine(double max_fuel_level)
  : m_max_fuel_level { max_fuel_level }
{
}

void CarEngine::start()
{
  if(m_running)
  {
    std::cout << "the engine is already running\n";
    return;
  }

  if(m_cur_fuel_level <= 0.0)
  {
    std::cout << "out of fuel, engine cannot start\n";
    return;
  }
  m_running = true;
  std::cout << "the engine is running\n";
}

void CarEngine::stop()
{
  if(m_running)
  {
    m_running = false;
    std::cout << "the engine has stopped\n";
  }
  else
    std::cout << "the engine is already off\n";
}

void CarEngine::set_fuel(double fuel_level)
{
  if(m_cur_fuel_level + fuel_level > m_max_fuel_level)
  {
    m_cur_fuel_level = m_max_fuel_level;
    std::cout << "The total amount of fuel liters already exceeds maximum liters of " << m_max_fuel_level << '\n';
  }

  else if(fuel_level > m_max_fuel_level)
  {
    m_cur_fuel_level = m_max_fuel_level;
    std::cout << "fuel liters exceeds the maximum liters of " << m_max_fuel_level << '\n';
    std::cout << "fuel level is now at " << get_fuel_percentage() << "%\n";
  }

  else if(fuel_level <= 0)
  {
    std::cout << "fuel liters is 0 or below\n";
    std::cout << "fuel level is now at " << get_fuel_percentage() << "%\n";
  }

  m_cur_fuel_level += fuel_level;
}

double CarEngine::get_fuel_percentage() const
{
  return (m_cur_fuel_level / m_max_fuel_level) * 100;
}

double CarEngine::get_fuel_liters() const
{
  return m_cur_fuel_level;
}

double CarEngine::get_max_fuel_liters() const
{
  return m_max_fuel_level;
}
