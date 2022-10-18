/**
 * \file Timer.h
 * \author Michael Roth
 * \date 21.11.2018, last changed 29.11.2021
 *
 *
 */

#ifndef MYTIMER_H
#define MYTIMER_H

#include <chrono>
#include <iostream>
#include <string>

/**
 * \brief Timer class for measuring running time
 *
 * Objects of this class can be used to measure running time of functions or
 * arbitrary blocks of code. Objects have to be created (initialized) with a
 * string containing a message. This message is printed together with the
 * running time in Milliseconds when a Timer object is printed to an ostream. If
 * a Timer object is destroyed, it automatically prints itself to cout. The
 * timer can also be reset using the \ref reset function.
 *
 * Timer objects can also be printed to any ostream, e.g. "cout << t" with t
 * being an instance of \ref Timer
 */
class Timer
{
  typedef std::chrono::high_resolution_clock high_resolution_clock;
  typedef std::chrono::milliseconds milliseconds;

  public:
  /**
   * @brief Timer Timer class
   * @param[in] message The message to be printed to an ostream
   * @param[in] run If the timer should start on initialization. Defaults to
   * true.
   */
  explicit Timer(const std::string& message, bool run = true)
      : m_message(message)
  {
    if (run)
      reset();
  }

  /**
   * @brief Timer Destructor
   *
   * When a Timer object is destroyed, it prints the message as well as the
   * elapsed time in milliseconds to the screen
   */
  ~Timer()
  {
    std::cout << "Timer <" << m_message << ">: " << *this << " ms "
              << std::endl;
  }

  /**
   * @brief Resets the running time to relative 0
   *
   * This functions can be used to reset the Timer instance, so it can be may be
   * used again. Also, this function can be used if the Timer was not started on
   * initialization.
   */
  inline void reset()
  {
    m_time = high_resolution_clock::now();
  }

  template <typename T, typename Traits>
  /**
   * @brief Prints the current elapsed Milliseconds to the ostream
   * @param out The ostream object to print to
   * @param timer The Timer object
   * @return The modified ostream
   *
   * This overloaded operator just prints the currently elapsed Milliseconds to
   * the given ostream \ref out. Neither the message nor the "ms" is printed.
   */
  inline friend std::basic_ostream<T, Traits>&
  operator<<(std::basic_ostream<T, Traits>& out, const Timer& timer)
  {
    return out << timer.millisecondsElapsed().count();
  }

  public:
  high_resolution_clock::time_point m_time;
  std::string m_message;

  milliseconds millisecondsElapsed() const
  {
    return std::chrono::duration_cast<milliseconds>(
        high_resolution_clock::now() - m_time);
  }
};

#endif // MYTIMER_H
