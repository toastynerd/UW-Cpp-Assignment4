#include "TestHarness.h"

#include <fstream>
#include <memory>

#include "../CodecLibrary.h"
#include "../WindowsBitmapEncoder.h"
#include "../WindowsBitmapDecoder.h"
#include "../BitmapIterator.h"
// include the header file for the class you are testing.

// each test function should be small and test a single capability

// replace testName with the name of the particular test. Replace ClassName with
// the name of the class being tested
//

TEST(CodecLibrarySetup, CodecLibrary)
{
  CodecLibrary myCodecLibrary;

  myCodecLibrary.registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
  myCodecLibrary.registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));

  CHECK_EQUAL(1, myCodecLibrary.numberOfEncoders());
  CHECK_EQUAL(1, myCodecLibrary.numberOfDecoders());
}

TEST(Decoder, CodecLibrary)
{
  CodecLibrary myCodecLibrary;

  myCodecLibrary.registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
  myCodecLibrary.registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));

  std::ifstream inFile("basic.bmp", std::ios::binary);

  HBitmapDecoder myDecoder = myCodecLibrary.createDecoder("image/x-ms-bmp",inFile);
  CHECK(myDecoder);
}

TEST(Encoder, CodecLibrary)
{

}
