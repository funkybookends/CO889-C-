/*  $Id: RingBuffer_skel.hpp 1772 2015-12-12 16:25:57Z arr $
 *
 *  Copyright (C) 2015  Andrew R. Runnalls
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, a copy is available at
 *  http://www.r-project.org/Licenses/
 */

/** @file RingBuffer.hpp
 *
 * Header file defining class template RingBuffer<T> and associated
 * iterators.
 */

#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP 1

#include <cstddef>
#include <iterator>
#include <memory>

// This class template needs to be predeclared because the definition
// of class template _RBIterator refers to it.
template <typename T>
class RingBuffer;

// *** Following the practice with STL iterators, none of the methods
// *** of the _RBIterator class template need carry out any error
// *** checking.  For example if a client tries to increment (++) an
// *** iterator that is already at end(), the client must expect
// *** undefined behaviour: your implementation of the operator++
// *** methods does not need to make any check for this.

/** @brief Template used to implement RingBuffer<T>::iterator and
 *         RingBuffer<T>::const_iterator.
 *
 * This class template represents a random-access iterator for a
 * RingBuffer<T>.  The nested types RingBuffer<T>::iterator and
 * RingBuffer<T>::const_iterator are aliases for instantiations of
 * this template; clients should not use this template otherwise than
 * via those aliases.
 *
 * @tparam T Type of object held in the RingBuffer to which this
 *           iterator type relates.
 *
 * @tparam Pointer A pointer type, in practice either T* for an
 *         ordinary iterator or const T* for a const_iterator.
 *
 * @tparam Reference A reference type, in practice either T& or const
 *         T&.
 */
template <typename T, typename Pointer, typename Reference>
class _RBIterator {
    // The following 'friend' declaration allows one instantiation of
    // the _RBIterator template to access private members of another
    // instantiation.
    template <typename T2, typename P2, typename R2>
    friend class _RBIterator;

    // *** The following declaration is provided to allow class
    // *** RingBuffer<T> to access the private constructor of
    // *** _RBIterator.  In your solution, RingBuffer should not
    // *** exploit it to access the private data members of
    // *** _RBIterator directly.
    friend class RingBuffer<T>;
public:
    // The following nested types are used by standard algorithms (and
    // other algorithms) to infer properties of this iterator type.
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = Pointer;
    using reference = Reference;

    /** @brief Default constructor.
     *
     * The resulting iterator is not valid, and must not be used until
     * a valid iterator has been assigned to it.
     */
    // This illustrates how (since C++11) one constructor can be
    // configured to call another:
    _RBIterator()
	: _RBIterator(nullptr, nullptr)
    {}

    /** @brief Generalised copy constructor
     *
     * This constructor allows the construction of a const_iterator
     * designating the same element as an ordinary iterator supplied
     * as pattern.  However, it will not allow the construction of an
     * ordinary iterator from a const_iterator.
     *
     * @tparam P Pointer type corresponding to pattern (T* or const
     *           T*).
     *
     * @tparam R Reference type corresponding to pattern (T& or const
     *           T&).
     *
     * @param pattern Iterator to be copied.
     */
    template <typename P, typename R>
    _RBIterator(const _RBIterator<T, P, R>& pattern)
	: m_rb(pattern.m_rb), m_ptr(pattern.m_ptr)
    {}

    template <typename P, typename R>
    _RBIterator& operator=(const _RBIterator<T, P, R>& pattern)
    {
	// *** Your code goes here (6 marks)6
        // this function makes this iterator a copy of pattern
        //it copies the pointer to the pattern
        // and to the current pointer
        //that doesn't seem enough for 6 marks though.

        m_rb = pattern.m_rb;
        m_ptr = pattern.m_ptr;

    }

    Reference operator*() const
    {
	// *** Your code goes here (2 marks)8
        return *m_ptr;
    }

    Pointer operator->() const
    {
	// *** Your code goes here (2 marks)10
        return &m_ptr;
    }

    // *** In the following method, you may assume that rhs relates to
    // *** the same RingBuffer as *this.
    bool operator==(const _RBIterator& rhs) const
    {
	//return false;  // *** Replace this with your code (2 marks)12
        return (rhs.m_rb == m_rb) && (rhs.m_ptr == m_ptr);
    }

    bool operator!=(const _RBIterator& rhs) const
    {
	return !operator==(rhs);
    }

    _RBIterator& operator++()
    {
	// *** Your code goes here (4 marks)16
        stepForward(m_ptr,1);
    }

    _RBIterator operator++(int)
    {
	// *** Your code goes here (6 marks)22
    }

    _RBIterator& operator--()
    {
	// *** Your code goes here (4 marks)26
        stepForward(m_ptr, -1);
    }

    _RBIterator operator--(int)
    {
	// *** Your code goes here (6 marks)32
    }

    _RBIterator& operator+=(difference_type n)
    {
	// *** Your code goes here (4 marks)36
    }

    _RBIterator operator+(difference_type n)
    {
	// *** Your code goes here (4 marks)40
    }

    // It would be logical to define operator-= and operator-
    // corresponding to the previous two methods, but we won't
    // bother.

    // *** In implementing the following method, you may assume that
    // *** rhs relates to the same RingBuffer as *this.
    difference_type
    operator-(const _RBIterator& rhs) const
    {
	return 0;  // *** Replace this with your code (14 marks)54
    }

    Reference operator[](difference_type n)
    {
	// *** Your code goes here (2 marks)56
    }
private:
    // Pointer to the RingBuffer to which this iterator relates:
    const RingBuffer<T>* m_rb;

    // Pointer to the slot of the T array designated by this iterator:
    Pointer m_ptr;

    // Private constructor for use by RingBuffer<T>:
    _RBIterator(const RingBuffer<T>* ringbuffer, Pointer ptr)
	: m_rb(ringbuffer), m_ptr(ptr)
    {}

};

template <typename T, typename Pointer, typename Reference>
inline bool
operator<(const _RBIterator<T, Pointer, Reference>& l,
	  const _RBIterator<T, Pointer, Reference>& r)
{
    return false;  // *** Replace this with your code (2 marks)58
}

/** @brief Ring Buffer.
 *
 * @tparam T Type of object to be contained in the RingBuffer.
 */
template <typename T>
class RingBuffer {
    // *** The follow declaration is provided to allow methods of the
    // *** class template _RBIterator to access the private methods of
    // *** this class.  In your solution, _RBIterator should not
    // *** exploit it to access the data members of RingBuffer
    // *** directly.
    template <typename, typename, typename>
    friend class _RBIterator;
public:
    using size_type = std::size_t;
    using value_type = T;
    using iterator = _RBIterator<T, T*, T&>;
    using const_iterator = _RBIterator<T, const T*, const T&>;

    /** @brief Constructor.
     *
     * @param capacity Desired capacity of the RingBuffer.
     */
    RingBuffer(std::size_t capacity)
	: m_buffer(new T[capacity + 1]),
	  m_base(m_buffer.get()),
	  // *** If you are attempting the challenging version of the
	  // *** assessment, you will need to modify the preceding
	  // *** two lines.
	  m_limit(m_base + capacity + 1), m_begin(m_base), m_end(m_base)
    {}

    RingBuffer(const RingBuffer& pattern)
	: RingBuffer(pattern.capacity())
    {
	// *** Your code goes here (4 marks)62
        m_buffer = new T[pattern.capacity + 1]; //make a new array of the 
                                                //right size
        m_base = m_buffer.get(); //find its base value
        m_limit = m_base + pattern.capacity + 1; //and set the limit
        m_begin = (pattern.m_begin - pattern.m_base) + m_base;
        m_end = (pattern.m_begin - pattern.m_end) + m_base;

        //we could be smart and only copy in the things between begin and end
        //but it's way simpler to just copy all of it, then we don't have to
        //worry about looping round correctly.

        //although perhaps we could just get a const iterator and start 
        //filling ourselves in with the pattern from begin to end?
        std::copy(pattern.m_base, pattern.m_limit, m_begin);


    }

    ~RingBuffer()
    {
	// *** Your code goes here (2 marks)64
        delete m_buffer;
        //do I need to delete the other things as well? they're not on the 
        //free store

    }

    // The following declaration prevents the compiler from generating
    // a default assignment operator for RingBuffer, and thus
    // prohibits assigning one RingBuffer to another.
    RingBuffer& operator=(const RingBuffer& rhs) = delete;

    iterator begin()
    {
	// *** Your code goes here (2 marks)66
        return _RBIterator(*this,m_begin);
    }

    const_iterator begin() const
    {
	// *** Your code goes here (2 marks)68
        return _RBIterator(*this,m_begin);
    }

    const_iterator cbegin() const
    {
	// *** Your code goes here (2 marks)70
        return _RBIterator(*this,m_begin);
    }

    /** @brief Capacity of the RingBuffer.
     *
     * @return The capacity of this RingBuffer.
     */
    size_type capacity() const
    {
	//return 0;  // *** Replace this with your code (2 marks)72
        return m_limit - m_base - 1;
    }

    /** @brief Remove all data from this RingBuffer.
     *
     * After this call, the RingBuffer will be empty.
     */
    void clear()
    {
	// *** Your code goes here (4 marks)76
        //while not empty, pop
        while (!empty()) {
            pop_front();
        }
    }

    /** @brief Test whether RingBuffer is empty.
     *
     * @return true if and only if the ring buffer is empty, otherwise
     * false.
     */
    bool empty() const
    {
	//return false;  // *** Replace this with your code (2 marks)78
        return m_begin == m_end;
    }

    iterator end()
    {
	// *** Your code goes here (2 marks)80
        return _RBIterator(*this, m_end);
    }

    const_iterator end() const
    {
	// *** Your code goes here (2 marks)82
        return _RBIterator(*this, m_end);
    }

    const_iterator cend() const
    {
	// *** Your code goes here (2 marks)84
        return _RBIterator(*this, m_end);
    }

    /** @brief Element at the front of the queue.
     *
     * @return Reference to the T object at the front of the queue
     * represented by this RingBuffer.  Effect undefined if the
     * RingBuffer is empty.
     */
    T& front()
    {
	// *** Your code goes here (2 marks)86
        return *m_begin;
    }

    const T& front() const
    {
	// *** Your code goes here (2 marks)88
        return *m_begin;
    }

    /** @brief Remove the element at the front of the queue.
     *
     * Removes the first element from the queue represented by this
     * RingBuffer.  Does nothing if the queue is empty.
     */
    void pop_front()
    {
	// *** Your code goes here (10 marks)98
        if (!empty()) {
            m_begin = stepForward(m_begin, 1);
        }
    }

    /** @brief Add element at the end of the queue.
     *
     * @param elem A copy of elem will be appended to the queue
     *             represented by this RingBuffer.  If the RingBuffer
     *             is already full, the RingBuffer is left unchanged
     *             and an exception of type std::length_error is thrown.
     */
    void push_back(const T& elem)
    {
	// *** Your code goes here (12 marks)110
        //puts the elemet at the end if there is space
        //and then steps m_end forward
        if (size()<capacity()){
            *m_end = elem;
            stepForward(m_end);
        }
    }

    size_type size() const
    {
	//return 0;  // *** Replace this with your code (2 marks)112
        if (m_begin <= m_end) {
            return m_end - m_begin;
        }
        else {
            return m_begin - m_end;
        }
    }
private:
    // This is a special syntax (not examinable) for declaring a
    // std::unique_ptr that points to an array of objects in the free
    // store.
    std::unique_ptr<T[]> m_buffer;

    // *** If you are attempting the challenging version of the
    // *** assessment, comment out the preceding declaration of
    // *** m_buffer, and uncomment the following one:
    //std::unique_ptr<char[]> m_buffer;

    T *m_base;   // Pointer to the beginning of the array of T objects
		 // implementing the ring buffer.

    T *m_limit;  // Pointer to a location 'one beyond' the array of T
		 // objects implementing the ring buffer.  (NB: this
		 // points outside the T array, and therefore must not
		 // be dereferenced.)

    T *m_begin;  // Pointer to the slot of the T array corresponding
		 // to the begin() iterator, i.e. the same slot as
		 // m_end if the buffer is empty, otherwise the slot
		 // containing what, from the client's point of view,
		 // it the first entry in the buffer.

    T *m_end;    // Pointer to the slot of the T array corresponding
		 // to the end() iterator, i.e. the same slot as
		 // m_begin if the buffer is empty, otherwise the slot
		 // one beyond (wrapping around if necessary) what,
		 // from the client's point of view, is the last entry
		 // in the buffer.

    // Ptr will be either T* or const T*.  This method returns a
    // pointer to the T array slot 'steps' steps along from the slot
    // pointed to by 'ptr', taking steps forwards if 'steps' is
    // positive (wrapping around from the end of the array to the
    // beginning if necessary) and taking steps backwards if 'steps'
    // is negative (wrapping around from the beginning of the array to
    // the end of the array if necessary).  (If 'steps' is zero, the
    // method returns 'ptr'.)  You may assume that at most one
    // wraparound will be necessary.
    template <typename Ptr>
    Ptr stepForward(Ptr ptr, std::ptrdiff_t steps) const
    {
	// *** Your code goes here (18 marks)130
        //check the end condition
        if (steps == 0){
            return ptr;
        }

        //take a step
        else if (steps > 0) {
            ptr++;
            steps --;
        }
        else {
            ptr--;
            steps ++;
        }

        //fix wrap arounds
        if (ptr == m_limit) {ptr = m_base;}
        else if (ptr == m_base-1) {ptr = m_limit;}

        //return the next step
        return stepForward(ptr, steps)
    }
};

/** @brief Equality test for RingBuffers.
 *
 * @param l Left-hand operand.
 *
 * @param r Right-hand operand.
 *
 * Note that two objects of type RingBuffer<T> are to be considered
 * equal if they have the same content, i.e. they have the same number
 * of T objects in their respective queues, the first elements in each
 * queue are equal, the second elements are equal, and so on.  It is
 * not necessary that l and r have the same capacity.
 */
template <typename T>
bool operator==(const RingBuffer<T>& l,
		const RingBuffer<T>& r)
{
    return false;  // *** Replace this with your code (22 marks)152
    //gets two const iterators and iterates through them checking that
    // all the elements are the same
}

template <typename T>
bool operator!=(const RingBuffer<T>& l,
		const RingBuffer<T>& r)
{
    return !(l == r);
}

#endif  // RINGBUFFER_HPP
