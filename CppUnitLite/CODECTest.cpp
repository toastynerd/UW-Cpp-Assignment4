#include "TestHarness.h"

#include <fstream>
#include <memory>

#include "../CodecLibrary.h"
#include "../WindowsBitmapEncoder.h"
#include "../WindowsBitmapDecoder.h"
#include "../BitmapIterator.h"
#include "../GrayscaleDecorator.h"
#include "../ReverseColorDecorator.h"
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
  std::shared_ptr<CodecLibrary> myCodecLibrary;
  myCodecLibrary.reset(new CodecLibrary);

  myCodecLibrary->registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
  myCodecLibrary->registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));

  std::ifstream inFile("basic.bmp", std::ios::binary);

  HBitmapDecoder myDecoder = myCodecLibrary->createDecoder("image/x-ms-bmp",inFile);
  CHECK(myDecoder);
}

TEST(CreateIterator, CodecLibrary)
{
  std::shared_ptr<CodecLibrary> myCodecLibrary;
  myCodecLibrary.reset(new CodecLibrary);

  myCodecLibrary->registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
  myCodecLibrary->registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));

  std::ifstream inFile("basic.bmp", std::ios::binary);

  HBitmapDecoder myDecoder = myCodecLibrary->createDecoder("image/x-ms-bmp", inFile);

  HBitmapIterator myIterator = myDecoder->createIterator();

  CHECK(myIterator);
}

TEST(Encoder, CodecLibrary)
{
  std::shared_ptr<CodecLibrary> myCodecLibrary;
  myCodecLibrary.reset(new CodecLibrary);

  myCodecLibrary->registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
  myCodecLibrary->registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));

  std::ifstream inFile("basic.bmp", std::ios::binary);

  HBitmapDecoder myDecoder = myCodecLibrary->createDecoder("image/x-ms-bmp",inFile);

  HBitmapIterator myIterator = myDecoder->createIterator();

  HBitmapEncoder myEncoder = myCodecLibrary->createEncoder("image/x-ms-bmp", myIterator);

  CHECK(myEncoder);

  std::ofstream outFile("reencoded.bmp", std::ios::binary);

  myEncoder->writeToStream(outFile);

  CHECK(outFile);
}

TEST(UsingDecoratorIterators,GrayscaleDecorator)
{
  std::shared_ptr<CodecLibrary> myCodecLibrary;
  myCodecLibrary.reset(new CodecLibrary);

  myCodecLibrary->registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
  myCodecLibrary->registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));

  std::ifstream inFile("basic.bmp", std::ios::binary);

  HBitmapDecoder myDecoder = myCodecLibrary->createDecoder("image/x-ms-bmp",inFile);

  HBitmapIterator myIterator = myDecoder->createIterator();
  HBitmapIterator myDecorator(new GrayscaleDecorator(myIterator));

  HBitmapEncoder myEncoder = myCodecLibrary->createEncoder("image/x-ms-bmp", myDecorator);

  CHECK(myEncoder);

  std::ofstream outFile("Grayscale.bmp", std::ios::binary);

  myEncoder->writeToStream(outFile);

  CHECK(outFile);
}


TEST(UsingDecoratorIterators,ReverseColorIterator)
{
  std::shared_ptr<CodecLibrary> myCodecLibrary;
  myCodecLibrary.reset(new CodecLibrary);

  myCodecLibrary->registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
  myCodecLibrary->registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));

  std::ifstream inFile("basic.bmp", std::ios::binary);

  HBitmapDecoder myDecoder = myCodecLibrary->createDecoder("image/x-ms-bmp",inFile);

  HBitmapIterator myIterator = myDecoder->createIterator();
  HBitmapIterator myDecorator(new ReverseColorDecorator(myIterator));

  HBitmapEncoder myEncoder = myCodecLibrary->createEncoder("image/x-ms-bmp", myDecorator);

  CHECK(myEncoder);

  std::ofstream outFile("Inverse.bmp", std::ios::binary);

  myEncoder->writeToStream(outFile);

  CHECK(outFile);
}



