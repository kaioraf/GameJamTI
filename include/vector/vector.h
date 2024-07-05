#pragma once
template <typename T> class Vector{
    public:
        Vector(const int newSize) // throws std::out_of_range("Vector")
        {
            data = new T[newSize];
            capacity = newSize;
            actualSize = newSize;
        }
        ~Vector()
        {
            delete [] data;
        }
        int size() const { return actualSize; }

        void resize(const int newSize) // throws std::out_of_range("Vector")
        {
            if (newSize > capacity)
            {
                T* oldData = data;
                data = new T[newSize];
                for (int i = 0; i < capacity; i++)
                {
                    data[i] = oldData[i];
                }
                
                capacity = newSize;
                actualSize = newSize;
                delete [] oldData;

            }
            else
            {
                actualSize = newSize;
            }
        }
        void pushBack(T& value)
        {
            unsigned int oldSize = this->size();
            this->resize(oldSize + 1);
            this->at(oldSize) = value;
        }
        void popBack()
        {
            unsigned int oldSize = this->size();
            this->resize(oldSize - 1);
        }
        T& at(const int index) // throws std::out_of_range("Vector")
        {
            return data[index];
        }
    private:
        T* data;
        int actualSize;
        int capacity;
};


