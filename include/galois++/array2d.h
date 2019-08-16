/**
 * @file array2d.h
 * @author Wojciech Jarosz
 * @copyright Copyright (c) 2019, Wojciech Jarosz
 */
#pragma once

#include <vector>

//! Generic, resizable, 2D array class.
template <typename T>
class Array2d
{
public:
    //@{ \name Constructors and destructors
    Array2d();                     // empty array, 0 by 0 elements
    Array2d(int sizeX, int sizeY); // sizeX by sizeY elements
    Array2d(const Array2d &);
    Array2d & operator=(const Array2d &);
    ~Array2d();
    //@}

    //@{ \name Element access
    T &         at(int x, int y);
    const T &   at(int x, int y) const;
    T &         operator()(int x, int y);
    const T &   operator()(int x, int y) const;
    T &         at(int i);
    const T &   at(int i) const;
    T &         operator()(int i);
    const T &   operator()(int i) const;
    const T *   row(int y) const;
    //@}
    
    //@{ \name Dimension sizes
    int width()  const { return m_sizeX; }
    int height() const { return m_sizeY; }
    
    int size()  const { return m_sizeX*m_sizeY; }
    int sizeX() const { return m_sizeX; }
    int sizeY() const { return m_sizeY; }
    //@}

    void resize(int sizeX, int sizeY);
    void reset(const T& value = T(0));
    void operator=(const T&);

protected:
    std::vector<T> m_data;
    int m_sizeX;
    int m_sizeY;
};


template <typename T>
inline Array2d<T>::Array2d():
    m_data(0), m_sizeX(0), m_sizeY(0)
{
    // empty
}


template <typename T>
inline Array2d<T>::Array2d(int sizeX, int sizeY):
    m_data(sizeX * sizeY), m_sizeX(sizeX), m_sizeY(sizeY)
{
    // empty
}


template<class T>
Array2d<T>::Array2d(const Array2d<T> & other)
  : m_data(other.m_data), m_sizeX(other.m_sizeX), m_sizeY(other.m_sizeY)
{
}


template<class T>
Array2d<T>& Array2d<T>::operator=(const Array2d<T>& other)
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
inline T & Array2d<T>::operator()(int x, int y)
{
    return m_data[y*m_sizeX + x];
}

template <typename T>
inline const T & Array2d<T>::operator()(int x, int y) const
{
    return m_data[y*m_sizeX + x];
}

template <typename T>
inline T & Array2d<T>::at(int x, int y)
{
    return m_data.at(y*m_sizeX + x);
}

template <typename T>
inline const T & Array2d<T>::at(int x, int y) const
{
    return m_data.at(y*m_sizeX + x);
}


template <typename T>
inline T & Array2d<T>::operator()(int i)
{
    return m_data[i];
}

template <typename T>
inline const T & Array2d<T>::operator()(int i) const
{
    return m_data[i];
}

template <typename T>
inline T & Array2d<T>::at(int i)
{
    return m_data.at(i);
}

template <typename T>
inline const T & Array2d<T>::at(int i) const
{
    return m_data.at(i);
}


template <typename T>
inline const T * Array2d<T>::row(int y) const
{
    return &m_data[y*m_sizeX];
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
inline void Array2d<T>::reset(const T& value)
{
    int size = m_sizeX*m_sizeY;
    for (int i = 0; i < size; i++)
        m_data[i] = value;
}


template <typename T>
inline void Array2d<T>::operator=(const T& value)
{
    reset(value);
}


