//Tyler Morgan
//UW CPP Quarter 3 Assignment 4
//WindowsBitmapDecoder.h

#pragma once

#include "IBitmapDecoder.h"

class WindowsBitmapDecoder : public IBitmapDecoder
{
public:
  WindowsBitmapDecoder();
  WindowsBitmapDecoder(std::istream& sourceStream);

  virtual HBitmapDecoder clone(std::istream& sourceStream);
  virtual HBitmapIterator createIterator();
  virtual std::string getMimeType() const;
  virtual bool isSupporter(const std::string& firstChunk) const;

private: 
  std::istream& mySourceStream;
};

