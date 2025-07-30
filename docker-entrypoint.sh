#!/usr/bin/env bash

socat -T 10 TCP-LISTEN:$chall_port,reuseaddr,fork EXEC:/root/$chall_name/$chall_name_bin &
python3 -m http.server 8000
