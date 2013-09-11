//Tyler Morgan
//UW CPP Quarter 3 assignment 4
//IBitmapDecoder.h

#pragma once

#include <memory>
#include "IBitmapIterator.h"
#include <iosfwd>
#include <string>

class IBitmapDecoder;
typedef std::shared_ptr<IBitmapDecoder> HBitmapDecoder;

class IBitmapDecoder
{
public:
  virtual ~IBitmapDecoder() {}

  virtual HBitmapDecoder clone (std::istream& HsourceStream) = 0;
  virtual HBitmapIterator createIterator() = 0;
  virtual std::string getMimeType() const = 0;
  virtual bool isSupported(const std::string& firstChunk) const = 0;
};

