//Tyler Morgan
//UW CPP Quarter 3 Assignment 4
//WindowsBitmapEncoder.h

#pragma once

#include "IBitmapEncoder.h"

class WindowsBitmapEncoder: public IBitmapEncoder
{
public:
  WindowsBitmapEncoder();
  WindowsBitmapEncoder(const HBitmapIterator& inputIterator);

  virtual HBitmapEncoder clone(const HBitmapIterator& sourceIterator);
  virtual void writeToStream(std::ostream& outputStream);
  virtual std::string getMimeType();

private:
  HBitmapIterator myBitmapIterator;
};
