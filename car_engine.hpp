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

  CarEngine(double max_fuel_level, double fuel_liters_consumption);

  void start();

  void stop();

  void set_fuel(double new_fuel);

  double get_fuel_percentage() const;

  double get_fuel_liters() const;

  double get_max_fuel_liters() const;

  int get_possible_distance();

  double get_fuel_consumption_rate();

  double get_fuel_consumed(int distance_traveled);

  void travel(int distance_traveled);

  void check_fuel();

private:
  void calculate_possible_distance();

private:
  double m_max_fuel_level { 0.0 };
  double m_cur_fuel_level { 0.0 };

  int m_possible_distance { 0 };

  double m_fuel_consumption_rate { 0.0 };
  double m_fuel_consumed { 0.0 };

  EngineState m_engine_state {EngineState::Off};
};

#endif /*CAR_ENGINE*/
