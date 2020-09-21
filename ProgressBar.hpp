#ifndef PROGRESS_BAR_HPP
#define PROFRESS_BAR_HPP

#include <iostream>

#define BAR_SIZE 35

class ProgressBar
{
private:
    int _barSize;
    int _totalWork;
    int _doneWork;

    float _progress;
    
    std::string _outputMsg;
    
    bool _debugMode;

public:
    ProgressBar() : _barSize(BAR_SIZE), _totalWork(BAR_SIZE), _doneWork(0),
                    _progress(0), _outputMsg("\n\n"), _debugMode(true) {};

    ProgressBar(int totalWork) : _barSize(BAR_SIZE), _totalWork(totalWork), _doneWork(0),
                                 _progress(0), _outputMsg("\n\n"), _debugMode(false) {};

    ProgressBar &operator+=(int const &rhs)
    {
        _doneWork += rhs;
        _progress = (float) _doneWork / (float) _totalWork;
        
        if (!_debugMode)
        {
            print(std::cout);
        }

        return *this;
    }

    ProgressBar operator++(int)
    {
        _doneWork++;
        _progress = (float) _doneWork / (float) _totalWork;
        
        if (!_debugMode)
        {
            print(std::cout);
        }

        return *this;
    }

    void addToOutputMsg(const char *txt)
    {
        std::string msg(txt);
        std::string space("                                 \n");
        _outputMsg = msg + space;
        printOutputMsg(std::cout);
        _outputMsg = "\n\n";
    }

    void printOutputMsg(std::ostream &os)
    {
        os << _outputMsg;
        os.flush();
    }

    void print(std::ostream &os) const
    {
        os << "[";
        
        int position = _barSize * _progress;

        for (int i = 0; i < _barSize; i++)
        {
            if (i < position) { os << "="; }
            else if (i == position) { os << ">"; }
            else { os << " "; }
        }

        os << "] " << int (_progress * 100) << " %\r";
        
        os.flush();
    }

    int determineTotalWork() const
    {
        std::cout << "\n\n'Done-work' recorded: " << _doneWork << std::endl;

        return _doneWork;
    }

};

#endif // PROGRESS_BAR_HPP