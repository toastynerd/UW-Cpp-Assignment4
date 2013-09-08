//Tyler Morgan
//UW CPP Qtr 3 Assignment 4
//IBitmapEncoder.h

#pragma once

#include "IBitmapIterator.h"
#include <iosfwd>
#include <string>

class IBitmapEncoder;
typedef std::shared_ptr<IBitmapEncoder> HBitmapEndcoder;

class IBitmapEncoder
{
public:
  virtual ~IBitmapEncoder {};
};
