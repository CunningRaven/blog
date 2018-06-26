POLL event | PIPE | TCP socket
-----------|------------|--------
POLLPRI | (none) | out-of-band data
POLLERR | reported for write end of a pipe when the read end has been closed | socket errors(?)
POLLHUP | reported for read end of a pipe when the write end has been closed | (seems none)
POLLIN  | normal data available | normal data available
 | | peer close its socket
 | | peer shutdown write half of its socket
