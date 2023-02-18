/**
 * TODO: Complete this class!
 */

/// Your welcome
#include <assert.h>
#include <iostream>
#include <string>

//
template <typename T>
class MyVector
{
public:
	/*******************
	 * Static constants
	 ******************/

	/// Default capacity
	static constexpr size_t DEFAULT_CAPACITY = 64;

	/// Minimum capacity
	static constexpr size_t MINIMUM_CAPACITY = 8;

	/*****************************
	 * Constructors / Destructors
	 ****************************/

	/// Normal constructor
	MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY)
	{
		// TODO: Your code here
		size_ = 0;
		capacity_ = capacity;
		elements_ = new T[capacity_];
	}

	/// Copy constructor
	MyVector(const MyVector &other)
	{
		// TODO: Your code here
		size_ = other.size();
		capacity_ = other.capacity();
		elements_ = new T[capacity_];
		for (size_t i = 0; i < size_; i++)
		{
			elements_[i] = other[i];
		}
	}

	/**
	 * Destructor
	 * Should call clear() so each element gets its destructor called.
	 * Then, de-allocate the internal array and make it a nullptr, if its not already a nullptr.
	 */
	~MyVector()
	{
		// TODO: Your code here
		delete[] elements_;
		elements_ = nullptr;
	}

	/************
	 * Operators
	 ************/

	///	Assignment operator
	MyVector &operator=(const MyVector &rhs)
	{
		// TODO: Your code here
		size_ = rhs.size();
		capacity_ = rhs.capacity();
		elements_ = new T[capacity_];
		for (size_t i = 0; i < size_; i++)
		{
			elements_[i] = rhs[i];
		}
		return *this;
	}

	/// Operator overload to at()
	T &operator[](size_t index) const
	{
		// TODO: Your code here
		return elements_[index];
	}

	/************
	 * Accessors
	 ************/

	/// Return the number of valid elements in our data
	size_t size() const
	{
		// TODO: Your code here
		return size_;
	}

	/// Return the capacity of our internal array
	size_t capacity() const
	{
		// TODO: Your code here
		return capacity_;
	}

	/**
	 * Check whether our vector is empty
	 * Return true if we have zero elements in our array (regardless of capacity)
	 * Otherwise, return false
	 */
	bool empty() const
	{
		// TODO: Your code here
		if (size_ == 0)
		{
			return true;
		}
		return false;

		/// Return a reference to the element at an index
		T &at(size_t index) const
		{
			// TODO: Your code here
			if (index >= size_)
			{
				throw std::out_of_range("Index is out of range");
			}
			return elements_[index];
		}

		/***********
		 * Mutators
		 ***********/

		/**
		 * Reserve capacity in advance, if our capacity isn't currently large enough.
		 * Useful if we know we're about to add a large number of elements, and we'd like to avoid the overhead of many internal changes to capacity.
		 */
		void reserve(size_t capacity)
		{
			// TODO: Your code here
			capacity_ = capacity;
			T *_elements = new T[capacity_];
			if (capacity <= capacity_)
			{
				return;
			}
			for (size_t i = 0; i < size_; i++)
			{
				_elements[i] = elements_[i];
			}
			delete[] elements_;
			elements_ = _elements;
		}

		/**
		 * Set an element at an index.
		 * Throws range error if outside the size boundary.
		 * Returns a reference to the newly set element (not the original)
		 */
		T &set(size_t index, const T &element)
		{
			// TODO: Your code here
			elements_[index] = element;
			if (index >= size_)
			{
				throw std::out_of_range("Outside the size boundary");
			}
			return elements_[index];
		}

		/**
		 * Add an element onto the end of our vector, increasing the size by 1
		 * Should rely on the insert() function to avoid repeating code.
		 * Returns a reference to the newly inserted element
		 */
		T &push_back(const T &element)
		{
			// TODO: Your code here
			if (size_ == capacity_)
			{
				reserve(capacity_ * 2);
			}
			elements_[size_++] = element;
			return elements_[size_ - 1];
		}

		/**
		 * Remove the last element in our vector, decreasing the size by 1
		 * Should rely on the erase() function to avoid repeating code.
		 * Returns the new size.
		 */
		size_t pop_back()
		{
			// TODO: Your code here
			if (size_ == 0)
			{
				throw std::out_of_range("Cannot pop from an empty vector");
			}
			size_--;
			return size_;
		}

		/**
		 * Insert an element at some index in our vector, increasing the size by 1
		 *
		 * Scoot all elements at index and beyond, one to the right. This
		 * makes a "hole" available at the index, where you can then place
		 * the new element.
		 *
		 * Returns a reference to the newly added element (not the original).
		 */
		T &insert(size_t index, const T &element)
		{
			// TODO: Your code here
			size_t i = size_ - 1;
			if (index > size_)
			{
				throw std::out_of_range("Index is out of range");
			}
			if (size_ == capacity_)
			{
				reserve(size_ * 2);
			}
		}
		while (i > index) // I think this is what the professor was talking about when saying "you might want to use a while loop"
		{
			elements_[i] = elements_[i - 1];
			i--;
		}
		elements_[index] = element;
		size_++;
		return elements_[index];
	}

	/**
	 * Erase one element in our vector at the specified index, decreasing the size by 1.
	 *
	 * This means you'd then have to scoot elements to the left to fill the "hole"
	 * 	left by the erased element.
	 *
	 * Throws std::range_error if the index is out of bounds.
	 *
	 * Calls the erased element's destructor.
	 *
	 * Returns the new size.
	 */
	size_t erase(size_t index)
	{
		// TODO: Your code here
		if (index >= size_)
		{
			throw std::out_of_range("Index is out of bounds");
		}
		// destructor syntax learned from SI
		elements_[index].~T();
		for (int i = index; i < size_ - 1; i++)
		{
			data_[i] = data_[i + 1];
		}
		size_--;
		return size_;
	}

	/**
	 * Calls each element's destructor, then clears our internal
	 * data by setting size to zero and resetting the capacity.
	 */
	void clear()
	{
		// TODO: Your code here
		for (int i = 0; i < size_; i++) // call the destructor first
		{
			elements_[i].~T();
		}
		// then clear and deallocate
		size_ = 0;
		capacity_ = 0;
		operator delete(elements_); // delete the non-array elements
		elements_ = nullptr;
	}

	/**
	 * Begin private members and methods.
	 * Private methods can often contain useful helper functions,
	 * or functions to reduce repeated code.
	 */
private:
	/// Number of valid elements currently in our vector
	size_t size_ = 0;

	/// Capacity of our vector; The actual size of our internal array
	size_t capacity_ = 0;

	/**
	 * Our internal array of elements of type T.
	 * Starts off as a null pointer.
	 */
	T *elements_ = nullptr;

	/**
	 * Helper function that is called whenever we need to change the capacity of our vector
	 * Should throw std::range_error when asked to change to a capacity that cannot hold our existing elements.
	 * It's probably a good idea to make an additional helper function that decides
	 * 	whether to change capacity at all (and to what new capacity), that your public functions can rely upon.
	 */
	void changeCapacity(size_t c)
	{
		// TODO: Your code here
		capacity_ = c;
		if (c < size_)
		{
			throw std::range_error("Cannot hold our existing elements");
		}
		T *new_elements = new T[c];
		for (size_t i = 0; i < size_; i++)
		{
			new_elements[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = new_elements;
	}

	/**
	 * Copy another vector's elements into our own, by value.
	 * Does not simply copy the other vector's array's pointer
	 * Does not care about matching the capacity exactly.
	 * This is a helper function relied upon by the copy constructor and the assignment operator,
	 * 	to avoid repeated code.
	 *
	 * You will probably want to make additional helper functions to make this one easier.
	 * Here is a suggested strategy for copying the internal array:
	 * 1. Deallocate the current array for 'this' (if it is already allocated)
	 * 2. Allocate a new array for 'this' of the appropriate size
	 * 3. Use a loop to copy elements one-by-one (by value)
	 * 4. Copy other relevant properties from the 'other' to 'this'
	 */
	void copyOther(const MyVector &other)
	{

		// TODO: Your code here
		copyElements(other.elements(), other.size());
	}

	void copyElements(const T *Elements, size_t size)
	{
		// TODO: Your code here
		if (capacity_ < size)
		{
			throw std::range_error("Cannot copy more.");
		}
		T *new_elements = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			new_elements[i] = Elements[i];
		}
		delete[] elements_;
		elements_ = new_elements;
		size_ = size;
	}

	void assertBounds(size_t index, std::string message = "") const
	{
		if (index >= size_)
		{
			throw std::range_error(message);
		}
	}

	void assertCapacity(size_t c) const
	{
		// TODO: Your code here
		if (capacity_ < c)
		{
			throw std::range_error("Cannot hold our existing elements");
		}
	}
};
