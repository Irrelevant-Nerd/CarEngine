#ifndef CAR_ENGINE
#define CAR_ENGINE

enum class EngineState
{
  On,
  Off,
  OutOfFuel
};

class CarEngine
{
public:
  CarEngine() = default;

  CarEngine(double max_fuel_level);

  void start();

  void stop();

  void set_fuel(double new_fuel);

  double get_fuel_percentage() const;

  double get_fuel_liters() const;

  double get_max_fuel_liters() const;

private:
  double m_cur_fuel_level { 0.0 };
  double m_max_fuel_level { 0.0 };
  EngineState m_engine_state {EngineState::Off};
};

#endif /*CAR_ENGINE*/
