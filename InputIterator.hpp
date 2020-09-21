#include <vector>

template <typename T>

class InputIterator
{
private:
    std::vector<T> _vec;

public:
    InputIterator() : _vec(std::vector<T> vec) {};
    InputIterator(std::vector<T> vec) : _vec(vec) {};

    class iterator
    {
    private:
        std::vector<T> _vector;
        std::vector<T>::iterator _iter;

        int _size;
        bool *_checkArray;
    
    public:
        iterator(const std::vector &vector, bool isEnd) : _vector(vector), _size(_vector.size())
        {
            if (isEnd)
            {
                _iter = _vector.begin();
            }
            else { _iter = _vector.end(); }

            _checkArray = new bool[_size - 1];

            for (int i = 0; i < _size; i++)
            {
                
            }
        }

        ~iterator()
        {
            delete[] checkArray;
        }

        iterator &operator++()
        {
            _iter++;
            return *this;
        }

        iterator operator++(int)
        {
            _iter++;
            return *this;
        }

        iterator()
    }

    iterator begin()
    {
        iterator it(*this, false);
        return it;
    }

    iterator end()
    {
        iterator it(*this, true);
        return it;
    }
};