//Tyler Morgan
//Color.cpp

#include "Color.h"

namespace Bitmap
{
Color::Color() {}


Color& Color::operator =(Color const& original)
{
  this->blue = original.blue;
  this->green = original.green;
  this->red = original.red;
  return *this;
}

void Color::read(std::istream& inputStream)
{
  blue = Binary::Byte::read(inputStream);
  green = Binary::Byte::read(inputStream);
  red = Binary::Byte::read(inputStream);
}

void Color::write(std::ostream& destinationStream)
{
  blue.write(destinationStream);
  green.write(destinationStream);
  red.write(destinationStream);
}
}
