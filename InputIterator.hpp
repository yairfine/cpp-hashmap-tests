#include <vector>

#define DOUBLE_DEREFERENCED "This input-iterator was dereferenced twice"

template <typename T>

class InputIterator
{
private:
    std::vector<T> _vec;

public:
    InputIterator() : _vec() {};
    InputIterator(std::vector<T> vec) : _vec(vec) {};

    class iterator
    {
    private:
        typename std::vector<T> _vector;
        typename std::vector<T>::iterator _iter;

        int _currentElement;

        int _size;
        bool *_checkArray;
    
    public:
        iterator(const std::vector<T> &vector, bool isEnd) : _vector(vector), _size(_vector.size())
        {
            if (isEnd)
            {
                _currentElement = _size;
                _iter = _vector.begin();
            }
            else
            {
                _currentElement = 0;
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
            _currentElement++;
            _iter++;
            return *this;
        }

        T operator*() const
        {
            if (_checkArray[_currentElement] == true)
            {
                throw std::runtime_error(DOUBLE_DEREFERENCED);
            }
            else
            {
                _checkArray[_currentElement] = true;
                return *((*this)._iter);
            }
        }

        const T &operator->() const
        {
            return *((*this)._iter);
        }

        bool operator==(const iterator &rhs) const
        {
            return (this->_currentElement == rhs._currentElement);
        }

        bool operator!=(const iterator &rhs) const
        {
            return (this->_currentElement != rhs._currentElement);
        }
    };

    iterator begin()
    {
        iterator it(this->_vec, false);
        return it;
    }

    iterator end()
    {
        iterator it(this->_vec, true);
        return it;
    }
};