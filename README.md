### getaddrinfo leak in old libc

[![Build Status](https://travis-ci.com/thz/getaddrinfo-leak.svg?branch=master)](https://travis-ci.com/thz/getaddrinfo-leak)

This is just a simple demonstration of a `getaddrinfo` memory leak found
in older libc versions (eglibc-2.19 as found in ubuntu-14.04).

A Dockerfile is provided to build on ubuntu-14.04 and run valgrind to
show the leak report.

Travis integration also shows that the same code has no issues when running
in a ubuntu-16.04 with a newer libc.
