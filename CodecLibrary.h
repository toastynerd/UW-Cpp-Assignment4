//Tyler Morgan
//UW CPP Qtr 3 Assignment 4
//CodecLibrary.h

#include "IBitmapDecoder.h"
#include "IBitmapEncoder.h"
#include <vector>

class CodecLibrary
{
public:
  void registerEncoder(HBitmapEncoder& encoder);
  void registerDecoder(HBitmapDecoder& decoder);
private:
  vector<HBitmapEncoder> my_encoders;
  vecotr<HBitmapDecoder> my_decoders;
};


