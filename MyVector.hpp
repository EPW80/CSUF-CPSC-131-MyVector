#include <assert.h>

#include <iostream>

#include <string>

template <typename T>
class MyVector {
public:
static constexpr size_t DEFAULT_CAPACITY = 64;

static constexpr size_t MINIMUM_CAPACITY = 8;
  MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY) {
	size_ = 0;
	capacity_ = capacity < MINIMUM_CAPACITY? MINIMUM_CAPACITY : capacity;
	elements_ = new T[capacity_];
	}
	MyVector(const MyVector &other) : size_(other.size()), capacity_(other.capacity()), elements_(new T[capacity_]) {
		for (size_t i = 0; i < size_; i++){
			elements_[i] = other[i];
		}
	}
	~MyVector() {
		clear();
		delete[] elements_;
		elements_ = nullptr;
	}
	MyVector &operator=(const MyVector &rhs) {
		if (this != &rhs) {
			size_ = rhs.size();
			capacity_ = rhs.capacity();
			T *new_elements_ = new T[capacity_];
			for (size_t i = 0; i < size_; i++) {
				new_elements_[i] = rhs[i];
		}
		delete[] elements_;
		elements_ = new_elements_;
	}
	return *this;
}
	T &operator[](size_t index) const {
		return elements_[index];
	}
	size_t size() const {
		return size_;
	}

	size_t capacity() const {
		return capacity_;
	}

	bool empty() const {
		return size_ == 0;
	}

	T &at(size_t index) const {
		if (index >= size_) {
			throw std::out_of_range("Index is out of range");
		}
		return elements_[index];
	}
	void reserve(size_t capacity) {
		if (capacity < this->capacity_)	{
			throw std::range_error("Cannot use reserve to shrink space");
		}
		changeCapacity(capacity);
	}

	T &set(size_t index, const T &element) {
		if (index >= size_) {
			throw std::out_of_range("Index is out of range");
		}
		elements_[index].~T();
		elements_[index] = element;
		return elements_[index];
	}

	T &push_back(const T &element) {
		return insert(size_, element);
	}

	size_t pop_back() {
		return erase(size_ - 1);
	}

	T &insert(size_t index, const T &element) {
		if (index > size_) {
			throw std::out_of_range("Index is out of range");
		}
		if (size_ == capacity_) {
			reserve(capacity_ * 2);
		}
		for (size_t i = size_; i > index; --i) {
			elements_[i] = elements_[i - 1];
		}
		elements_[index] = element;
		size_++;
		return elements_[index];
	}
	size_t erase(size_t index) {
		if (index >= size_) { 
        throw std::out_of_range("Index is out of bounds");
    }
	elements_[index].~T();
    for (size_t i = index; i < size_ - 1; i++) {
        elements_[i] = elements_[i + 1];
    }
    size_--;
    if (capacity_ > MINIMUM_CAPACITY && size_ < capacity_ / 3) {
        size_t new_capacity = std::max(size_, MINIMUM_CAPACITY);
        changeCapacity(new_capacity);
    }
	return size_;
}
    void clear() { 
		for (size_t i = 0; i < size_; i++) {
			elements_[i].~T();
		}
		size_ = 0;
	}

private:
	size_t size_ = 0;

	size_t capacity_ = 0;

	T *elements_ = nullptr;
	void changeCapacity(size_t c) {
		if (c <= capacity_) {
			return;
		}
		T *new_elements = new T[c];
		for (size_t i = 0; i < size_; i++) {
			new_elements[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = new_elements;
		capacity_ = c;
	}
	void copyOther(const MyVector &other) {
		if (elements_ != nullptr) {
			delete[] elements_;
		}
		size_ = other.size();
		capacity_ = other.capacity();
		elements_ = new T[capacity_];
		for (size_t i = 0; i < size_; i++){
			elements_[i] = other[i];
		}
	}
};