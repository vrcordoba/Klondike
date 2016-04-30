
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

void PlainTextFileWriter::writeComposedField(const std::list<std::string>& fields)
{
   for (auto field : fields)
      writeField(field);
   writeFieldSeparator();
}

void PlainTextFileWriter::writeNumericField(const std::int64_t number)
{
   writeField(std::to_string(number));
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
