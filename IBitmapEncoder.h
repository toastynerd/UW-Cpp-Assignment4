//Tyler Morgan
//UW CPP Qtr 3 Assignment 4
//IBitmapEncoder.h

#pragma once

#include <memory>
#include "IBitmapIterator.h"
#include <iosfwd>
#include <string>

class IBitmapEncoder;
typedef std::shared_ptr<IBitmapEncoder> HBitmapEncoder;

class IBitmapEncoder
{
public:
  virtual ~IBitmapEncoder() {};

  virtual HBitmapEncoder clone(const HBitmapIterator& inputIterator) = 0;
  virtual void writeToStream(std::ostream& outputStream) = 0;
  virtual std::string getMimeType() = 0;
};
