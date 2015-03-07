#pragma once

#include <algorithm>
#include <vector>


namespace utils
{
   template<typename T>
   class Matrix
   {
   public:
      Matrix(size_t w, size_t h, T const& val)
         : m_width(w)
         , m_height(h)
         , m_data(w * h, val)
      {}

      Matrix(size_t w, size_t h)
         : Matrix(w, h, T())
      {}

      Matrix(size_t w, size_t h, std::initializer_list<T> const& init)
         : Matrix(w, h)
      {
         size_t i = 0;
         for (auto d : init)
         {
            at(i % m_width, i / m_width) = d;
            ++i;
         }
      }

      ~Matrix() = default;

      size_t width()  const { return m_width; }
      size_t height() const { return m_height; }

      T&       at(size_t x, size_t y)        { return m_data[x + m_width * y]; }
      T const& at(size_t x, size_t y) const  { return m_data[x + m_width * y]; }

      friend bool operator==(Matrix const& lhs, Matrix const& rhs)
      {
         if (lhs.m_width != rhs.m_width) return false;
         if (lhs.m_height != rhs.m_height) return false;
         return std::equal(begin(lhs.m_data), end(lhs.m_data) , begin(rhs.m_data));
      }

   private:
      size_t m_width;
      size_t m_height;
      std::vector<T> m_data;
   };
}
