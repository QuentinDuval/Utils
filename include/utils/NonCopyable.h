#pragma once


namespace utils
{
   struct NonCopyable
   {
      NonCopyable() = default;
      ~NonCopyable() = default;

      NonCopyable(NonCopyable const&) = delete;
      NonCopyable& operator=(NonCopyable const&) = delete;
   };
}
