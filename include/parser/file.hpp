#ifndef AEQUATIO_PARSER_FILE_HPP
#define AEQUATIO_PARSER_FILE_HPP

#include <string>
#include <vector>

namespace aequatio {
  namespace parser {
    class File {
     public:
      File();
      File(const File& copy);
      File(std::string file);

     private:
      std::vector<std::string> function_reference_;
      std::string file_path_;
    };
  }  // namespace parser
}  // namespace aequatio

#endif /* ifndef AEQUATIO_PARSER_FILE_HPP */
