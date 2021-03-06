/*
 * Twilio REST C++
 * Author: Laurent Luce
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Utils.h"
#include "Rest.h"
#include "TwiML.h"

using namespace twilio;

int main ()
{

  // Twilio REST API version
  const string API_VERSION = "2010-04-01";

  // Twilio AccountSid and AuthToken
  const string ACCOUNT_SID = "SID";
  const string ACCOUNT_TOKEN = "TOKEN";

  // Outgoing Caller ID previously validated with Twilio
  const string CALLER_ID = "NNNNNNNNNN";

  string response;

  vector<Var> vars;

  try
  {

    // Twilio REST
    Rest t (ACCOUNT_SID, ACCOUNT_TOKEN);

    // get completed calls XML
    vars.push_back(Var("Status", "Completed"));
    response = t.request("/" + API_VERSION + "/Accounts/" + ACCOUNT_SID + "/Calls", "GET", vars);
    cout << response << endl;

    // make a call
    vars.clear();
    vars.push_back(Var("To", "xxx-xxx-xxxx"));
    vars.push_back(Var("From", "xxx-xxx-xxxx"));
    vars.push_back(Var("Url", "http://xxxx"));
    response = t.request("/" + API_VERSION + "/Accounts/" + ACCOUNT_SID + "/Calls", "POST", vars);
    cout << response << endl;

    // send SMS
    vars.clear();
    vars.push_back(Var("To", "xxx-xxx-xxxx"));
    vars.push_back(Var("From", "xxx-xxx-xxxx"));
    vars.push_back(Var("Body", "Hello, how are you?"));
    response = t.request("/" + API_VERSION + "/Accounts/" + ACCOUNT_SID + "/SMS/Messages", "POST", vars);
    cout << response << endl;

    // TwiML reponse

    // Say, Dial and Play
    TwiMLResponse response;
    Say say ("Hello, how are you?");
    say.setLoop(5);
    say.setVoice("woman");
    response.append(say);
    cout << response.toXML() << endl;

    // Gather, redirect
    TwiMLResponse response2;
    Gather gather;
    gather.setNumDigits(10);
    Say say2 ("Press 1");
    Redirect redirect;
    gather.append(say2);
    response2.append(gather);
    response2.append(redirect);
    cout << response2.toXML() << endl;

    // Twilio Utils
    Utils u (ACCOUNT_SID, ACCOUNT_TOKEN);

    // validate request signature
    vars.clear();
    vars.push_back(Var("Status", "Completed"));
    bool v = u.validateRequest("x1P+eKchQZzgVQO3Yad/PgKSM1k=", "/" + API_VERSION + "/Accounts/" + ACCOUNT_SID + "/Calls", vars);
    cout << "request valid:" << v << endl;
  }
  catch (char const* str)
  {
    cout << "Exception raised: " << str << endl;
  }

  return 0;
}
