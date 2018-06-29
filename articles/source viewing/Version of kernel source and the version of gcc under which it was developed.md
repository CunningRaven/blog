On the top directory of source tree of Linux kernel, v2.6.30.4:
'''shell
$ uname -a
Linux kili-pc 4.14.48-1-MANJARO #1 SMP PREEMPT Tue Jun 5 18:53:59 UTC 2018 x86_64 GNU/Linux
$ gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-pc-linux-gnu/8.1.0/lto-wrapper
Target: x86_64-pc-linux-gnu
Configured with: /build/gcc/src/gcc/configure --prefix=/usr --libdir=/usr/lib --libexecdir=/usr/lib --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=https://bugs.archlinux.org/ --enable-languages=c,c++,ada,fortran,go,lto,objc,obj-c++ --enable-shared --enable-threads=posix --enable-libmpx --with-system-zlib --with-isl --enable-__cxa_atexit --disable-libunwind-exceptions --enable-clocale=gnu --disable-libstdcxx-pch --disable-libssp --enable-gnu-unique-object --enable-linker-build-id --enable-lto --enable-plugin --enable-install-libiberty --with-linker-hash-style=gnu --enable-gnu-indirect-function --enable-multilib --disable-werror --enable-checking=release --enable-default-pie --enable-default-ssp
Thread model: posix
gcc version 8.1.0 (GCC)
$ make menuconfig # use default config
$ make # The building-up fails with an up-to-date compiler to work on an old kernel version.
'''
Under the same environment and with same commands, I try to build up kernel v4.17.3. It succeeds.