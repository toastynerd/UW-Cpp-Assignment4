//Tyler Morgan
//Color.h

#pragma once
#include "Binary.h"

namespace Bitmap
{
  class Color
  {
  public:
    Color();
    Color& operator =(Color const& original);
    void read(std::istream& inputStream);
    void write(std::ostream& destinationStream);

  private:
    Binary::Byte blue;
    Binary::Byte green;
    Binary::Byte red;
  };

  class ScanLine
  {

  };
}
