//Tyler Morgan
//Word.cpp

#include "Binary.h"

namespace Binary
{
  //definitions for Byte
  Byte::Byte(unsigned char value)
   :my_value(value) {}
  Byte::operator unsigned char() const
  {
    return my_value;
  }

  Byte& Byte::operator =(Byte const& original)
  {
    this->my_value = original.my_value;
    return *this;
  }

  Byte& Byte::operator =(unsigned char value)
  {
    this->my_value = value;
    return *this;
  }

  Byte Byte::read(std::istream& inputStream)
  {
    return inputStream.get();
  }


  void Byte::write(std::ostream& destinationStream)
  {
    destinationStream.put(my_value);
  }


  //definitions for Word
  Word::Word(uint16_t value)
    :my_value(value) {}
  Word::operator uint16_t () const
  {
    return my_value;
  }

  Word& Word::operator =(Word const& original)
  {
    this->my_value = original.my_value;
    return *this;
  }

  Word& Word::operator =(uint16_t value)
  {
    this->my_value = value;
    return *this;
  }

  Word Word::readLittleEndian(std::istream& sourceStream)
  {
#ifdef LITTLE_ENDIAN
    return readNativeOrder(sourceStream);
#else
    return readNativeOrderSwapped(sourceStream);
#endif 
  }

  void Word::writeLittleEndian(std::ostream& destinationStream) 
  {
#ifdef LITTLE_ENDIAN
    return writeNativeOrder(destinationStream);
#else
    return writeNativeOrderSwapped(destinationStream);
#endif

  } 

  Word Word::readBigEndian(std::istream& sourceStream)
  {
#ifdef LITTLE_ENDIAN 
    return readNativeOrderSwapped(sourceStream);
#else
    return readNativeOrder(sourceStream);
#endif

  }

  void Word::writeBigEndian(std::ostream& destinationStream)
  {

#ifdef LITTLE_ENDIAN
    return writeNativeOrderSwapped(destinationStream);
#else
    return writeNativeOrder(destinationStream);
#endif
  }

  //private functions
  Word Word::readNativeOrder(std::istream& sourceStream) 
  {
    Word word;
    Byte* bytes = reinterpret_cast<Byte*>(&word);
    bytes[0] = Byte::read(sourceStream);
    bytes[1] = Byte::read(sourceStream);
    return word;
  }

  Word Word::readNativeOrderSwapped(std::istream& sourceStream)
  {
    Word word;
    Byte* bytes = reinterpret_cast<Byte*>(&word);
    bytes[1] = Byte::read(sourceStream);
    bytes[0] = Byte::read(sourceStream);
    return word;
  }

  void Word::writeNativeOrder(std::ostream& destinationStream)
  {
    Byte* bytes = reinterpret_cast<Byte*>(&my_value);
    bytes[0].write(destinationStream);
    bytes[1].write(destinationStream);
  }

  void Word::writeNativeOrderSwapped(std::ostream& destinationStream)
  {
    Byte* bytes = reinterpret_cast<Byte*>(&my_value);
    bytes[1].write(destinationStream);
    bytes[0].write(destinationStream);
  }


  //definitnions for DoubleWord
  DoubleWord::DoubleWord(uint32_t value)
    :my_value(value) {}
  DoubleWord::operator uint32_t () const
  {
    return my_value;
  }

  DoubleWord& DoubleWord::operator = (DoubleWord const& original)
  {
    this->my_value = original.my_value;
    return *this;
  }

  DoubleWord& DoubleWord::operator =(uint32_t value)
  {
    this->my_value = value;
    return *this;
  }

  DoubleWord DoubleWord::readLittleEndian(std::istream& sourceStream)
  {
#ifdef LITTLE_ENDIAN
    return readNativeOrder(sourceStream);
#else
    return readNativeOrderSwapped(sourceStream);
#endif
  }

  void DoubleWord::writeLittleEndian(std::ostream& destinationStream)
  {
#ifdef LITTLE_ENDIAN
    return writeNativeOrder(destinationStream);
#else
    return writeNativeOrderSwapped(destinationStream);
#endif
  }

  DoubleWord DoubleWord::readBigEndian(std::istream& sourceStream)
  {
#ifdef LITTLE_ENDIAN
    return readNativeOrderSwapped(sourceStream);
#else
    return readNativeOrder(sourceStream);
#endif
  }

  void DoubleWord::writeBigEndian(std::ostream& destinationStream)
  {
#ifdef LITTLE_ENDIAN
    return writeNativeOrderSwapped(destinationStream);
#else
    return writeNativeOrder(destinationStream);
#endif
  }

  //private methods

  DoubleWord DoubleWord::readNativeOrder(std::istream& sourceStream)
  {
    DoubleWord dword;
    Byte* bytes = reinterpret_cast<Byte*>(&dword);
    bytes[0] = Byte::read(sourceStream);
    bytes[1] = Byte::read(sourceStream);
    bytes[2] = Byte::read(sourceStream);
    bytes[3] = Byte::read(sourceStream);

    return dword;
  }

  DoubleWord DoubleWord::readNativeOrderSwapped(std::istream& sourceStream)
  {
    DoubleWord dword;
    Byte* bytes = reinterpret_cast<Byte*>(&dword);
    bytes[3] = Byte::read(sourceStream);
    bytes[2] = Byte::read(sourceStream);
    bytes[1] = Byte::read(sourceStream);
    bytes[0] = Byte::read(sourceStream);

    return dword;
  }

  void DoubleWord::writeNativeOrder(std::ostream& destinationStream)
  {
    Byte* bytes = reinterpret_cast<Byte*>(&my_value);
    bytes[0].write(destinationStream);
    bytes[1].write(destinationStream);
    bytes[2].write(destinationStream);
    bytes[3].write(destinationStream);
  }

  void DoubleWord::writeNativeOrderSwapped(std::ostream& destinationStream)
  {
    Byte* bytes = reinterpret_cast<Byte*>(&my_value);
    bytes[3].write(destinationStream);
    bytes[2].write(destinationStream);
    bytes[1].write(destinationStream);
    bytes[0].write(destinationStream);

  }
   

}

