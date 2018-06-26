**Get/set socket options**

```C
#include <sys/socket.h>
int getsockopt(int sd, int level, int opt, void *var, socklen_t *len);
int setsockopt(int sd, int level, int opt, const void *var, socklen_t *len);
```


**getaddrinfo/getnameinfo**

```C
#include <sys/socket.h>
#include <netdb.h>

struct addrinfo {
  int ai_flags;
  int ai_family;
  int ai_socktype;
  int ai_protocol;
  char *ai_canonname;
  struct sockaddr *ai_addr;
  socklen_t ai_addrlen;
  struct addrinfo *ai_next;
};
int getaddrinfo(const char *domainname, const char *service, 
		const struct addrinfo *hint, struct addrinfo **vr);
	// returns: 0 if OK, error number able to be passed to gai_strerror() otherwise.

void freeaddrinfo(struct addrinfo *ai_llist);
const char *gai_strerror(int err_nbr);
int getnameinfo(const struct sockaddr *sa, socklen_t salen,
		char *domainname, socklen_t dnlen,
		char *service, socklen_t svlen, 
		int flags);
	// returns: 0 if OK, error number able to be passed to gai_strerror() otherwise.
```

**sendmsg/recvmsg**

```C
#include <sys/uio.h>

struct iovec {
  void *iov_base;
  size_t iov_len;
};
```

```C
#include <sys/socket.h>

struct cmsghdr {
  int cmsg_level;
  int cmsg_type;
};

struct cmsghdr *CMSG_FIRSTHDR(struct msghdr *msg);
struct cmsghdr *CMSG_NXTHDR(struct msghdr *msg, struct cmsghdr *cur_cmsg);
unsigned char *CMSG_DATA(struct cmsghdr *cmsg);

struct msghdr {
  int msg_flags;
  char *msg_name;
  socklen_t msg_namelen;
  struct iovec *msg_iov;
  int msg_iovlen;
  void *msg_control;
  socklen_t msg_controllen;
};

ssize_t recvmsg(int sd, struct msghdr *msg, int flags);
ssize_t sendmsg(int sd, struct msghdr *msg, int flags);
```
