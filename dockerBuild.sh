#!/bin/bash

args="${@}"
if [ -z args ]; then
    args="bash"
fi

readonly dockername="cpp-builder-inst"
readonly dockerimage="cpp-builder"

function start_docker()
{
    docker volume create userhome

    docker run -ti --rm -i -d \
        --env LOCAL_USER_ID=$(id -u) \
        --workdir=$PWD \
        --name $dockername \
        -v $PWD:$PWD:Z \
        $dockerimage
        #-v userhome:/home/user:Z \

}

function exe_args()
{
    set +e
    
    echo "Running docker $dockername"

    docker exec --user $(id -u) -ti $dockername sh -c "$args"
}

function main_func()
{
    running=$(docker ps -s -f name=$dockername -q)
    if [ -z "$running" ]; then
        echo "Docker $dockername is NOT running"
        start_docker
    fi

    exe_args
}


main_func