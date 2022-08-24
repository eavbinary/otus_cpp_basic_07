#include <stdexcept>

template <typename T>
struct Node
{
  Node();
  Node<T> *prev;
  Node<T> *next;
  T value;
};

template <typename T>
Node<T>::Node()
{
  prev = nullptr;
  next = nullptr;
}

template <typename T>
class LineContainer
{
public:
  LineContainer()
  {
    p_Begin = nullptr;
    p_End = nullptr;
    p_Size = 0;
  };

  ~LineContainer(){};

  void push_back(const T &value)
  {
    Node<T> *node = new Node<T>;
    node->value = value;
    if (p_Size > 0)
    {
      p_End->next = node;
      node->prev = p_End;
      p_End = node;
    }
    else
    {
      p_Begin = p_End = node;
    }
    p_Size++;
  }

  void show()
  {
    if (nullptr == p_Begin)
    {
      std::cout << "ERROR: empty container" << std::endl;
    }
    else
    {
      Node<T> *tmp = p_Begin;
      std::cout << ">>";
      while (nullptr != tmp)
      {
        std::cout << " " << tmp->value;
        tmp = tmp->next;
      }
      std::cout << std::endl;
    }
  }

  size_t size() const
  {
    return p_Size;
  }

  void erase(std::size_t pos)
  {
    if (pos < 0)
    {
      std::cout << "ERROR: invalid position for delete" << std::endl;
      return;
    }
    if (p_Begin == nullptr)
    {
      std::cout << "ERROR: empty container" << std::endl;
      return;
    }
    if (pos == 0)
    {
      p_Begin = p_Begin->next;
      if (nullptr != p_Begin)
      {
        p_Begin->prev = nullptr;
      }
      else
      {
        p_End = nullptr;
      }
    }
    else
    {
      Node<T> *tmp = p_Begin;
      int i = 0;
      while (tmp != nullptr && pos - 1 > i)
      {
        tmp = tmp->next;
        i++;
      }
      if (tmp == nullptr)
      {
        std::cout << "ERROR: deleted item not found" << std::endl;
      }
      else
      {
        tmp->prev->next = tmp->next;
        if (tmp->next != nullptr)
        {
          tmp->next->prev = tmp->prev;
        }
        else
        {
          p_End = tmp->prev;
        }
      }
      delete tmp;
    }
    p_Size--;
  }

  void insert(std::size_t pos, const T &value)
  {
    Node<T> *node = new Node<T>;
    node->value = value;
    node->next = nullptr;
    node->prev = nullptr;
    if (pos < 0)
    {
      std::cout << "ERROR: invalid position for insert" << std::endl;
    }
    else if (0 == pos)
    {
      node->next = p_Begin;
      p_Begin->prev = node;
      p_Begin = node;
      p_Size++;
    }
    else
    {
      Node<T> *tmp = p_Begin;
      for (int i = 0; i < pos - 1; i++)
      {
        if (tmp != nullptr)
        {
          tmp = tmp->next;
        }
      }
      if (tmp != nullptr)
      {
        node->next = tmp->next;
        node->prev = tmp;
        tmp->next = node;
        if (node->next != nullptr)
        {
          node->next->prev = node;
        }
        p_Size++;
      }
      else
      {
        std::cout << "ERROR: null node" << std::endl;
      }
    }
  }

  T operator[](std::size_t pos)
  {
    //std::cout << pos << std::endl;
    if (p_Begin == nullptr)
    {
      throw std::runtime_error("ERROR: empty container");
    }
    Node<T> *tmp = p_Begin;
    int i = 0;
    while (tmp != nullptr && pos + 1 > i)
    {
      if (i == pos)
      {
        break;
      }
      tmp = tmp->next;
      i++;
    }

    if (tmp == nullptr)
    {
      throw std::runtime_error("ERROR: index outside the bounds of the array");
    }
    else
    {
      return (tmp->value);
    }
  }

private:
  Node<T> *p_Begin;
  Node<T> *p_End;
  size_t p_Size;
};
