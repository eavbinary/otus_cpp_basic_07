template <class T>
class SerialContainer
{
public:
  SerialContainer()
  {
    p_capacity = 0;
    p_size = 0;
    p_data = nullptr;
  };

  ~SerialContainer()
  {
    delete[] p_data;
  };

  T &operator[](size_t index) const
  {
    return p_data[index];
  };

  size_t size() const
  {
    return p_size;
  }

  void push_back(const T &value)
  {
    check_capacity();
    p_data[p_size++] = value;
  };

  void SerialContainer<T>::erase(size_t pos)
  {
    for (size_t i = pos; i < p_size; i++)
    {
      p_data[i - 1] = p_data[i];
    }
    resize_data(p_size - 1);
  }

  void SerialContainer<T>::insert(std::size_t pos, const T &value)
  {
    check_capacity();
    for (size_t i = 0; i <= p_size - pos; i++)
    {
      p_data[p_size - i + 1] = p_data[p_size - i];
    }
    p_data[pos] = value;
    p_size++;
  }

  void show()
  {
    std::cout << ">> ";
    for (int i = 0; i < p_size; i++)
    {
      std::cout << p_data[i] << " ";
    }
    std::cout << std::endl;
  }

private:
  size_t p_size;
  size_t p_capacity;
  T *p_data;

  void reserve_data(size_t size)
  {
    T *tmp = new T[size];
    std::copy(p_data, p_data + p_size, tmp);
    p_capacity = size;
    delete[] p_data;
    p_data = tmp;
  }

  void check_capacity()
  {
    if (p_size >= p_capacity)
    {
      if (p_capacity == 0)
        reserve_data(p_capacity + 1);
      else
        reserve_data(p_capacity * 2);
    }
  }

  void resize_data(size_t size)
  {
    p_size = size;
  }
};
