FROM ubuntu:14.04
RUN apt-get update
RUN apt-get install -y build-essential valgrind
COPY gai_leak.c .
COPY Makefile .
ENTRYPOINT [ "make", "run" ]
