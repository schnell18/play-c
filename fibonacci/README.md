# Introduction

Some notes on fibonacci implementation in C.

## Create static binary using musl libc

Static binary makes distribution of software easier. And it is the
default way in golang. The [musl libc][1] is a popular streamlined libc
implementation. To install musl libc on ubuntu, type the following
commands:

    sudo apt-get install -y musl musl-dev musl-tools

Then you substitute `gcc` with `musl-gcc` by change the CC macro in you
Makefile. To build static executable, add the `-static` option to
`LDFLAGS` as well.

You can verify whether a given executable is statically linked by using
either `ldd` or `file` command. For instance, you have an executable
named `fib`, you may check if it is statically linked by:


    $ file fib
    fib: ELF 64-bit LSB executable, x86-64, version 1 (GNU/Linux), statically linked, for GNU/Linux 3.2.0, BuildID[sha1]=0594a4e92c49eba9ac85557bfa5bc409f0ef7469, stripped

or using `ldd` command:

    $ ldd fib
    不是动态可执行文件

[1]: https://www.musl-libc.org/
