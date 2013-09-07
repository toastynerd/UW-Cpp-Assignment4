//Tyler Morgan
//Word.h
//
#pragma once
#include <iostream>

namespace Binary
{
  class Byte
  {
  public:
    Byte(unsigned char value = 'a');
    operator unsigned char () const;
    Byte& operator =(Byte const& original);
    Byte& operator =(unsigned char value);
    static Byte read(std::istream& inputStream);
    void write(std::ostream& destinationStream);
  private:
    unsigned char my_value;
  };

  class Word
  {
  public:
    Word(uint16_t value = 0);
    operator uint16_t () const;
    Word& operator =(Word const& original);
    Word& operator =(uint16_t value);
    static Word readLittleEndian(std::istream& sourceStream); 
    void writeLittleEndian(std::ostream& destinationStream);
    static Word readBigEndian(std::istream& sourceStream);
    void writeBigEndian(std::ostream& destinationStream);
  private:
    static Word readNativeOrder(std::istream& sourceStream);
    static Word readNativeOrderSwapped(std::istream& sourceStream);

    void writeNativeOrder(std::ostream& destinationStream);
    void writeNativeOrderSwapped(std::ostream& destinationStream);

    uint16_t my_value; 
  };

  class DoubleWord
  {
  public:
    DoubleWord(uint32_t value = 0);
    operator uint32_t () const;
    DoubleWord& operator =(DoubleWord const& original);
    DoubleWord& operator =(uint32_t value);
    static DoubleWord readLittleEndian(std::istream& sourceStream); 
    void writeLittleEndian(std::ostream& destinationStream);
    static DoubleWord readBigEndian(std::istream& sourceStream);
    void writeBigEndian(std::ostream& destinationStream);
  private:
    static DoubleWord readNativeOrder(std::istream& sourceStream);
    static DoubleWord readNativeOrderSwapped(std::istream& sourceStream);

    void writeNativeOrder(std::ostream& destinationStream);
    void writeNativeOrderSwapped(std::ostream& destinationStream);

    uint32_t my_value;
  };

}
