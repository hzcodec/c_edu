#!/bin/bash

echo "------ UDP client3/server3 started ------"
echo "------ Enter data                  ------"


./udp_server3 &
./udp_client3 127.0.0.1 $1 &
