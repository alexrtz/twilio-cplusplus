/*
 * Twilio REST C++
 * Author: Laurent Luce
*/

#ifndef TWILIOUTILS_H
#define TWILIOUTILS_H

#include <string>
#include <vector>

namespace twilio
{
/** struct to contain the key and value for URL attributes or Body data */
struct Var
{
  std::string key;
  std::string value;
  Var(const std::string& k, const std::string& v)
  {
    key = k;
    value = v;
  }
};
typedef struct Var Var;

class Utils
{
public:
  /**
   * Constructor
   */
  Utils(const std::string& id, const std::string& token)
  {
    tid = id;
    ttoken = token;
  }
  /**
    * Check if expectedSignature matches url + params base64 encoded hash
    * @param expectedSignature signature to compare to
    * @param url URL to build hash on
    * @param params POST params
  */
  bool validateRequest(const std::string& expectedSignature, const std::string& url, std::vector<Var>& params);

private:
  /** Twilio account SID */
  std::string tid;
  /** Twilio account token */
  std::string ttoken;
};

/**
  * Replace all occurences of needle in haystack by replacement
  * @param haystack std::string to search in
  * @param needle std::string to search for
  * @param replacement std::string to replace with
*/
std::string replaceAll(const std::string& haystack, const std::string& needle, const std::string& replacement);

/**
 * Convert integer to std::string
 * @param i integer to convert
 * @return std::string
*/
std::string intToStr(int i);

/**
 * '<' operator to compare 2 Var structure based on their key std::string
 * @param a Var 1
 * @param b Var 1
 * @return < result
*/
bool operator<(const Var& a, const Var& b);

/**
 * base64 encoding of input
 * @param input std::string to encode
 * @param length of std::string
 * @return encoded std::string
*/
char* base64(const unsigned char* input, int length);

}

#endif
