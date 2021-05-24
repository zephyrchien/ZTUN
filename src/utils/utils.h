#ifndef UTILS_H_
#define UTILS_H_

#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm> 
#include <functional> 
#include <locale>
#include <cctype>
#include <cstdint>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <memory.h>
#include <fcntl.h>
#include <unistd.h>
#include "config.h"

using std::string;
using std::stringstream;
using std::vector;
using std::pair;
using std::unordered_set;
using std::shared_ptr;
using std::unique_ptr;

enum LOG_LEVEL { NONE, WARN, INFO, DEBUG };
enum LOG_BUF_LINE { LNONE, LWARN = 2, LINFO = 5, LDEBUG = 10};
const static int SALEN = sizeof(sockaddr_in);
class Event;
class Buffer;
class ZBuffer;
class RingBuffer;
class Config;
class Log;
class Endpoint;
class Listener;
class ReadWriter;
typedef shared_ptr<Event> SharedEvent;
typedef shared_ptr<Buffer> SharedBuffer;
typedef unique_ptr<Buffer> OwnedBuffer;
typedef unique_ptr<RingBuffer> OwnedRingBuffer;
typedef shared_ptr<sockaddr_in> SharedSA;
typedef unique_ptr<sockaddr_in> OwnedSA;
typedef vector<Config> Configs;
typedef vector<Listener> Listeners;
typedef unordered_set<uintptr_t> PtrSet;
typedef unique_ptr<Log> OwnedLogger;

string& trim_space_left(string&);
string& trim_space_right(string&);
string& trim_space(string&);
string trim_space_copy(string);

int split_addr_port(const string&, pair<string, int>&);
int split_key_value(const string&, pair<string, string>&);

int set_reuseaddr(const int);
int set_nonblocking(const int);
int get_error(const int);
int dup_with_opt(const int);

sockaddr_in* to_sockaddr(const int);
sockaddr_in* to_sockaddr(const char*, const int);
sockaddr_in* to_sockaddr(const string&, const int);
const string to_string(const sockaddr_in*);
LOG_LEVEL to_level(const string&);

#endif
