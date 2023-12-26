/**
 * @file array2d.h
 * @author Wojciech Jarosz
 * @copyright Copyright (c) 2019, Wojciech Jarosz
 */
#pragma once

#include <vector>

/// Generic, resizable, 2D array class.
template <typename T>
class Array2d
{
public:
    Array2d();                     ///< empty array, 0 by 0 elements
    Array2d(int sizeX, int sizeY); ///< sizeX by sizeY elements
    Array2d(const Array2d &);
    Array2d &operator=(const Array2d &);
    ~Array2d();

    ///@{ \name Element access
    T &at(int x, int y);                     ///< bounds-checked 2d access
    const T &at(int x, int y) const;         ///< bounds-checked 2d access
    T &operator()(int x, int y);             ///< unchecked 2d access
    const T &operator()(int x, int y) const; ///< unchecked 2d access
    T &at(int i);                            ///< bounds-checked linear access
    const T &at(int i) const;                ///< bounds-checked linear access
    T &operator()(int i);                    ///< unchecked linear access
    const T &operator()(int i) const;        ///< unchecked linear access
    T *row(int y);                           ///< pointer to `y`-th row
    const T *row(int y) const;               ///< pointer to `y`-th row
    ///@}

    ///@{ \name Dimension sizes
    int width() const { return m_sizeX; }  ///< size of first dimension
    int height() const { return m_sizeY; } ///< size of second dimension

    int size() const { return m_sizeX * m_sizeY; } ///< total number of elements
    int sizeX() const { return m_sizeX; }          ///< size of first dimension
    int sizeY() const { return m_sizeY; }          ///< size of first dimension
    ///@}

    void resize(int sizeX, int sizeY); ///< Resize to `sizeX` x `sizeY`
    void reset(const T &value = T(0)); ///< Set all elements to `value`
    void operator=(const T &);         ///< Set all elements to `value`

protected:
    std::vector<T> m_data; ///< the data
    int m_sizeX;           ///< size of first dimension
    int m_sizeY;           ///< size of second dimension
};

template <typename T>
inline Array2d<T>::Array2d() : m_data(0), m_sizeX(0), m_sizeY(0)
{
    // empty
}

template <typename T>
inline Array2d<T>::Array2d(int sizeX, int sizeY) : m_data(sizeX * sizeY), m_sizeX(sizeX), m_sizeY(sizeY)
{
    // empty
}

template <class T>
Array2d<T>::Array2d(const Array2d<T> &other)
    : m_data(other.m_data), m_sizeX(other.m_sizeX), m_sizeY(other.m_sizeY)
{
}

template <class T>
Array2d<T> &Array2d<T>::operator=(const Array2d<T> &other)
{
    m_sizeX = other.m_sizeX;
    m_sizeY = other.m_sizeY;
    m_data = other.m_data;
    return *this;
}

template <typename T>
inline Array2d<T>::~Array2d()
{
    // empty
}

template <typename T>
inline T &Array2d<T>::operator()(int x, int y)
{
    return m_data[y * m_sizeX + x];
}

template <typename T>
inline const T &Array2d<T>::operator()(int x, int y) const
{
    return m_data[y * m_sizeX + x];
}

template <typename T>
inline T &Array2d<T>::at(int x, int y)
{
    return m_data.at(y * m_sizeX + x);
}

template <typename T>
inline const T &Array2d<T>::at(int x, int y) const
{
    return m_data.at(y * m_sizeX + x);
}

template <typename T>
inline T &Array2d<T>::operator()(int i)
{
    return m_data[i];
}

template <typename T>
inline const T &Array2d<T>::operator()(int i) const
{
    return m_data[i];
}

template <typename T>
inline T &Array2d<T>::at(int i)
{
    return m_data.at(i);
}

template <typename T>
inline const T &Array2d<T>::at(int i) const
{
    return m_data.at(i);
}

template <typename T>
inline T *Array2d<T>::row(int y)
{
    return &m_data[y * m_sizeX];
}

template <typename T>
inline const T *Array2d<T>::row(int y) const
{
    return &m_data[y * m_sizeX];
}

template <typename T>
inline void Array2d<T>::resize(int sizeX, int sizeY)
{
    if (sizeX == m_sizeX && sizeY == m_sizeY)
        return;

    m_data.resize(sizeX * sizeY);
    m_sizeX = sizeX;
    m_sizeY = sizeY;
}

template <typename T>
inline void Array2d<T>::reset(const T &value)
{
    int size = m_sizeX * m_sizeY;
    for (int i = 0; i < size; i++)
        m_data[i] = value;
}

template <typename T>
inline void Array2d<T>::operator=(const T &value)
{
    reset(value);
}
