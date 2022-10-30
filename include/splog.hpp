#ifndef SPLOG_H
#define SPLOG_H
#include <string>

struct Log {
  public:
    enum Level { debug, warning, error } log_level;

    Log ();
    explicit Log (Level log_level);

    void dbg (std::string message);
    void inf (std::string message);
    void wrn (std::string message);
    void err (std::string message);

  private:
    void        print_log (std::string message);
    void        print_err (std::string message);
    std::string time ();
};
#endif
