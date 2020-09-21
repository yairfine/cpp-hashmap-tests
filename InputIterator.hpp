#include <vector>

#define DOUBLE_DEREFERENCED "This input-iterator was dereferenced twice"

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

        int _currentElement;

        int _size;
        bool *_checkArray;
    
    public:
        iterator(const std::vector &vector, bool isEnd) : _vector(vector), _size(_vector.size())
        {
            if (isEnd)
            {
                _currentElement(_size);
                _iter = _vector.begin();
            }
            else
            {
                _currentElement(0);
                _iter = _vector.end(); 
            }

            _checkArray = new bool[_size - 1];

            for (int i = 0; i < _size; i++)
            {
                _checkArray[i] = false;
            }
        }

        ~iterator()
        {
            delete[] _checkArray;
        }

        iterator &operator++()
        {
            _currentElement++;
            _iter++;
            return *this;
        }

        iterator operator++(int)
        {
            _iter++;
            return *this;
        }

        iterator operator*()
        {
            if (_checkArray[_currentElement] == true)
            {
                throw std::runtime_error(DOUBLE_DEREFERENCED);
            }
            else
            {
                _checkArray[_currentElement] = true;
                return *(_iter);
            }
        }
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