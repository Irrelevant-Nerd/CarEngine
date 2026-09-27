#ifndef CAR_ENGINE
#define CAR_ENGINE

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
  double m_max_fuel_level { 60.0 }; // liters, max: 60.0
  bool m_running { false };
};

#endif /*CAR_ENGINE*/
