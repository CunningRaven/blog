POLL event | PIPE | TCP socket
-----------|------------|--------
POLLPRI | (none) | out-of-band data
POLLERR | reported for write end of a pipe when<br>the read end has been closed | socket errors(?)
POLLHUP | reported for read end of a pipe when<br>the write end has been closed | (seems none)
POLLIN  | normal data available | normal data available <br> peer close its socket <br> peer shutdown write half of its socket
