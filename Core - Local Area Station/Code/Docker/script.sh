#!/bin/bash

# initial check

# delete old docker if exists
docker ps -q --filter "name=astli" | grep -q . && docker stop astli
docker ps -aq --filter "name=astli" | grep -q . && docker rm astli

# build docker file
docker build . -f Dockerfile -t astli

#get cam ip

echo "searching for cam"  
while [ -z "$s" ] 
do 
s=`arp -a | grep 30:c6:f7:20:61:e8 | awk '{while ( match($0,/([0-9]+\.){3}[0-9]+/) ) { print substr($0,RSTART,RLENGTH); $0=substr($0,RSTART+RLENGTH) } }'`
done
echo "cam found"
# bring model up
docker run -p 12345:12345 --name astli astli "$s"

# stop container
docker stop astli

# dump container logs
docker logs -t astli > logs/server.stdout 2> logs/server.stderr

# remove container
#docker rm astli