/*
 * Twilio REST C++
 * Author: Laurent Luce
*/

#ifndef TWILIOREST_H
#define TWILIOREST_H

#include <string>
#include <vector>

namespace twilio
{

class Rest
{
public:
  /**
   * Constructor
   * @param id Twilio account SID
   * @param token Twilio account token
   */
  Rest(const std::string& id, const std::string& token)
  {
    tid = id;
    ttoken = token;
  }

  /**
   * HTTP request
   * @param path URL path
   * @param method HTTP method: "GET", "POST", "PUT", "DELETE"
   * @param vars URL attributes or POST attributes
   * @return HTTP response
   */
  std::string request(const std::string& path, const std::string& method, const std::vector<Var>& vars);

private:
  /** Twilio account SID */
  std::string tid;
  /** Twilio account token */
  std::string ttoken;
  /** Response buffer */
  std::string tbuffer;
  /** Twilio API URL - set in cpp */
  static const std::string TWILIO_API_URL;

  /**
   * Prefix path with Twilio URL
   * @param path URL path
   * @return full URL
   */
  std::string build_uri(const std::string& path) const;
  /**
   * HTTP GET request
   * @param url HTTP request URL
   * @param vars URL attributes
   * @return HTTP response
   */
  std::string get(const std::string& url, const std::vector<Var>& vars);
  /**
   * HTTP POST request
   * @param url HTTP request URL
   * @param vars POST attributes
   * @return HTTP response
   */
  std::string post(const std::string& url, const std::vector<Var>& vars);
  /**
   * HTTP PUT request
   * @param url HTTP request URL
   * @param filename File to read data from
   * @return HTTP response
  */
  std::string put(const std::string& url, const std::string& filename);
  /**
   * HTTP DELETE request
   * @param url HTTP request URL
   * @return HTTP response
  */
  std::string tdelete(const std::string& url);

};

}

#endif
