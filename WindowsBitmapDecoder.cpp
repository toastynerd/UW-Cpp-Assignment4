//Tyler Morgan
//UW CPP Quarter 3 Assignment 4
//WindowsBitmapDecoder.cpp

#include "WindowsBitmapDecoder.h"
#include "WidowsBitmapHeader.h"
#include "Bitmap.h"
#include "BitmapIterator.h"
#include <sstream>

namespace
{
  std::stringstream nullStream;
}

WindowsBitmapDecoder::WindowsBitmapDecoder() 
  :mySourceStream(nullStream)
{
  mySourceStream.setstate(std::ios::badbit);
}

WindowsBitmapDecoder::WindowsBitmapDecoder(std::istream& sourceStream)
  :mySourceStream(sourceStream)
{
}

HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
{
  return HBitmapDecoder(new WindowsBitmapDecoder(sourceStream));
}

HBitmapIterator WindowsBitmapDecoder::createIterator()
{
  if(mySourceStream.bad())
  {
    throw std::runtime_error("Invalid Decoder!");
  }

  WindowsBitmapHeader bitmapHeader;
  bitmapHeader.readFileHeader(mySourceStream);
  bitmapHeader.readInfoHeader(mySourceStream);
  Hbitmap bitmap(new Bitmap(bitmapHeader.getBitmapWidth(),
                            bitmapHeader.getBitmapHeight(),
                            mySourceStream));
  return HBitmapIterator(new BitmapIterator(bitmap));
}

std::string WindowsBitmapDecoder::getMimeType() const
{
  return "image/x-ms-bmp";
}

bool WindowsBitmapDecoder::isSupported(const std::string& firstChunk) const
{
  if(firstChunk.size() < 2)
  {
    return false;
  }

  return firstChunk[0] == 'B' && firstChunk[1] == 'M';
}
