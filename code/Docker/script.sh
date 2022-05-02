#!/bin/bash

# initial check

# delete old docker if exists
docker ps -q --filter "name=astli" | grep -q . && docker stop astli
docker ps -aq --filter "name=astli" | grep -q . && docker rm astli

# build docker file
docker build . -f Dockerfile -t astli

# bring model up
docker run -d -p 12345:12345 --name astli astli

# perform evaluation
/usr/bin/env python main.py

# stop container
docker stop astli

# dump container logs
docker logs -t astli > logs/server.stdout 2> logs/server.stderr

# remove container
docker rm astli