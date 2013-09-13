//Tyler Morgan
//UW CPP Quarter 3 Assignment 4
//WindowsBitapEncoder.cpp

#include "WindowsBitmapEncoder.h"
#include "WindowsBitmapHeader.h"
#include "Bitmap.h"
#include <sstream>

WindowsBitmapEncoder::WindowsBitmapEncoder()
{
  
}

WindowsBitmapEncoder::WindowsBitmapEncoder(const HBitmapIterator& inputIterator)
  :myBitmapIterator(inputIterator)
{

}

HBitmapEncoder WindowsBitmapEncoder::clone(const HBitmapIterator& sourceIterator)
{
  return HBitmapEncoder(new WindowsBitmapEncoder(sourceIterator));
}

void WindowsBitmapEncoder::writeToStream(std::ostream& outputStream)
{
  WindowsBitmapHeader header;

  header.setBitmapWidth(myBitmapIterator->getBitmapWidth());
  header.setBitmapHeight(myBitmapIterator->getBitmapHeight());

  header.writeFileHeader(outputStream);
  header.writeFileHeader(std::cout);
  header.writeInfoHeader(outputStream);
  header.writeInfoHeader(std::cout);

  std::cout << std::endl;
  
  while(! myBitmapIterator->isEndOfImage())
  {
    while(! myBitmapIterator->isEndOfScanLine())
    {
      myBitmapIterator->getColor().write(outputStream);
      myBitmapIterator->nextPixel();
    }
    myBitmapIterator->nextScanLine();
  }
}

std::string WindowsBitmapEncoder::getMimeType()
{
  return "image/x-ms-bmp";
}

