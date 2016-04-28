
#include "PlainTextFileWriter.hpp"

namespace Utils
{

PlainTextFileWriter::PlainTextFileWriter() : fileM()
{
}

PlainTextFileWriter::~PlainTextFileWriter()
{
   if (isOk())
      fileM.close();
}

PermanentMediumWriter* PlainTextFileWriter::clone()
{
   return new PlainTextFileWriter();
}

void PlainTextFileWriter::open(const std::string& name)
{
   fileM.open(name + ".txt");
}

void PlainTextFileWriter::writeFieldSeparator()
{
   writeField(PermanentMedium::FIELD_SEPARATOR);
}

void PlainTextFileWriter::writeField(const std::string& line)
{
   fileM << line << std::endl;
}

bool PlainTextFileWriter::isOk() const
{
   return fileM.is_open();
}

}
