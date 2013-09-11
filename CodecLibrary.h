//Tyler Morgan
//UW CPP Qtr 3 Assignment 4
//CodecLibrary.h

#pragma once

#include <memory>
#include "IBitmapDecoder.h"
#include "IBitmapEncoder.h"
#include <vector>

class CodecLibrary
{
public:
  void registerEncoder(const HBitmapEncoder& encoder);
  void registerDecoder(const HBitmapDecoder& decoder);

  HBitmapDecoder createDecoder(std::istream& sourceStream);
  HBitmapDecoder createDecoder(std::string const& mimeType, std::istream& sourceStream);

  HBitmapEncoder createEncoder(std::string const& mimeType, const HBitmapIterator& bitmapIterator);

  int numberOfDecoders();
  int numberOfEncoders();

private:
  std::vector<HBitmapEncoder> myEncoders;
  std::vector<HBitmapDecoder> myDecoders;
};


