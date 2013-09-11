//Tyler Morgan
//UW CPP Qtr 3 Assignment 4
//CodecLibrary.cpp

#include "CodecLibrary.h"

void CodecLibrary::registerEncoder(const HBitmapEncoder& encoder)
{
  myEncoders.push_back(encoder);
}

void CodecLibrary::registerDecoder(const HBitmapDecoder& decoder)
{
  myDecoders.push_back(decoder);
}

HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream)
{
  return HBitmapDecoder();
}

HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType, std::istream& sourceStream)
{
  for(int x =0 ; x < myDecoders.size(); x++)
  {
    if (myDecoders[x]->getMimeType() == mimeType)
    {
      return myDecoders[x]->clone(sourceStream);
    }
  }
  return HBitmapDecoder();
}

HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, const HBitmapIterator& bitmapIterator)
{
  for(int x =0 ; x < myEncoders.size(); x++)
  {
    if (myEncoders[x]->getMimeType() == mimeType)
    {
      return myEncoders[x]->clone(bitmapIterator);
    }
  }
  return HBitmapEncoder();
}

int CodecLibrary::numberOfEncoders()
{
  return myEncoders.size();
}

int CodecLibrary::numberOfDecoders()
{
  return myDecoders.size();
}
