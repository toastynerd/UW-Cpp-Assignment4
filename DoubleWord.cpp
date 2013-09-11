#include "DoubleWord.h"
#include "Byte.h"
#include <iostream>

namespace Binary
{

    DoubleWord::DoubleWord(uint32_t value)
    {
        myValue = value;
    }

    DoubleWord::operator uint32_t() const
    {
        return myValue;
    }

    DoubleWord& DoubleWord::operator=(const DoubleWord& rhs)
    {
        myValue = rhs.myValue;
        return *this;
    }

    DoubleWord& DoubleWord::operator=(uint32_t rhs)
    {
        myValue = rhs;
        return *this;
    }

    void DoubleWord::writeLittleEndian(std::ostream& destinationStream) const
    {
#ifdef Big_Endian
        writeSwappedOrder(destinationStream);
#else
        writeNativeOrder(destinationStream);
#endif
    }

    void DoubleWord::writeBigEndian(std::ostream& destinationStream) const
    {
#ifdef Big_Endian_
        writeNativeOrder(destinationStream);
#else
        writeSwappedOrder(destinationStream);
#endif
    }

    DoubleWord DoubleWord::readBigEndian(std::istream& sourceStream)
    {
#ifdef Big_Endian_
        return readNativeOrder(sourceStream);
#else
        return readSwappedOrder(sourceStream);
#endif
    }

    DoubleWord DoubleWord::readLittleEndian(std::istream& sourceStream)
    {
#ifdef Big_Endian_
        return readSwappedOrder(sourceStream);
#else
        return readNativeOrder(sourceStream);
#endif
    }

    DoubleWord DoubleWord::readNativeOrder(std::istream& sourceStream)
    {
        DoubleWord doubleWord;
        Byte* bytes = reinterpret_cast<Byte*>(&doubleWord);
        
        bytes[0] = Byte::read(sourceStream);
        bytes[1] = Byte::read(sourceStream);
        bytes[2] = Byte::read(sourceStream);
        bytes[3] = Byte::read(sourceStream);
        
        return doubleWord;
    }

    DoubleWord DoubleWord::readSwappedOrder(std::istream& sourceStream)
    {
        DoubleWord doubleWord;
        Byte* bytes = reinterpret_cast<Byte*>(&doubleWord);
        
        bytes[3] = Byte::read(sourceStream);
        bytes[2] = Byte::read(sourceStream);
        bytes[1] = Byte::read(sourceStream);
        bytes[0] = Byte::read(sourceStream);
        
        return doubleWord;
    }

    void DoubleWord::writeNativeOrder(std::ostream& destinationStream) const
    {
        const Byte* bytes = reinterpret_cast<const Byte*>(&myValue);
        
        bytes[0].write(destinationStream);
        bytes[1].write(destinationStream);
        bytes[2].write(destinationStream);
        bytes[3].write(destinationStream);
    }

    void DoubleWord::writeSwappedOrder(std::ostream& destinationStream) const
    {
        const Byte* bytes = reinterpret_cast<const Byte*>(&myValue);

        bytes[3].write(destinationStream);
        bytes[2].write(destinationStream);
        bytes[1].write(destinationStream);
        bytes[0].write(destinationStream);
    }
}
