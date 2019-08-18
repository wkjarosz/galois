/**
    @file element.h
    @author Wojciech Jarosz
    @copyright Copyright (c) 2019, Wojciech Jarosz
 */
#pragma once

#include <galois++/field.h>
#include <assert.h>
#include <iostream>

namespace Galois
{

//! Defines a Galois Field element and corresponding arithmetic operations.
class Element
{
public:
    /**
        \brief Constructs a new Element and sets its value
      
        \param gf    pointer to a Galois Field
        \param value initial value of element
     */
    Element(const Field* gf, int value = 0) : m_gf(gf), m_value(value)
    {
        if (!isValid(value))
            throw std::domain_error("invalid Galois field value");
    }

    /**
        \brief Clones an existing Element
      
        \param gfe reference to existing Element to clone
     */
    Element(const Element& gfe) : m_gf(gfe.m_gf), m_value(gfe.m_value)
    {
        // empty
    }

    //! Assigns/copies the value of another Element to this Element
    Element& operator=(const Element& rhs)
    {
        m_gf = rhs.m_gf;
        m_value = rhs.m_value;
        return *this;
    }

    //! Assigns a value to this Element
    Element& operator=(int value)
    {
        if (!isValid(value))
            throw std::domain_error("invalid Galois field value");
        m_value = value;
        return *this;
    }

    //-----------------------------------------------------------------------
    //@{ \name Access and manipulation.
    //-----------------------------------------------------------------------
    //! Returns the pointer to the Galois Field this element is associated with.
    const Field* field() const { return m_gf; }
    //! Returns true if the value is zero
    bool isZero() const { return m_value == 0; }
    //! The stored value
    int value() const { return m_value; }
    //! Set the stored value
    void setValue(int value) { m_value = value; }
    //! Check whether the value is between 0 and the GF's size q
    bool isValid() const { return isValid(m_value); }
    //! Ensure that the value is valid by modding with the GF's size q
    void makeValid() { m_value = m_value % m_gf->q; }
    //@}

    /**
        \brief Compares two GFelements, checks for equality
      
        \return true   if equal
        \return false  if not equal
     */
    friend bool operator==(const Element& lhs, const Element& rhs);

    /**
        \brief Compares two GFelements, checks for inequality
      
        \return true   if not equal
        \return false  if equal
     */
    friend bool operator!=(const Element& lhs, const Element& rhs);

    //-----------------------------------------------------------------------
    //@{ \name Addition
    //-----------------------------------------------------------------------
    //! Adds two GFelements
    Element operator+(const Element& rhs) const
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
#ifdef GF_RANGE_DEBUG
        return Element(m_gf, m_gf->plus.at(m_value, rhs.m_value));
#else
        return Element(m_gf, m_gf->plus(m_value, rhs.m_value));
#endif
    }
    //! Addition-assignment operator.
    const Element& operator+=(const Element& rhs)
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
#ifdef GF_RANGE_DEBUG
        m_value = m_gf->plus.at(m_value, rhs.m_value);
#else
        m_value = m_gf->plus(m_value, rhs.m_value);
#endif
        return *this;
    }
    //! Add a scalar to a Element
    Element operator+(int rhs) const { return (*this) + Element(m_gf, rhs); }
    //! Addition-assignment operator with a scalar.
    const Element& operator+=(int rhs) { return (*this) += Element(m_gf, rhs); }
    //! Prefix increment operator.
    Element& operator++()
    {
#ifdef GF_RANGE_DEBUG
        m_value = m_gf->plus.at(m_value, 1);
#else
        m_value = m_gf->plus(m_value, 1);
#endif
        return *this;
    }
    //! Postfix increment operator.
    Element operator++(int)
    {
        Element tmp = *this;
        ++*this;
        return tmp;
    }
    //! Adds a Element to a scalar
    friend Element operator+(int lhs, const Element& rhs);
    //@}

    //-----------------------------------------------------------------------
    //@{ \name Subtraction
    //-----------------------------------------------------------------------
    //! Returns the negated copy of this Element
    Element operator-() const { return negative(); }

    //! Subtracts two GFelements
    Element operator-(const Element& rhs) const
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
#ifdef GF_RANGE_DEBUG
        return Element(m_gf, m_gf->plus.at(m_value, m_gf->neg.at(rhs.m_value)));
#else
        return Element(m_gf, m_gf->plus(m_value, m_gf->neg[rhs.m_value]));
#endif
    }
    //! Subtraction-assignment operator.
    const Element& operator-=(const Element& rhs)
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
#ifdef GF_RANGE_DEBUG
        m_value = m_gf->plus.at(m_value, m_gf->neg.at(rhs.m_value));
#else
        m_value = m_gf->plus(m_value, m_gf->neg[rhs.m_value]);
#endif
        return *this;
    }
    //! Subtract a scalar from a Element
    Element operator-(int rhs) const { return (*this) - Element(m_gf, rhs); }
    //! Substraction-assignment operator with a scalar.
    const Element& operator-=(int rhs) { return (*this) -= Element(m_gf, rhs); }
    //! Prefix decrement operator.
    Element& operator--()
    {
#ifdef GF_RANGE_DEBUG
        m_value = m_gf->plus.at(m_value, m_gf->neg.at(1));
#else
        m_value = m_gf->plus(m_value, m_gf->neg[1]);
#endif
        return *this;
    }
    //! Postfix decrement operator.
    Element operator--(int)
    {
        Element tmp = *this;
        --*this;
        return tmp;
    }
    //! Subtracts a Element from a scalar
    friend Element operator-(int lhs, const Element& rhs);
    //@}

    //-----------------------------------------------------------------------
    //@{ \name Multiplication
    //-----------------------------------------------------------------------
    //! Multiplies two GFelements
    Element operator*(const Element& rhs) const
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
#ifdef GF_RANGE_DEBUG
        return Element(m_gf, m_gf->times.at(m_value, rhs.m_value));
#else
        return Element(m_gf, m_gf->times(m_value, rhs.m_value));
#endif
    }
    //! Multiplication-assignment operator.
    const Element& operator*=(const Element& rhs)
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
#ifdef GF_RANGE_DEBUG
        m_value = m_gf->times.at(m_value, rhs.m_value);
#else
        m_value = m_gf->times(m_value, rhs.m_value);
#endif
        return *this;
    }
    //! Right-multiplies a Element by a scalar
    Element operator*(int rhs) const { return (*this) * Element(m_gf, rhs); }
    //! Multiplication-assignment operator with a scalar.
    const Element& operator*=(int rhs) { return (*this) *= Element(m_gf, rhs); }
    //! Left-multiplies a Element by a scalar
    friend Element operator*(int lhs, const Element& rhs);
    //@}

    //-----------------------------------------------------------------------
    //@{ \name Division
    //-----------------------------------------------------------------------
    //! Divides two GFelements
    Element operator/(const Element& rhs) const
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
        if (rhs.m_value == 0)
            throw std::domain_error("cannot divide by zero");
#ifdef GF_RANGE_DEBUG
        return Element(m_gf,
                       m_gf->times.at(m_value, m_gf->inv.at(rhs.m_value)));
#else
        return Element(m_gf, m_gf->times(m_value, m_gf->inv[rhs.m_value]));
#endif
    }
    //! Division-assignment operator
    const Element& operator/=(const Element& rhs)
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
        if (rhs.m_value == 0)
            throw std::domain_error("cannot divide by zero");
#ifdef GF_RANGE_DEBUG
        m_value = m_gf->times.at(m_value, m_gf->inv.at(rhs.m_value));
#else
        m_value = m_gf->times(m_value, m_gf->inv[rhs.m_value]);
#endif
        return *this;
    }
    //! Divides a Element by a scalar
    Element operator/(int rhs) const { return (*this) / Element(m_gf, rhs); }
    //! Division-assignment operator with a scalar
    const Element& operator/=(int rhs) { return (*this) /= Element(m_gf, rhs); }
    //! Left-divides a Element by a scalar
    friend Element operator/(int lhs, const Element& rhs);
    //@}


    //-----------------------------------------------------------------------
    //@{ \name Modulo
    //-----------------------------------------------------------------------
    //! Mods two GFelements
    Element operator%(const Element& rhs) const
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
        if (rhs.m_value == 0)
            throw std::domain_error("cannot modulo by zero");
        return Element(m_gf, m_value % rhs.m_value);
    }
    //! Mod-assignment operator
    const Element& operator%=(const Element& rhs)
    {
#ifdef GF_SIZE_DEBUG
        if (m_gf->q != rhs.m_gf->q)
            throw std::runtime_error("incompatible fields");
#endif
        if (rhs.m_value == 0)
            throw std::domain_error("cannot modulo by zero");
        m_value %= rhs.m_value;
        return *this;
    }
    //! Mod an Element by a scalar
    Element operator%(int rhs) const { return (*this) % Element(m_gf, rhs); }
    //! Mod-assignment operator with a scalar
    const Element& operator%=(int rhs) { return (*this) %= Element(m_gf, rhs); }
    //! Left-mods a Element by a scalar
    friend Element operator%(int lhs, const Element& rhs);
    //@}


    //! Returns the element y in the Galois Field such that y*y = x.
    Element sqrt() const
    {
#ifdef GF_RANGE_DEBUG
        return Element(m_gf, m_gf->root.at(m_value));
#else
        return Element(m_gf, m_gf->root[m_value]);
#endif
    }

    //! Returns the multiplicative inverse of a Element.
    Element negative() const
    {
#ifdef GF_RANGE_DEBUG
        return Element(m_gf, m_gf->neg.at(m_value));
#else
        return Element(m_gf, m_gf->neg[m_value]);
#endif
    }
    //! Returns the multiplicative inverse of a Element.
    Element inverse() const
    {
#ifdef GF_RANGE_DEBUG
        return Element(m_gf, m_gf->inv.at(m_value));
#else
        return Element(m_gf, m_gf->inv[m_value]);
#endif
    }
    //@}

    //! Outputs a Element to the standard output
    friend std::ostream& operator<<(std::ostream& output, const Element& rhs);

private:
    bool isValid(int value) const
    {
        return value >= 0 && m_gf && value < m_gf->q;
    }

    const Field* m_gf; //!< Associated Galois Field
    int m_value;       //!< Stored value
};

inline bool operator==(const Element& lhs, const Element& rhs)
{
    return lhs.m_gf->q == rhs.m_gf->q && lhs.m_value == rhs.m_value;
}

inline bool operator!=(const Element& lhs, const Element& rhs)
{
    return !(lhs == rhs);
}

inline Element operator+(int lhs, const Element& rhs)
{
    return Element(rhs.m_gf, lhs) + rhs;
}

inline Element operator-(int lhs, const Element& rhs)
{
    return Element(rhs.m_gf, lhs) - rhs;
}

inline Element operator*(int lhs, const Element& rhs)
{
    return Element(rhs.m_gf, lhs) * rhs;
}

inline Element operator/(int lhs, const Element& rhs)
{
    return Element(rhs.m_gf, lhs) / rhs;
}

inline Element operator%(int lhs, const Element& rhs)
{
    return Element(rhs.m_gf, lhs) % rhs;
}

inline std::ostream& operator<<(std::ostream& output, const Element& rhs)
{
    output << rhs.m_value;
    return output;
}

} // namespace Galois